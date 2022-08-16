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
#endif

bool reachable(int x, int y){
	cout << "? " << x + 1 <<" " << y + 1 << endl;
	string s; cin >> s;
	return s[0] == 'Y';
}

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int n; cin >> n;
	vector<int> indeg(n);
	for(int & x : indeg) cin >> x;
	vector<int> perm(n);
	iota(all(perm), 0);
	sort(all(perm), [&](int i, int j){return indeg[i] < indeg[j];});
	vector<pii> vec;
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			vec.push_back({perm[i], perm[j]});
		}
	}
	sort(all(vec), [&](const pii & X, const pii & Y){return indeg[X.second] - indeg[X.first] > indeg[Y.second] - indeg[Y.first];});
	for(auto it : vec){
		if(reachable(it.second, it.first)){
			cout << "! " << it.first + 1 << " " << it.second + 1 << endl;
			return 0;
		}
	}
	cout << "! 0 0" << endl;
}