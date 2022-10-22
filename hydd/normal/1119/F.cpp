#include<bits/stdc++.h>
//#include "roads.h"
typedef long long ll;
typedef std::pair<int,int> pii;
std::vector<pii> vec[410000];
ll dp[410000][2];
int d,cnt,deg[410000],tim[410000];
std::vector<ll> Ans;
struct node{
	std::priority_queue<ll> p,q; ll sum;
	ll top(){
		while (!q.empty()&&p.top()==q.top()) p.pop(),q.pop();
		return p.top();
	}
	void push(ll x){ p.push(x); sum+=x;}
	void erase(ll x){ q.push(x); sum-=x;}
	void pop(){ sum-=top(); p.pop();}
	int size(){ return p.size()-q.size();}
} Heap[410000];
void Del(int u){
	for (pii t:vec[u]){
		int v=t.first,w=t.second;
		if (deg[v]<=d) break;
		Heap[v].push(w);
	}
}
std::vector<ll> del,add;
void dfs(int u,int f){
	tim[u]=d; int num=deg[u]-d;
	ll res=0;
	while (Heap[u].size()>num) Heap[u].pop();
	for (pii t:vec[u]){
		int v=t.first,w=t.second;
		if (v==f) continue;
		if (deg[v]<=d) break;
		
		dfs(v,u);
	}
	
	add.clear(); del.clear();
	for (pii t:vec[u]){
		int v=t.first,w=t.second;
		if (v==f) continue;
		if (deg[v]<=d) break;
		
		ll x=dp[v][1]+w-dp[v][0];
		if (x<=0){
			num--;
			res+=dp[v][1]+w;
			continue;
		}
		res+=dp[v][0]; Heap[u].push(x);
		del.push_back(x);	
	}
	
	num=std::max(num,0);
	while (Heap[u].size()>num) add.push_back(Heap[u].top()),Heap[u].pop();
	dp[u][0]=res+Heap[u].sum;
	num=std::max(num-1,0);
	while (Heap[u].size()>num) add.push_back(Heap[u].top()),Heap[u].pop();
	dp[u][1]=res+Heap[u].sum;
	
	for (int i:add) Heap[u].push(i);
	for (int i:del) Heap[u].erase(i);
}
bool cmp(pii x,pii y){
	return deg[x.first]>deg[y.first];
}
pii num[410000];
std::vector<ll> minimum_closure_costs(int N, std::vector<int> U, std::vector<int> V, std::vector<int> W){
	ll res=0;
    for (int i=0;i<N-1;i++){
        vec[U[i]].push_back(pii(V[i],W[i]));
        vec[V[i]].push_back(pii(U[i],W[i]));
        deg[U[i]]++; deg[V[i]]++; res+=W[i];
    }
    for (int i=0;i<N;i++) num[i]=pii(deg[i],i);
    sort(num,num+N);
    for (int i=0;i<N;i++) sort(vec[i].begin(),vec[i].end(),cmp);
    
    Ans.resize(N);
    Ans[0]=res;
    int i=0;
    for (d=1;d<N;d++){
    	for (;i<N&&num[i].first==d;i++) Del(num[i].second);
    	ll ans=0;
    	for (int j=i;j<N;j++){
    		int v=num[j].second;
    		if (tim[v]==d) continue;
    		dfs(v,-1); ans+=dp[v][0];
		}
		Ans[d]=ans;
	}
	return Ans;
}

int main() {
  int N;
  assert(1 == scanf("%d", &N));

  std::vector<int> U(N - 1), V(N - 1), W(N - 1);
  for (int i = 0; i < N - 1; ++i) {
    assert(3 == scanf("%d %d %d", &U[i], &V[i], &W[i]));
    U[i]--; V[i]--;
  }
//	puts("OK");
  std::vector<long long> closure_costs = minimum_closure_costs(N, U, V, W);
  for (int i = 0; i < static_cast<int>(closure_costs.size()); ++i) {
    if (i > 0) {
      printf(" ");
    }
    printf("%lld",closure_costs[i]);
  }
  printf("\n");
  return 0;
}