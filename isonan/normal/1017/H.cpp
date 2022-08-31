#include <algorithm>
#include <cstdio>
#include <cmath>

const int P=998244353;
inline int mul(const int &a,const int &b){return 1ll*a*b%P;}
inline int sub(int a,const int &b){a-=b;return (a<0)?a+P:a;}
inline int add(int a,const int &b){a+=b;return(a>=P)?a-P:a;}
int qsm(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=mul(ans,a);
		a=mul(a,a);
		b>>=1;
	}
	return ans;
}
int n,m,q,pos[200010],a[200010],cnt[200010],tot[200010],top,inv[200010],_mul[200010],k;
int ans[200010];
struct point{
	int l,r,k,ord;
}num[200010];
bool cmp1(point a,point b){return a.k<b.k;}
bool cmp2(point a,point b){return (pos[a.l]<pos[b.l])||(pos[a.l]==pos[b.l]&&((a.r!=b.r)?(a.r<b.r)^(pos[a.l]&1):(a.ord<b.ord)));}
int nl,nr,nowans;
void addl(){
	--nl;
	nowans=mul(nowans,cnt[a[nl]]--);
}
void addr(){
	++nr;
	nowans=mul(nowans,cnt[a[nr]]--);
}
void dell(){
	nowans=mul(nowans,inv[++cnt[a[nl]]]);
	++nl;
}
void delr(){
	nowans=mul(nowans,inv[++cnt[a[nr]]]);
	--nr;
}
void solve(int l,int r){
	_mul[0]=1;
	for(int i=1,start=(1ll*num[l].k*m+n)%P;i<=n;i++,start--)
		_mul[i]=mul(_mul[i-1],start);
	int bl=std::max((int)((double)n/sqrt(r-l+1)),1);
	for(int i=1;i<=n;i++)pos[i]=(i-1)/bl+1;
	for(int i=1;i<=m;i++)cnt[i]=tot[i]+num[l].k;
	std::sort(num+l,num+r+1,cmp2);
//	printf("solve %d %d\n",l,r);
	nl=1,nr=0,nowans=1;
	for(int i=l;i<=r;i++){
		while(nl>num[i].l)addl();
		while(nr<num[i].r)addr();
		while(nl<num[i].l)dell();
		while(nr>num[i].r)delr();
		ans[num[i].ord]=mul(mul(nowans,qsm(_mul[num[i].r-num[i].l+1],P-2)),_mul[n]);
	}
}
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
void write(int x){
	if(x>9)write(x/10);
	putchar((x%10)+'0');
}
int main(){
//	freopen("in.txt","r",stdin);
	n=read(),m=read(),q=read();
	for(int i=1;i<=n;i++)++tot[a[i]=read()];
	for(int i=1;i<=q;i++)num[i].l=read(),num[i].r=read(),num[i].k=read(),num[i].ord=i;
	inv[0]=inv[1]=1;
	for(int i=2;i<=200000;i++)inv[i]=mul(P-P/i,inv[P%i]);
	std::sort(num+1,num+q+1,cmp1);
	for(int i=1,last=1;i<=q;i++){
		if(i==q||(num[i].k!=num[i+1].k)){
			solve(last,i);
			last=i+1;
		}
	}
	for(int i=1;i<=q;i++)write(ans[i]),putchar('\n');
}