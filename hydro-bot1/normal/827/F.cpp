// Hydro submission #632b07f344e7d0bd86fff860@1663764467835
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 500001
ll Lated[maxn][2],cnt=0;
ll head[maxn][2];
ll n,m;
struct edge{
	ll u,v,start,end,nxt;
	friend bool operator <(const edge &a,const edge &b){
		return a.start>b.start;
	}
}f[maxn<<2],tmp;
priority_queue <edge> Q;
void Hang_back(ll x,ll t,ll en){
	Lated[x][t&1]=max(Lated[x][t&1],en);
	for(int i=head[x][t&1];i;i=f[i].nxt){
		tmp=f[i];tmp.start=t;
		Q.push(tmp);
	}
	head[x][t&1]=0;
}
inline void add_edge(edge Temp){
	f[++cnt]=Temp;
	f[cnt].nxt=head[Temp.u][Temp.start&1];
	head[Temp.u][Temp.start&1]=cnt;
}
int main()
{
	scanf("%lld%lld",&n,&m);
	if(n==1) return puts("0"),0;
	for(int i=1,a,b,l,r;i<=m;i++){
		scanf("%d%d%d%d",&a,&b,&l,&r);r-=1;
		tmp.u=a,tmp.v=b;
		tmp.start=l,tmp.end=r-((r^l)&1);Q.push(tmp);
		tmp.start++;tmp.end=r-((r^l^1)&1);Q.push(tmp);
		swap(tmp.u,tmp.v);
		tmp.start=l,tmp.end=r-((r^l)&1);Q.push(tmp);
		tmp.start++;tmp.end=r-((r^l^1)&1);Q.push(tmp);
	}
	memset(Lated,225,sizeof Lated);
	Lated[1][0]=0;
	while(Q.size()){
		tmp=Q.top();Q.pop();
		if(tmp.start>tmp.end) continue ;
		if(Lated[tmp.u][tmp.start&1]>=tmp.start){
			if(tmp.v==n) return printf("%lld\n",tmp.start+1),0;
			Hang_back(tmp.v,tmp.start+1,tmp.end+1);
		}
		else add_edge(tmp);
	}
	puts("-1");
	return 0;
}