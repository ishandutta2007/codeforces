#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MOD = 998244353;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int w, h;
	cin >> w >> h;
	ll res = 4;
	for(int i = 2; i <= w; i ++){
		(res *= 2) %= MOD;
	}
	for(int j = 2; j <= h; j ++){
		(res *= 2) %= MOD;
	}
	cout << res;
	return 0;
}