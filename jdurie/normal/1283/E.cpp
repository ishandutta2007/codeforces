#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
const ll NN = 200020;

ll x[NN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	ll n, min = 0, max = 0, last = -1; cin >> n;
	for(ll i = 0; i < n; i++) cin >> x[i];
	sort(x, x + n);
	for(ll i = 0; i < n; i++)
		if(abs(x[i] - last) > 1) {
			last = x[i] + 1;
			min++;
		}
	last = -1;
	for(ll i = 0; i < n; i++)
		if(last < x[i] - 1) {
			last = x[i] - 1;
			max++;
		} else if(last < x[i]) {
			last = x[i];
			max++;
		} else if(last < x[i] + 1) {
			last = x[i] + 1;
			max++;
		}
	cout << min << " " << max << endl;
}