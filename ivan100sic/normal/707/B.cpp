#include "bits/stdc++.h"
using namespace std;

vector<pair<int, int>> E[100005];
multiset<pair<long long, int>> S;
long long D[100005];
int N, M, K;

int main(){
	cin >> N >> M >> K;
	for (int i=1; i<=M; i++){
		int u, v, l;
		cin >> u >> v >> l;
		E[v].push_back(make_pair(u, l));
		E[u].push_back(make_pair(v, l));
	}
	memset(D, 63, sizeof(D));
	for (int i=1; i<=K; i++){
		int x;
		cin >> x;
		D[x] = 0;
		S.insert({0, x});
	}
	while (!S.empty()){
		auto p = *S.begin();
		S.erase(S.begin());
		if (D[p.second] < p.first) continue;
		int x = p.second;
	
		for (auto p : E[x]){
			if (p.second + D[x] < D[p.first]){
				S.insert({p.second + D[x], p.first});
				D[p.first] = p.second + D[x];
			}
		}	
	}
	long long m = 1e15;
	for (int i=1; i<=N; i++){
		if (D[i] > 0 && D[i] < 1e15){
			m = min(m, D[i]);
		}
	}
	if (m > 9.9e14) m = -1;
	cout << m;
	
	//cin >> m;

	return 0;
}