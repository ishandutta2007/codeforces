#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
const int maxn=3e5+5;
int n;
ll sum0[maxn],sum1[maxn];
int id[maxn][2];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int w=0;
pair<ll,int> p[2*maxn];
int lowbit[2*maxn];
int t00[2*maxn],t01[2*maxn],t10[2*maxn],t11[2*maxn];
void update(int x,int v,int *t){
	while(x<=w)t[x]=min(t[x],v),x+=lowbit[x];
	return ;
}
inline int query(int x,int *t){
	int res=n+1;
	while(x)res=min(res,t[x]),x-=lowbit[x];
	return res;
}
vector<int> P[2*maxn];
int main(){
	int T;
	T=read();
	while(T--){
		n=read();
		p[0]=make_pair(0,0);
		for(int i=1;i<=n;i++){
			int x;
			x=read();
			sum0[i]=sum0[i-1];sum1[i]=sum1[i-1];
			if(i&1)sum1[i]+=x;else sum0[i]+=x;
			p[i]=make_pair(sum0[i]-sum1[i],i);
			p[i+n]=make_pair(sum1[i]-sum0[i],-i);
		}
		sort(p,p+2*n+1);
		ll pre=-1e18;
		w=0;
		for(int i=0;i<=2*n;i++){
			if(p[i].fi>pre)P[++w].clear();
			id[abs(p[i].se)][p[i].se<0]=w;pre=p[i].fi;
		}
		id[0][1]=id[0][0];
		for(int i=0;i<=n;i++)P[id[i][0]].push_back(i);
		for(int i=1;i<=w;i++)lowbit[i]=i&-i;
		for(int i=1;i<=w;i++)t00[i]=t01[i]=t10[i]=t11[i]=n+1;
		ll res=0;
		for(int i=n;i>=1;i--){
			if(i&1){
				int pos=min(query(id[i-1][1]-1,t11),query(id[i-1][0]-1,t00))-1;
				res+=upper_bound(P[id[i-1][0]].begin(),P[id[i-1][0]].end(),pos)-P[id[i-1][0]].begin();
				res-=upper_bound(P[id[i-1][0]].begin(),P[id[i-1][0]].end(),i-1)-P[id[i-1][0]].begin();
				update(id[i][0],i,t10);update(id[i][1],i,t11);
			}
			else{
				int pos=min(query(id[i-1][0]-1,t00),query(id[i-1][1]-1,t11))-1;
				res+=upper_bound(P[id[i-1][0]].begin(),P[id[i-1][0]].end(),pos)-P[id[i-1][0]].begin();
				res-=upper_bound(P[id[i-1][0]].begin(),P[id[i-1][0]].end(),i-1)-P[id[i-1][0]].begin();
				update(id[i][0],i,t00);update(id[i][1],i,t01);
			}
		}
		printf("%lld\n",res);
	}
    return 0;
}