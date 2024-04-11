#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
const int maxn = 105, mod = 1e9 + 7;
int n, q, se = 2, so = 1;
void print() {
	for(int i = 0; i < n/2; i++) {
		int x = (2*i + so)%n;
		if(x == 0) x = n;
		cout << x << " ";
		x = (2*i + se)%n;
		if(x == 0) x = n;
		cout << x << " ";
	}
	cout << endl;
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> q;
	for(int t, x; q--;) {
		cin >> t;
		if(t == 1) {
			cin >> x;
			x = (n+x)%n;
			if(x&1) swap(se, so);
			se = (n + se - 2*(x/2))%n;
			so = (n + so - 2*(x - (x/2)))%n;
		} else
			swap(so, se);
	}
	print();
}