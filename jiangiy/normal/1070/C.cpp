#include<bits/stdc++.h>
#define maxn 201000
using namespace std;
typedef long long ll;
struct data{
	int lc,rc;
	ll sum,sz;
}s[maxn*40];
int n,k,m,ptr,rt,li[maxn],ri[maxn],ci[maxn],zid[maxn],pi[maxn];
map<int,int>id;
vector<int>G[1001000];
void mdy(int& rt,int l,int r,int x,int xs,ll co){
	if(!rt)rt=++ptr;
	s[rt].sz+=xs,s[rt].sum+=co;
	if(l==r)return ;
	int mid=l+r>>1;
	if(x<=mid)mdy(s[rt].lc,l,mid,x,xs,co);
	else mdy(s[rt].rc,mid+1,r,x,xs,co);
}
ll qry(int rt,int l,int r,int k){
	if(!rt)return 0;
	if(l==r)
		return (ll)min((ll)k,s[rt].sz)*zid[l];
	int mid=l+r>>1;
	if(s[s[rt].lc].sz>=k)return qry(s[rt].lc,l,mid,k);
	else return qry(s[rt].rc,mid+1,r,k-s[s[rt].lc].sz)+s[s[rt].lc].sum;
}
int main(){
	scanf("%d%d%d",&n,&k,&m);
	for(int i=1;i<=m;++i){
		scanf("%d%d%d%d",&li[i],&ri[i],&ci[i],&pi[i]);
		G[li[i]].push_back(i);
		G[ri[i]+1].push_back(-i);
		id[pi[i]]=0;
	}
	int ptr=0;
	for(auto& c:id)
		c.second=++ptr,zid[ptr]=c.first;
	ll ans=0;
	for(int i=1;i<=n;++i){
		for(auto c:G[i]){
			if(c<0)
				mdy(rt,1,ptr,id[pi[-c]],-ci[-c],-(ll)ci[-c]*pi[-c]);
			else mdy(rt,1,ptr,id[pi[c]],ci[c],(ll)ci[c]*pi[c]);
		}
//		printf("[%lld]",qry(rt,1,ptr,k));
		ans+=qry(rt,1,ptr,k);
	}
	printf("%lld",ans);
}