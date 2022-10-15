#include "bits/stdc++.h"
using namespace std;

string pow2[64];

void solve(){
	int n;
	cin >> n;

	string a = to_string(n);
	int ans = INT_MAX;

	for(int i = 0; i < 64; ++i){
		string b = pow2[i];
		int cur = 0;
		for(char c : a){
			if(c == b[cur]) ++cur;
		}

		ans = min(ans, int(a.size() + b.size()) - 2 * cur);
	}

	cout << ans << '\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for(int i = 0; i < 64; ++i){
		pow2[i] = to_string((1LL << i));
	}

	int t;
	cin >> t;
	while(t--){
		solve();
	}
}