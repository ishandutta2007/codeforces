#include<bits/stdc++.h>
using namespace std;using ll = long long;
const int maxn = 1<<19, mod = 1e9 + 7;
int cur(char i) {
	if(i >= 'A' && i <= 'Z') return 0;
	else if(i >= 'a' && i <= 'z') return 1;
	return 2;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll l, r;
	cin >> l >> r;
	cout << "YES\n";
	while(l+1 <= r) cout << l << " " << l+1 << "\n", l+=2;
}