#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using llf = long double;
using pi = pair<lint, lint>;
const int MAXN = 305;

int main(){
		ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, q; cin >> n >> q;
	string s; cin >> s;
	int ans = 0;
	for(int i = 0; i < n - 2; i++){
		if(s.substr(i, 3) == "abc") ans++;
	}
	while(q--){
		int x; string c;
		cin >> x >> c;
		x--;
		for(int i = max(x-2, 0); i <= min(n-3, x); i++){
			if(s.substr(i, 3) == "abc") ans--;
		}
		s[x] = c[0];
		for(int i = max(x-2, 0); i <= min(n-3, x); i++){
			if(s.substr(i, 3) == "abc") ans++;
		}
		cout << ans << '\n';
	}
}