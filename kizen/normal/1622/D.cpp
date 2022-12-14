#include <bits/stdc++.h>
#define int long long
#define mi(x, y) (x = min(x, y))
#define ma(x, y) (x = max(x, y))
using namespace std;

const int NS = 5004;
int fact[NS], inv[NS], mod = 998244353;

int pw(int x, int y, int md){
    if(!y) return 1;
    if(y % 2) return pw(x, y - 1, mod) * x % md;
    int val = pw(x, y / 2, md);
    return val * val % md;
}

int ncr(int n, int r){
    if(!fact[0]){
        for(int i = 0; i < NS; ++i){
            if(!i) fact[i] = 1;
            else fact[i] = i * fact[i - 1] % mod;
        }
        inv[NS - 1] = pw(fact[NS - 1], mod - 2, mod);
        for(int i = NS - 2; i >= 0; --i){
            inv[i] = inv[i + 1] * (i + 1) % mod;
        }
    }
    return fact[n] * inv[r] % mod * inv[n - r] % mod;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	string s; cin >> s;
	int ans = 0;
	vector<int> cl(n), cr(n);
	for(int i = 0; i < n; ++i){
		if(i) cl[i] = cl[i - 1];
		cl[i] += (s[i] == '1');
	}
	for(int i = n - 1; i >= 0; --i){
		if(i + 1 < n) cr[i] = cr[i + 1];
		cr[i] += (s[i] == '1');
	}
	vector<int> c(n + 1);
	c[1] = 1;
	for(int i = 2; i <= n; ++i){
		for(int j = 2; j <= i; ++j){
			if(j % 2 ^ i % 2){
				c[i] = (c[i] + ncr(i - 2, j - 2)) % mod;
			}
			else{
				c[i] = (c[i] - ncr(i - 2, j - 2) + mod) % mod;
			}
		}
	}
	for(int i = k; i >= 0; --i){
		int r = -1, cnt = 0;
		for(int l = 0; l < n;){
			while(r + 1 < n && cnt < i){
				++r;
				cnt += (s[r] == '1');
			}
			if(cnt < i) break;
			while(r + 1 < n && s[r + 1] == '0') ++r;
			if((l ? cl[l - 1] : 0) >= k - i && (r + 1 < n ? cr[r + 1] : 0) >= k - i){
				ans = (ans + (ncr(r - l + 1, i) + mod - 1) * c[k - i + 1] % mod) % mod;
			}
			while(l + 1 < n && s[l] == '0') ++l;
			--cnt; ++l;
		}
	}
	ans = (ans + 1) % mod;
	cout << ans << '\n';
	return 0;
}