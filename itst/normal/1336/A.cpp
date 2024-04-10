#include<bits/stdc++.h>
using namespace std;

set < int > nxt[200003]; int N , dep[200003] , num[200003] , K; long long sum;
priority_queue < pair < int , int > > q;

void dfs(int x , int p){dep[x] = dep[p] + 1; for(auto t : nxt[x]) if(t != p) dfs(t , x);}

int main(){
	cin >> N >> K; for(int i = 1 ; i < N ; ++i){int p , q; cin >> p >> q; nxt[p].insert(q); nxt[q].insert(p);}
	dfs(1 , 0); for(int i = 2 ; i <= N ; ++i) if(nxt[i].size() == 1) q.push(make_pair(dep[i] - 1 , i));
	while(!q.empty() && K--){
		int t = q.top().second; sum += q.top().first; q.pop();
		int p = *nxt[t].begin(); nxt[p].erase(t); num[p] += num[t] + 1;
		if(nxt[p].size() == 1 && p != 1) q.push(make_pair(dep[p] - 1 - num[p] , p));
	}
	cout << sum;
	return 0;
}