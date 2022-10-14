#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll n, k;
	cin >> n >> k;
	vector<array<ll, 4>> sol;
	int odd = 1;
	for(int even = 2; n; even+=2) {
		if(even%3 == 0) continue;
		n--;
		sol.push_back({even, odd, odd+2, odd+4});
		odd += 6;
	}
	cout << sol.back()[3]*k << endl;
	for(auto i : sol){
		for(auto j : i) cout << j*k << " "; cout << '\n';
		for(int x = 0; x < 4; x++)
			for(int y = 0; y < x; y++) if(__gcd(i[x], i[y])>1) cout << "HERE\n", exit(0);
	}
}