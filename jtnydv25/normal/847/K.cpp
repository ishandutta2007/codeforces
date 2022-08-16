#include <bits/stdc++.h>
using namespace std;

map<pair< string, string>, int> edges;

inline void add(string a, string b, int x){
	if(a > b) swap(a, b);
	edges[{a, b}] -= x;
}

int n, a, b, k, f;
vector<int> vec;
int main(){
	string p = "", q = "", P, Q;
	cin >> n >> a >> b >> k >> f;
	int COST = 0;
	for(int i = 1; i <= n; i++){
		cin >> P >> Q;
		int cost = a;
		if(P == q) cost = b;
		p = P; q = Q;
		add(P, Q, cost);
		COST += cost;
	}
	int ans = COST;
	for(auto it : edges) vec.push_back(it.second);
	sort(vec.begin(), vec.end());
	for(int i = 0; i < k && i < vec.size(); i++){
		COST += f + vec[i];
		ans = min(ans, COST);
	}
	cout << ans;
}