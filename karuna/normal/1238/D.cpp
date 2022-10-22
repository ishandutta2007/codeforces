#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll N, ans;
string s;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> N >> s;
	ans = (N-1)*N/2;

	ll cnt = 0;
	for (int i=0; i<N; i++) {
		if (s[i]=='A') ++cnt;
		else { ans -= cnt; cnt=0; }
	}

	cnt = 0;
	for (int i=0; i<N; i++) {
		if (s[i]=='B') ++cnt;
		else { ans -= cnt; cnt=0; }
	}

	cnt = 0;
	for (int i=N-1; i>=0; i--) {
		if (s[i]=='B') ++cnt;
		else { ans -= cnt; cnt=0; }
	}

	cnt = 0;
	for (int i=N-1; i>=0; i--) {
		if (s[i]=='A') ++cnt;
		else { ans -= cnt; cnt=0; }
	}

	for (int i=0; i<N-1; i++) {
		if (s[i]=='A' && s[i+1]=='B') ++ans;
		if (s[i]=='B' && s[i+1]=='A') ++ans;
	}
	cout << ans;
}