#include<bits/stdc++.h>
#define rgi register int
#define pbk push_back
#define pii pair<int,int>
#define fi first
#define se second
#define lc k<<1
#define rc lc|1
#define mid (l+r>>1)
#define fin(x) freopen(x,"r",stdin)
#define fout(x) freopen(x,"w",stdout)
typedef long long ll;
using namespace std;
inline void read(){}template <typename T,typename... Ts> inline void read(T& A,Ts&... As){
	T x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	A=x*f,read(As...);
}
inline void write(char a){putchar(a);}
template <typename T> inline void write(T a){
	if(a<0ll)putchar('-'),a=-a;
	if(a>9ll)write(a/10ll);
	putchar(a%10ll+'0');
}
template <typename T,typename... Ts> inline void write(T A,Ts... As){write(A),write(As...);}
const int N=100010;
pii p[N];
vector<int>v[N<<2];
int a[9],b[9],c[9],sx[2],sy[2],fx[2],fy[2],n;
void build(int k,int l,int r){
	for(rgi i=l;i<=r;++i)v[k].pbk(p[i].se);
	if(l==r)return;
	sort(v[k].begin(),v[k].end());
	build(lc,l,mid),build(rc,mid+1,r);
}
int Q(int x,int y,int k=1,int l=1,int r=n){
	if(p[l].fi>x)return 0;
	if(p[r].fi<=x)return upper_bound(v[k].begin(),v[k].end(),y)-v[k].begin();
	return Q(x,y,lc,l,mid)+Q(x,y,rc,mid+1,r);
}
int x[N],y[N];
int get(){
	sx[0]=c[0]+c[3]+c[6],sx[1]=sx[0]+c[1]+c[4]+c[7];
	sy[0]=c[0]+c[1]+c[2],sy[1]=sy[0]+c[3]+c[4]+c[5];
	for(rgi i=0;i<2;++i)if(x[sx[i]]==x[sx[i]+1]||y[sy[i]]==y[sy[i]+1])return 0;
	for(rgi i=0;i<2;++i)fx[i]=x[sx[i]],fy[i]=y[sy[i]];
	if(Q(fx[0],fy[0])!=c[0]||Q(fx[0],fy[1])!=c[0]+c[3]||Q(fx[1],fy[0])!=c[0]+c[1]||Q(fx[1],fy[1])!=c[0]+c[1]+c[3]+c[4])return 0;
	printf("%.8lf %.8lf\n%.8lf %.8lf",(double)fx[0]+0.5,(double)fx[1]+0.5,(double)fy[0]+0.5,(double)fy[1]+0.5);
	return 1;
}
int main(){
	read(n);
	for(int i=1;i<=n;++i)read(x[i],y[i]),p[i]=pii(x[i],y[i]);
	sort(x+1,x+n+1),sort(y+1,y+n+1),sort(p+1,p+n+1);
	for(rgi i=0;i<9;++i)read(a[i]),b[i]=i;
	build(1,1,n);
	do{
		for(rgi i=0;i<9;++i)c[i]=a[b[i]];
		if(get())return 0;
	}while(next_permutation(b,b+9));
	puts("-1");
	return 0;
}