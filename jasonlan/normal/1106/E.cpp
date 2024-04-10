#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const int maxn=101000,maxm=210;
const ll INF=1ll<<62;
int n,m,k;
struct point{
	int s,t,d;ll w;
	bool operator < (const point &b)const{
		if(w!=b.w)return w<b.w;
		return d<b.d;
	}
}p[maxn];
bool cmp(point a,point b){
	return a.s<b.s;
}
ll f[maxn][maxm];
priority_queue <point> pq;
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=res*10+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
int main(){
	n=read();m=read();k=read();
	for(register int i=1;i<=k;++i){
		p[i].s=read();p[i].t=read();p[i].d=read();p[i].w=read();
	}
	sort(p+1,p+1+k,cmp);
	memset(f,0x3f,sizeof(f));
	f[0][0]=0;
	for(register int i=0,l=1,d,w;i<=n;++i){
		while(pq.size()&&pq.top().t<i)pq.pop();
		while(l<=k&&p[l].s<=i)pq.push(p[l]),++l;
		if(!pq.size())
			d=i,w=0;
		else
			d=pq.top().d,w=pq.top().w;
		for(register int j=0;j<=m;++j)
			f[d+1][j]=min(f[d+1][j],f[i][j]+w);
		for(register int j=0;j<m;++j)
			f[i+1][j+1]=min(f[i+1][j+1],f[i][j]);
	}
	ll ans=INF;
	for(register int i=0;i<=m;++i)
		ans=min(ans,f[n+1][i]);
	printf("%lld",ans);
    return 0;
}