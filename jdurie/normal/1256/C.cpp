#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;

ll c[1010], space[1010];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n, m, d;
	cin >> n >> m >> d;
	for(ll i = 0; i < m; i++) cin >> c[i];
	space[m - 1] = c[m - 1];
	for(ll i = m - 2; i >= 0; i--) space[i] = c[i] + space[i + 1];
	if(space[0] + (m + 1) * d - m < n + 1) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	ll idx = 0, cI = 0, last = -1;
	while(idx < n && cI < n) {
		while(idx - last < d && space[cI] + idx < n) {
			cout << "0 ";
			idx++;
		}	
		for(ll i = 0; i < c[cI]; i++) {	
			cout << (cI + 1) << " ";
			idx++;
		}
		last = idx - 1;
		cI++;
	}
	while(idx < n) {
		cout << "0 ";
		idx++;
	}
	return 0;
}