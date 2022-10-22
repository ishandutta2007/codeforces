#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> N;
	while (N--) {
		string x; cin >> x;

		int cnt[10]; memset(cnt, 0, sizeof cnt);
		int sum = 0;
		for (int i=0; i<x.size(); i++) {
			cnt[x[i]-'0']++;
			sum += x[i]-'0';
		}

		if (!cnt[0]) {
			cout << "cyan\n";
			continue;
		}

		--cnt[0];

		bool flag = false;
		for (int i=0; i<10; i+=2) if (cnt[i]) flag = true;

		if (sum%3==0 && flag) cout << "red\n";
		else cout << "cyan\n";
	}
}