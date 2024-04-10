#include<bits/stdc++.h>
#define rgi register int
#define pbk push_back
#define pii pair<int,int>
#define fi first
#define se second
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
const int N=510,S=1000010;
int n,m,q,ans[S];
char ch[N][N];
bitset<N>f[N][N],g[N][N];
struct node{
	int a,b,c,d,id;
	inline void get(int D){id=D,read(a,b,c,d);}
	inline void calc(int w){ans[id]=(w?g[b][a]&f[d][c]:g[a][b]&f[c][d]).any();}
}Q[S];
inline int chk(int x,int y,int w){return (w?ch[y][x]:ch[x][y])=='.';}
void solve(int xl,int xr,int yl,int yr,int L,int R,int w){
	if(xl>xr||yl>yr||L>R)return;
	if(w)swap(xl,yl),swap(xr,yr);
	int sl=L-1,sr=R+1,M=(xl+xr>>1);
	for(rgi i=L;i<=R;++i)if(w?Q[i].d<M:Q[i].c<M)swap(Q[i],Q[++sl]);
	for(rgi i=R;i>sl;--i)if(w?Q[i].b>M:Q[i].a>M)swap(Q[i],Q[--sr]);
	if(sl+1==sr)goto tag;
	for(rgi i=yl;i<=yr;++i){
		if(chk(M,i,w))f[M][i]=f[M][i-1],f[M][i][i]=1;
		else f[M][i]=0;
	}
	for(rgi i=M+1;i<=xr;++i){
		for(rgi j=yl;j<=yr;++j){
			if(chk(i,j,w)){
				f[i][j]=f[i-1][j];
				if(j!=yl)f[i][j]|=f[i][j-1];
			}
			else f[i][j]=0;
		}
	}
	for(rgi i=yr;i>=yl;--i){
		if(chk(M,i,w))g[M][i]=g[M][i+1],g[M][i][i]=1;
		else g[M][i]=0;
	}
	for(rgi i=M-1;i>=xl;--i){
		for(rgi j=yr;j>=yl;--j){
			if(chk(i,j,w)){
				g[i][j]=g[i+1][j];
				if(j!=yr)g[i][j]|=g[i][j+1];
			}
			else g[i][j]=0;
		}
	}
	for(rgi i=sl+1;i<sr;++i)Q[i].calc(w);
	tag:if(w)solve(yl,yr,xl,M-1,L,sl,!w),solve(yl,yr,M+1,xr,sr,R,!w);
	else solve(xl,M-1,yl,yr,L,sl,!w),solve(M+1,xr,yl,yr,sr,R,!w);
}
signed main(){
	read(n,m);
	for(rgi i=1;i<=n;++i)scanf("%s",ch[i]+1);
	read(q);
	for(rgi i=1;i<=q;++i)Q[i].get(i);
	solve(1,n,1,m,1,q,0);
	for(rgi i=1;i<=q;++i)puts(ans[i]?"Yes":"No");
	return 0;
}