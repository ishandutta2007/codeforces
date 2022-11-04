#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef _FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		string s;
		cin >> s;
		vi ans(n * m, 0);
		vector<bool> here(m, false);
		int now = 0;
		for(int i = 0; i < n * m; i++) {
			if(s[i] == '1') {
				if(!here[i % m]) {
					here[i % m] = true;
					++now;
				}
			}
			ans[i] += now;
		}
		vi minus(m, 0);
		int first = -1;
		int serie = 0;
		for(int i = 0; i < n * m; i++) {
			if(s[i] == '0' && first == -1) continue;
			if(s[i] == '1' && first == -1) first = i;
			int poten = (i - first) / m + 1;
			if(s[i] == '1') {
				serie = 0;
			} else {
				++serie;
				if(serie >= m) {
					++minus[i % m];
				}
			}
			ans[i] += poten - minus[i % m];
		}
		for(int i = 0; i < n * m; i++) {
			cout << ans[i] << ' ';
		}
		cout << '\n';
	}
}