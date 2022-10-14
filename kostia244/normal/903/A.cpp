#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<ll>;
const ll mod = 998244353ll;

int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	ll t, x, a, b;
	cin >> t;
	while(t--) {
		cin >> x;
		a = 0;
		for(int i = 0; i*3 <= x; i++)
			if((x-3*i)%7 == 0)
				a = 1;
		cout << (a ? "YES" : "NO") << "\n";
	}
}