#include <bits/stdc++.h>
#define int long long
#define umi(x, y) (x = min(x, y))
#define uma(x, y) (x = max(x, y))
using namespace std;

const int mod = (int)1e9 + 7;

pair<int, int> extgcd(int a, int b) {
   	if(!b) return {1, 0};
    pair<int, int> val = extgcd(b, a % b);
    return {val.second, val.first - (a / b) * val.second};
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	vector<int> fact((int)2e5 + 4);
	fact[0] = 1;
	fact[1] = 1;
	for(int i = 2; i < (int)fact.size(); ++i){
		fact[i] = fact[i - 1] * i % mod;
	}
	auto comb = [&](int n, int r)->int{
		int rv = fact[n];
		rv *= extgcd(fact[r], mod).first + mod; rv %= mod;
		rv *= extgcd(fact[n - r], mod).first + mod; rv %= mod;
		return rv;
	};
	while(t--){
		int n, l, r; cin >> n >> l >> r;
		int ans = 0;
		int u = n / 2, d = n / 2 + n % 2;
		int x = 0, y = n - 1;
		while(x <= y){
			if(!u || !d){
				if(!u){
					ans += min(x + 1 - l, r - x); ans %= mod;
				}
				else{
					ans += min(r - y - 1, y + 2 - l); ans %= mod;
				}
				break;
			}
			if(x + 1 - l >= r - y - 1){
				ans += comb(u + d - 1, u - 1) * (r - y - 1) % mod; ans %= mod;
				--d, --y;
			}
			else{
				ans += comb(u + d - 1, d - 1) * (x + 1 - l) % mod; ans %= mod;
				--u, ++x;
			}
		}
		if(n % 2){
			u = n / 2 + n % 2, d = n / 2;
			x = 0, y = n - 1;
			while(x <= y){
				if(!u || !d){
					if(!u){
						ans += min(x + 1 - l, r - x); ans %= mod;
					}
					else{
						ans += min(r - y - 1, y + 2 - l); ans %= mod;
					}
					break;
				}
				if(x + 1 - l >= r - y - 1){
					ans += comb(u + d - 1, u - 1) * (r - y - 1) % mod; ans %= mod;
					--d, --y;
				}
				else{
					ans += comb(u + d - 1, d - 1) * (x + 1 - l) % mod; ans %= mod;
					--u, ++x;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}