#include<bits/stdc++.h>
using namespace std;

const int _ = 4e5 + 7; int x[_] , y[_] , d[_] , col[_] , N; set < int > nxt[_]; vector < int > seq;

void dfs(int t){
	while(nxt[t].size()){
		int p = *nxt[t].begin(); nxt[t].erase(nxt[t].begin());
		int q = x[p] + y[p] - t; nxt[q].erase(p); dfs(q);
		seq.push_back(p); if(x[p] / 200001 == y[p] / 200001) seq.push_back(p);
	}
}

int main(){
	ios::sync_with_stdio(0); cin >> N; for(int i = 1 ; i <= N ; ++i){cin >> x[i] >> y[i]; d[x[i]] ^= 1; d[y[i] += 2e5] ^= 1;}
	vector < int > node; for(int i = 1 ; i <= 4e5 ; ++i) if(d[i]) node.push_back(i);
	for(int i = 0 ; i < node.size() ; i += 2){x[i / 2 + N + 1] = node[i]; y[i / 2 + N + 1] = node[i + 1];}
	
	for(int i = 1 ; i <= N + node.size() / 2 ; ++i){nxt[x[i]].insert(i); nxt[y[i]].insert(i);}
	for(int i = 1 ; i <= 2e5 ; ++i) dfs(i);
	for(int i = 0 ; i < seq.size() ; ++i) col[seq[i]] = i & 1;
	for(int i = 1 ; i <= N ; ++i) cout << (col[i] ? 'r' : 'b');
	return 0;
}