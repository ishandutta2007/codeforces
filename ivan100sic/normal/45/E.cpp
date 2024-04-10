#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

map<char, int> ca, cb;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	vector<string> a(n); 
	for (int i=0; i<n; i++) {
		cin >> a[i];
		ca[a[i][0]]++;
	}
	map<char, set<string>> mp;
	for (int i=0; i<n; i++) {
		string s;
		cin >> s;
		mp[s[0]].insert(s);
		cb[s[0]]++;
	}

	vector<string> sol;

	sort(a.begin(), a.end());
	for (int i=0; i<n; i++) {
		// ako mozes, spari sa a
		string s = a[i];

		for (char x='A'; x<='Z'; x++) {
			bool cond;

			if (x == s[0]) {
				cond = cb[x] > 0;
			} else {
				cond = cb[x] > ca[x] && ca[s[0]] > cb[s[0]];
			}

			if (cond) {
				cb[x]--;
				ca[s[0]]--;

				string p = *mp[x].begin();

				// cerr << "ja sam retard jer... " << s << ' ' << p << "\n";
				
				mp[x].erase(mp[x].begin());
				sol.push_back(s + ' ' + p);
				break;
			}
		}
	}

	sort(sol.begin(), sol.end());

	for (int i=0; i<n; i++) {
		cout << sol[i];
		if (i < n-1) {
			cout << ", ";
		}
	}
	cout << '\n';
}