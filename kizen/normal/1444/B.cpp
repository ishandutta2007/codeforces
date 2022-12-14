#include <bits/stdc++.h>

using namespace std;

using LL = long long;
const LL MOD = (LL)998244353;
const LL NS = (LL)300004;
LL N;
LL a[NS];

pair<LL, LL> extgcd(LL a, LL b){
    if(b == 0) return make_pair(a, b);
    pair<LL, LL> gap = extgcd(b, a % b);
    return make_pair(gap.second, gap.first - (a / b) * gap.second);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	N *= 2;
	for(LL i = 1; i <= N; ++i){
		cin >> a[i];
	}
	sort(a + 1, a + N + 1);
	LL sum = 0;
	for(LL i = N / 2 + 1; i <= N; ++i){
		sum += a[i];
	}
	for(LL i = 1; i <= N / 2; ++i){
		sum -= a[i];
	}
	for(LL i = 1; i <= N; ++i){
		sum = sum * i % MOD;
	}
	for(LL i = 1; i <= N / 2; ++i){
		LL val = (extgcd(i, MOD).first + MOD) % MOD;
		sum = sum * val % MOD * val % MOD;
	}
	cout << sum;
	return 0;
}