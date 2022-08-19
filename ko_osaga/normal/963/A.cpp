#include <bits/stdc++.h>
const int MAXN = 100005;
const int mod = 1e9 + 9;
using namespace std;
using lint = long long;
using pi = pair<int, int>;

lint ipow(lint x, lint p){
	lint ret = 1, piv = x;
	while(p){
		if(p & 1) ret = ret * piv % mod;
		piv = piv * piv % mod;
		p >>= 1;
	}
	return ret;
}

lint n, a, b, k;
char s[MAXN];

lint sum(lint x, int t){
	if(t == 0) return 1;
	if(t % 2 == 0) return (sum(x, t - 1) + ipow(x, t)) % mod;
	else return (ipow(x, t / 2 + 1) + 1) * sum(x, t / 2) % mod;
}

int main(){
	cin >> n >> a >> b >> k;
	scanf("%s", s);
	lint ret = 0;
	lint den = b * ipow(a, mod - 2) % mod;
	for(int i=0; i<k && i<=n; i++){
		int t = (n - i) / k;
		lint tmp = sum(ipow(den, k), t) * ipow(den, i) % mod;
		if(s[i] == '+') ret += tmp;
		else ret += mod - tmp;
		ret %= mod;
	}
	ret *= ipow(a, n);
	ret %= mod;
	cout << ret << endl;
}