#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
const int maxn = 1<<21, mod = 1e9 + 7;
string s(maxn, 'a');
set<int> fr;
int n;
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for(int i = 0; i < maxn; i++) fr.insert(i);
	string t;
	int k;
	int r = 0;
	for(int i = 0; i < n; i++) {
		cin >> t >> k;
		for(int p; k--;) {
			cin >> p;p--;
			while(true) {
				auto j = *fr.lower_bound(p);
				if(j>=p+t.size()) break;
				fr.erase(j);
				s[j] = t[j-p];
				r = max(r, j);
			}
		}
	}
	cout << s.substr(0, r+1) << endl;
}