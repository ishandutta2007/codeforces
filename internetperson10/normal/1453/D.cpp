#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

vector<int> ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		ll n;
		cin >> n;
		if(n%2) {
			cout << -1 << '\n';
			continue;
		}
		n -= 2;
		int stages = 1;
		ans.push_back(1);
		while(n) {
			ll k = 4;
			int i = 0;
			while(n >= k-2) {
				k *= 2; i++;
			}
			ans.push_back(i);
			stages += i;
			n -= (k/2 - 2);
		}
		if(stages > 2000) {
			cout << -1 << '\n';
			continue;
		}
		cout << stages << '\n';
		for(int i : ans) {
			for(int j = 1; j < i; j++) {
				cout << 0 << ' ';
			}
			cout << 1 << ' ';
		}
		cout << '\n';
		vector<int>().swap(ans);
	}
}