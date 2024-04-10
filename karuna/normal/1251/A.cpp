#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int Q;
string s;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> Q;
	while (Q--) {
		cin >> s;
		set<char> st;
		int cnt = 1;
		for (int i=1; i<s.size(); i++) {
			if (s[i] == s[i-1]) ++cnt;
			else {
				if (cnt%2==1) st.insert(s[i-1]);
				cnt = 1;
			}
		}
		if (cnt%2==1) st.insert(s[s.size()-1]);

		for (auto it = st.begin(); it != st.end(); it++) cout << (*it);
		cout << '\n';
	}
}