#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	const ll MOD = 998244353;
	vector<ll> exp{1};
	for(int i = 1; i <= 19; i ++){
		exp.push_back(exp.back() * 10);
		exp.back() %= MOD;
	}
	int n;
	cin >> n;
	vector<string> s(n);
	for(auto &x: s){
		cin >> x;
	}
	auto cmp = [](string &A, string &B){
		return A.size() < B.size();
	};
	sort(s.begin(), s.end(), cmp);
	vector<ll> size(n);
	for(int i = 0; i < n; i ++){
		size[i] = s[i].size();
	}
	vector<ll> sum{0};
	for(auto x: size){
		sum.push_back(exp[x] + sum.back());
		sum.back() %= MOD;
	}
	ll res = 0;
	for(int i = 0; i < n; i ++){
		for(int digit = 0; digit < size[i]; digit ++){
			auto temp = equal_range(size.begin(), size.end(), digit);
			int p = temp.first - size.begin(), q = temp.second - size.begin();
			res += (s[i][size[i] - digit - 1] - '0') * (sum[p] + sum[q] * 10);
			res %= MOD;
			res += (n - p) * exp[2 * digit] % MOD * (s[i][size[i] - digit - 1] - '0');
			res %= MOD;
			res += (n - q) * exp[2 * digit + 1] * (s[i][size[i] - digit - 1] - '0');
			res %= MOD;
		}
	}
	cout << res;
	return 0;
}