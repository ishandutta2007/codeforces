#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
const int maxn = 1<<21, mod = 1e9 + 7;
int n;
vector<pair<char, int>> op;
int apply(int x) {
	for(auto i : op) {
		if(i.first == '^') x ^= i.second;
		if(i.first == '&') x &= i.second;
		if(i.first == '|') x |= i.second;
	}
	return x;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	op.resize(n);
	for(auto &i : op) cin >> i.first >> i.second;
	int o = 0, xr = 0, a = (1<<10) - 1;
	for(int i = 0; i < 10; i++) {
		int x = (apply(0)>>i)&1, y = (apply(1<<i)>>i)&1; 
		if(x == 0 && y == 0) a ^= 1<<i;
		if(x == 1 && y == 0) xr ^= 1<<i;
		if(x == 1 && y == 1) o ^= 1<<i;
	}
	cout << "3\n";
	cout << "| " << o << '\n';
	cout << "^ " << xr << '\n';
	cout << "& " << a << '\n';
}