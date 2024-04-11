#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
const int maxn = 303030, b = 10*maxn, mod = 1e9 + 7;
using vi = vector<int>;
using ll = long long;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll n, a = 0, b = 0;
	cin >> n;
	for(int t, i = 0; i < n; i++) {
		cin >> t;
		if(t) b++;
		else a += b;
	}
	cout << a;
}