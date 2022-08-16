#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...)
// #define endl '\n'
#endif
int n;
set<pair<int, int>> edges;
bool asked[10000];
vector<int> ask(int r){
	if(asked[r]) return {};
	asked[r] = true;
	r++;
	cout << "? " << r << endl;
	fflush(stdout);
	vector<int> ret(n);
	for(int i = 0; i < n; i++){
		cin >> ret[i];
		if(ret[i] == 1){
			int u = r, v = i + 1;
			if(u > v) swap(u,v);
			edges.insert({u, v});
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	cin >> n;
	vector<int> depths = ask(0);
	vector<vector<int>> d(2);
	for(int i = 0; i < n; i++) d[depths[i] % 2].push_back(i);
	int id = sz(d[1]) < sz(d[0]);

	for(int r : d[id]) ask(r);
	cout << "!" << endl;
	fflush(stdout);
	for(auto it : edges) cout << it.first << " " << it.second << endl;
	fflush(stdout);
}