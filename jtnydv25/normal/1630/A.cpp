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
#define endl '\n' // remove in interactive
#endif

vector<pair<int, int>> go(int n, int k){
	vector<pii> ret;
	if(k == n - 1){
		if(n <= 4){
			return {};
		}
		ret.push_back({0, n - 4});
		ret.push_back({1, 3});
		ret.push_back({2, n - 3});
		ret.push_back({n - 2, n - 1});
		for(int i = 4; i < n / 2; i++){
			ret.push_back({i, n - 1 - i});
		}
		return ret;
	}

	if(n == 2){
		return {{0, 1}};
	}
	if(k < n / 2){
		for(int i = 0; i < n / 2; i++){
			if(i == k){
				ret.push_back({i, n - 1});
			} else if(i == 0){
				ret.push_back({i, n - 1 - k});
			} else{
				ret.push_back({i, n - 1 - i});
			}
		}
	} else{
		for(int i = n / 2; i < n; i++){
			if(i == k){
				ret.push_back({i, n - 1});
			} else if(i == n - 1){
				ret.push_back({0, n - 1 - k});
			} else{
				ret.push_back({i, n - 1 - i});
			}
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int t; cin >> t;
	// trace(t);
	while(t--){
		int n, k; cin >> n >> k;
		vector<pii> ans = go(n, k);
		if(ans.empty()){
			cout << -1<<endl;
			continue;
		}
		for(auto it: ans) cout << it.first << " " << it.second << endl;
	}
}