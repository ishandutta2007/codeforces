#include "bits/stdc++.h"
using namespace std;

void solve(){
	long long a, b, c;
	cin >> a >> b >> c;

	long long n = llabs(a - b) * 2, k = n / 2;
	if(max(a, b) > n || c > n) cout << -1;
	else cout << (c + k - 1) % n + 1;
	cout << '\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while(t--){
		solve();
	}
}