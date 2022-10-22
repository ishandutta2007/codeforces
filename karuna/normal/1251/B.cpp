#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int Q, N;
string s[50];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> Q;
	while (Q--) {
		cin >> N;
		for (int i=0; i<N; i++) cin >> s[i];

		bool flag = false;
		int cnt0=0, cnt1=0;
		for (int i=0; i<N; i++) {
			if ((int)s[i].size()%2 == 1) flag = true;
			for (int j=0; j<(int)s[i].size(); j++) {
				if (s[i][j]=='0') ++cnt0;
				else ++cnt1;
			}
		}

		if (flag) cout << N;
		else {
			if (cnt0%2==1 || cnt1%2==1) cout << N-1;
			else cout << N;
		}

		cout << '\n';
	}
}