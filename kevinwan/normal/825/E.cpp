#include<bits/stdc++.h>
#ifndef LOCAL_PROJECT
#define cerr if(0)cerr
#endif
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll mod=998244353;
const int mn=1e5+10;
vector<int>g[mn];
int num[mn],ans[mn];
int main(){
#ifdef LOCAL_PROJECT
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
#else
    cin.tie(0);
    cin.sync_with_stdio(0);
#endif
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
    	int a,b;
    	cin>>a>>b;
    	g[b].push_back(a);
    	num[a]++;
    }
    priority_queue<int>pq;
    for(int i=1;i<=n;i++)if(!num[i])pq.push(i);
   	int val=n;
    while(pq.size()){
    	int x=pq.top();
    	ans[x]=val--;
    	pq.pop();
    	for(int y:g[x]){
    		num[y]--;
    		if(!num[y])pq.push(y);
    	}
    }
    for(int i=1;i<=n;i++)printf("%d ",ans[i]);
}