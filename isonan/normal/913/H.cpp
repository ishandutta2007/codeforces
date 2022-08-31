#include <cstdio>
#include <vector>
#include <algorithm>

const int P=998244353;
inline int mul(const int &a,const int &b){return 1ll*a*b%P;}
inline int add(int a,const int &b){a+=b;return(a>=P)?a-P:a;}
inline int sub(int a,const int &b){a-=b;return (a<0)?a+P:a;}
int qsm(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=mul(ans,a);
		a=mul(a,a);
		b>>=1;
	}
	return ans;
}
typedef std::vector<int> poly;
int C[41][41],inv[41];
int gcd(int a,int b){return (!b)?a:gcd(b,a%b);}
struct fract{
	int a,b;
	fract operator+(int n){return (fract){a+b*n,b};}
	bool operator>=(const fract &rhs)const{return 1ll*a*rhs.b>=1ll*b*rhs.a;}
	bool operator==(const fract &rhs)const{return 1ll*a*rhs.b==1ll*b*rhs.a;}
	bool operator<(const fract &rhs)const{return 1ll*a*rhs.b<1ll*b*rhs.a;}
}x[31];
struct interval{
	fract l;
	poly f;
};
std::vector<interval>vec,vec2;
std::vector<fract>cut;
poly h[100001],tem[100001];
int n;
fract read(){
	fract x;
	int y=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch!='.'&&ch!='\n')y=y*10+ch-'0',ch=getchar();
	if(ch=='\n')return (fract){y,1};
	x.a=0,x.b=1;
	ch=getchar();
	while(ch>='0'&&ch<='9')x.a=x.a*10+ch-'0',x.b*=10,ch=getchar();
	int _gcd=gcd(x.a,x.b);
	x.a/=_gcd,x.b/=_gcd;
	x=x+y;
	return x;
}
poly operator+=(poly &a,poly b){
	if((int)a.size()<(int)b.size())a.resize((int)b.size());
	for(int i=0;i<(int)b.size();i++)a[i]=add(a[i],b[i]);
	return a;
}
poly operator-=(poly &a,poly b){
	if((int)a.size()<(int)b.size())a.resize((int)b.size());
	for(int i=0;i<(int)b.size();i++)a[i]=sub(a[i],b[i]);
	return a;
}
poly operator*(poly a,poly b){
	poly c((int)a.size()+(int)b.size()-1);
	for(int i=0;i<(int)a.size();i++)
		for(int j=0;j<(int)b.size();j++)
			c[i+j]=add(c[i+j],mul(a[i],b[j]));
	return c;
}
poly trans(poly a){
	poly b((int)a.size());
	for(int i=0;i<(int)a.size();i++)
		for(int j=0;j<=i;j++)
			b[j]=(((i-j)&1)?sub:add)(b[j],mul(C[i][j],a[i]));
	return b;
}
poly trans2(poly a){
	poly b((int)a.size()+1);
	for(int i=0;i<(int)a.size();i++)b[i+1]=mul(a[i],mul(i,inv[i+1]));
	return b;
}
int eval(poly a,fract x){
	int n=mul(x.a,qsm(x.b,P-2));
	int tot=0;
	for(int i=0,Mul=1;i<(int)a.size();i++,Mul=mul(Mul,n))
		tot=add(tot,mul(Mul,a[i]));
	return tot;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<=40;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++)
			C[i][j]=add(C[i-1][j],C[i-1][j-1]);
	}
	inv[0]=inv[1]=1;
	for(int i=2;i<=40;i++)inv[i]=mul(P-P/i,inv[P%i]);
	for(int i=1;i<=n;i++)
		x[i]=read();
	vec.push_back((interval){(fract){0,1},poly(1,1)});
	poly x,b;
	x.push_back(0);
	x.push_back(1);
	b.push_back(P-1);
	b.push_back(1);
	for(int fd=1;fd<=n;fd++){
		cut.clear();
		for(int i=0;i<(int)vec.size();i++)cut.push_back(vec[i].l),cut.push_back(vec[i].l+1);
		std::sort(cut.begin(),cut.end());
		cut.resize(std::unique(cut.begin(),cut.end())-cut.begin());
		for(int i=0;i<(int)vec.size();i++){
			tem[i]=trans2(vec[i].f);
		}
		for(int i=0;i<(int)vec.size()-1;i++){
			h[i].resize(2);
			h[i][1]=sub(eval(vec[i].f,vec[i+1].l),eval(vec[i].f,vec[i].l));
			h[i][0]=sub(eval(tem[i],vec[i].l),eval(tem[i],vec[i+1].l));
		}
		for(int i=0,j=-1,k=0;i<(int)cut.size();i++){
			while(k<(int)vec.size()-1&&cut[i]>=vec[k+1].l)++k;
			while(j<(int)vec.size()-1&&cut[i]>=vec[j+1].l+1)++j;
			vec2.push_back((interval){cut[i],poly()});
			if(~j)vec2.back().f+=trans(vec[j].f);
			for(int l=j+1;l<k;l++)vec2.back().f+=h[l];
			vec2.back().f+=x*vec[k].f;
			vec2.back().f[1]=sub(vec2.back().f[1],eval(vec[k].f,vec[k].l));
			vec2.back().f-=tem[k];
			vec2.back().f[0]=add(vec2.back().f[0],eval(tem[k],vec[k].l));
			if(~j){
				vec2.back().f-=x*trans(vec[j].f);
				vec2.back().f[1]=add(vec2.back().f[1],eval(vec[j].f,vec[j+1].l));
				vec2.back().f+=trans(tem[j]);
				vec2.back().f[0]=sub(vec2.back().f[0],eval(tem[j],vec[j+1].l));
			}
			if(fd==1&&cut[i]==(fract){0,1})vec2.back().f+=x;
		}
		while(::x[fd]<cut.back())cut.pop_back(),vec2.pop_back();
		int v=eval(vec2.back().f,::x[fd]);
		if(::x[fd]==cut.back())cut.pop_back(),vec2.pop_back();
		vec2.push_back((interval){::x[fd],poly(1,v)});
		vec=vec2;
		vec2.clear();
	}
	printf("%d\n",vec.back().f[0]);
}