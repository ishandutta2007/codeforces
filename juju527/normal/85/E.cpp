#include<bits/stdc++.h>
using namespace std;
const int maxn=5005,mod=1000000007;
struct point{
	short x,y;
}a[maxn];
int dis[maxn][maxn];
short n,maxx,maxy;
int g;
short c[maxn];
inline short read(){
	register short x=0,y=1;
	register char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*y;
}
inline short dist(point p,point q){
	return abs(p.x-q.x)+abs(p.y-q.y);
}
inline int power(register int x,register int b){
	register int ans=1;
	while(b){
		if(b&1)ans=1ll*ans*x%mod;
		x=1ll*x*x%mod;
		b>>=1;
	}
	return ans;
}
inline bool dfs(register short x,register short fa,int val){
	c[x]=c[fa]^1;
	for(register int i=1;i<=n;i++){
		if(i==fa||dis[x][i]<=val)continue;
		if(c[i]!=-1&&c[i]==c[x])return 1;
		if(c[i]!=-1)continue;
		if(dfs(i,x,val))return 1;
	}
	return 0;
}
inline short check(register int k){
	for(register short i=1;i<=n;i++)c[i]=-1;
	c[0]=0;
	register short sum=0;
	for(register short i=1;i<=n;i++){
		if(c[i]!=-1)continue;
		sum++;
		if(dfs(i,0,k))return 0;
	}
	return sum;
}
inline void search(){
	register int l=-1,r=maxx+maxy+1;
	while(l+1<r){
		register int mid=l+((r-l)>>1);
		if(check(mid))
			r=mid;
		else
			l=mid;
	}
	printf("%d\n",r);
	printf("%d\n",power(2,check(r)));
	return ;
}
int main(){
	n=read();
	for(register short i=1;i<=n;i++){
		a[i].x=read();
		a[i].y=read();
		maxx=max(maxx,a[i].x);
		maxy=max(maxy,a[i].y);
	}
	for(register short i=1;i<=n;i++)
		for(register short j=i+1;j<=n;j++)
			dis[i][j]=dis[j][i]=dist(a[i],a[j]);
	search();
	cerr<<clock()*1.0/CLOCKS_PER_SEC<<endl;
	return 0;
}