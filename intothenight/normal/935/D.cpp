#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	const int MOD = 1e9 + 7;
	int n, m;
	cin >> n >> m;
	vector<int> s1(n), s2(n);
	for(auto &x: s1){
		cin >> x;
	}
	for(auto &x: s2){
		cin >> x;
	}
	auto product = [&](pll p, pll q){
		ll n = p.first * q.first, d = p.second * q.second, g = gcd(n, d);
		return pll{n / g % MOD, d / g % MOD};
	};
	auto sum = [&](pll p, pll q){
		ll n = p.first * q.second + p.second * q.first, d = p.second * q.second, g = gcd(n, d);
		return pll{n / g % MOD, d / g % MOD};
	};
	auto inv = [&](ll x){
		int e = MOD - 2;
		ll res = 1;
		while(e){
			if(e & 1){
				(res *= x) %= MOD;
			}
			(x *= x) %= MOD;
			e >>= 1;
		}
		return res;
	};
	pll p{0, 1}, q{1, 1};
	for(int i = 0; i < n; i ++){
		pll np, nq;
		if(!s1[i] && !s2[i]){
			np = sum(p, product(q, pll(m - 1, 2 * m)));
			nq = product(q, pll(1, m));
		}
		else if(!s1[i] && s2[i]){
			np = sum(p, product(q, pll(m - s2[i], m)));
			nq = product(q, pll(1, m));
		}
		else if(s1[i] && !s2[i]){
			np = sum(p, product(q, pll(s1[i] - 1, m)));
			nq = product(q, pll(1, m));
		}
		else if(s1[i] > s2[i]){
			np = sum(p, q);
			nq = pll(0, 1);
		}
		else if(s1[i] == s2[i]){
			np = p;
			nq = q;
		}
		else{
			np = p;
			nq = pll(0, 1);
		}
		p = np, q = nq;
	}
	cout << p.first * inv(p.second) % MOD << "\n";
	return 0;
}