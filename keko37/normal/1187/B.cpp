#include<bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

int n, q;
string s;
int tmp[30];
vector <int> f[30];

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> s;
	for (int i=0; i<n; i++) {
		if (i > 0) {
			for (int j=0; j<26; j++) {
				f[j].push_back(f[j].back());
			}
		} else {
			for (int j=0; j<26; j++) {
				f[j].push_back(0);
			}
		}
		f[s[i] - 'a'][i]++;
	}
	cin >> q;
	for (int i=0; i<q; i++) {
		string t;
		cin >> t;
		for (int j=0; j<26; j++) {
			tmp[j] = 0;
		}
		int len = t.size();
		for (int j=0; j<len; j++) {
			tmp[t[j] - 'a']++;
		}
		int sol = 0;
		for (int j=0; j<26; j++) {
			sol = max(sol, (int) (lower_bound(f[j].begin(), f[j].end(), tmp[j]) - f[j].begin()) );
		}
		cout << sol + 1 << endl;
	}
	return 0;
}