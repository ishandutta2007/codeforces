#include<bits/stdc++.h>
#define int ll
#define rgi register int
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
const int N=1010;
int n,m,cnt;
char a[N][N];
void dfs(int x,int y){
	if(a[x][y]!='#')return;
	a[x][y]='.';
	dfs(x+1,y);
	dfs(x,y+1);
	dfs(x-1,y);
	dfs(x,y-1);
}
int h[N],l[N];
int ch[N],cl[N];
int checkh(int x){
	int fl=1;
	for(rgi i=1;i<=m;++i)if(a[x][i]=='#')fl=0;
	return fl;
}
int checkl(int x){
	int fl=1;
	for(rgi i=1;i<=n;++i)if(a[i][x]=='#')fl=0;
	return fl;
}
int c2h(int x){
	int fl=1,l=0,r=0;
	for(rgi i=1;i<=m;++i){
		if(a[x][i]=='#'){
			if(!l)l=i;
			r=i;
		}
	}
	for(rgi i=l;i<=r;++i)if(a[x][i]!='#')fl=0;
	return fl;
}
int c2l(int x){
	int fl=1,l=0,r=0;
	for(rgi i=1;i<=n;++i){
		if(a[i][x]=='#'){
			if(!l)l=i;
			r=i;
		}
	}
	for(rgi i=l;i<=r;++i)if(a[i][x]!='#')fl=0;
	return fl;
}
signed main(){
	read(n,m);
	for(rgi i=1;i<=n;++i)scanf("%s",a[i]+1);
	for(rgi i=1;i<=n;++i)h[i]=checkh(i);
	for(rgi i=1;i<=m;++i)l[i]=checkl(i);
	for(rgi i=1;i<=n;++i)for(rgi j=1;j<=m;++j){
		if(h[i]&&l[j])ch[i]=cl[j]=1;
	}
	for(rgi i=1;i<=n;++i)if(!h[i])ch[i]|=c2h(i);
	for(rgi i=1;i<=m;++i)if(!l[i])cl[i]|=c2l(i);
	for(rgi i=1;i<=n;++i){
		if(!ch[i]){
			puts("-1");
			return 0;
		}
	}
	for(rgi i=1;i<=m;++i){
		if(!cl[i]){
			puts("-1");
			return 0;
		}
	}
	for(rgi i=1;i<=n;++i)for(rgi j=1;j<=m;++j){
		if(a[i][j]=='#')dfs(i,j),++cnt;
	}
	cout<<cnt;
	return 0;
}