#include <cstdio>
#include <vector>
#include <algorithm>

const int P=998244353;
inline int mul(const int &a,const int &b){return 1ll*a*b%P;}
inline int sub(int a,const int &b){a-=b;return (a<0)?a+P:a;}
inline int add(int a,const int &b){a+=b;return(a>=P)?a-P:a;}
typedef std::vector<int> poly;
poly operator*(poly a,poly b){
	int size=a.size()+b.size()-1;
	poly c(size);
	for(int i=0;i<a.size();i++)
		for(int j=0;j<b.size();j++)
			c[i+j]=add(c[i+j],mul(a[i],b[j]));
	return c;
}
poly operator+(poly a,poly b){
	if(a.size()<b.size())a.resize(b.size());
	for(int i=0;i<b.size();i++)a[i]=add(a[i],b[i]);
	return a;
}
poly operator-(poly a,poly b){
	if(a.size()<b.size())a.resize(b.size());
	for(int i=0;i<b.size();i++)a[i]=sub(a[i],b[i]);
	return a;
}
poly diff(poly a){
	for(int i=0;i<a.size()-1;i++)a[i]=mul(a[i+1],i+1);
	a.pop_back();
	return a;
}
poly lift(poly a,int n){
	a.resize(a.size()+n);
	for(int i=a.size()-1;i>=n;i--)a[i]=a[i-n];
	for(int i=0;i<n;i++)a[i]=0;
	return a;
}
struct fract{
	poly a,b;
	fract operator*(fract c){return (fract){a*c.a,b*c.b};}
	fract operator+(fract c){return (fract){a*c.b+b*c.a,b*c.b};}
	fract diff(){return (fract){::diff(a)*b-::diff(b)*a,b*b};}
	fract sum(){return (fract){b,b-a};}
	void print(){
		for(int i=0;i<a.size();i++)printf("%d ",a[i]);putchar('\n');
		for(int i=0;i<b.size();i++)printf("%d ",b[i]);putchar('\n');
	}
}fib,H,C,tem,ans;
fract get(fract f){
	f=f.diff();
	f.a=lift(f.a,1);
	f=f.diff();
	f.a=lift(f.a,1);
	return f;
}
int f[50001];
int getval(int n,fract ans){
	f[0]=1;
	for(int i=1;i<=n;i++){
		f[i]=0;
		for(int j=1;j<ans.b.size();j++)
			if(i-j>=0)f[i]=sub(f[i],mul(f[i-j],ans.b[j]));
	}
	int Ans=0;
	for(int i=0;i<ans.a.size()&&n-i>=0;i++)Ans=add(Ans,mul(ans.a[i],f[n-i]));
	return Ans;
}
int main(){
	fib.a.push_back(1);
	fib.b.push_back(1);
	fib.b.push_back(0);
	fib.b.push_back(P-1);
	fib.b.push_back(0);
	fib.b.push_back(P-1);
//	for(int i=0;i<6;i++)printf("%d ",getval(i,fib));putchar('\n');
	tem=get(fib);
	tem.a=lift(tem.a,1);
	C=tem;
	fib.a=lift(fib.a,1);
	tem=get(fib);
	tem.a=lift(tem.a,1);
	fib.a=lift(fib.a,1);
	H=get(fib);
	H.a=lift(H.a,1);
	C=C+H.sum()*tem*tem;
	ans=H.diff()*H.sum()+C.diff()*C.sum();
	int n;
	scanf("%d",&n);
	printf("%d\n",getval(n-1,ans));
}