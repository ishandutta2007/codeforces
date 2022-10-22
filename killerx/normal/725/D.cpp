#include<cstdio>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
#define ll long long
const int N=1<<19;
int n;
ll t[N],w[N];
priority_queue<ll,vector<ll>,greater<ll> >pq;
int id[N];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i)scanf("%lld%lld",t+i,w+i);
	for(int i=1;i<n;++i)id[i-1]=i;
	sort(id,id+n-1,[&](int a,int b){return t[a]>t[b];});
	int j=0;
	ll nw=t[0];
	int cur=0,ans=n;
	while(1){
		for(;j<n-1&&t[id[j]]>nw;++j)pq.push(w[id[j]]-t[id[j]]+1);
		ans=min(ans,cur+1+(int)pq.size());
		if(!pq.empty()){
			ll x=pq.top();pq.pop();
			if(nw>=x)nw-=x;else++cur;
		}else break;
	}
	printf("%d\n",ans);
	return 0;
}