#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int cnt;
string s, t;
int main() {
	cin >> s;
	reverse(s.begin(), s.end());

	for (int i=0; i<s.size(); i++) {
		if (s[i] == '0') { t += '0', ++cnt; }
		else {
			--cnt;
			if (cnt<0) { t += '0'; ++cnt; }
			else t += '1';
		}
	}

	reverse(t.begin(), t.end());
	cout << t;
}