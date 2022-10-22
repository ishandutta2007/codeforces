#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int T;
string s;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> T;
	while (T--) {
		cin >> s;
		vector<int> odd, even;

		for (int i=0; i<(int)s.size(); i++) {
			if ((s[i]-'0')%2) odd.push_back(s[i]-'0');
			else even.push_back(s[i]-'0');
		}

		vector<int>::iterator ito, ite;
		ito = odd.begin(); ite = even.begin();

		while (ito != odd.end() && ite != even.end()) {
			if (*ito < *ite) cout << (*ito++);
			else cout << (*ite++);
		}
		while (ito != odd.end()) cout << (*ito++);
		while (ite != even.end()) cout << (*ite++);

		cout << '\n';
	}
}