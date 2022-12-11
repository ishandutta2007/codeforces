#include <iostream>
#include <cmath>

typedef long long LL;

LL n, k, s, dok[200010];

int main() {
	std :: ios :: sync_with_stdio(false);
	std :: cin >> n >> k >> s;
	LL max_ = (n - 1) * 1ll * k;
	if(max_ < s || s < k) {
		std :: cout << "NO" << std :: endl;
		return 0;
	}
	std :: cout << "YES" << std :: endl;
	for(int i=1; i<=k; i++)
		dok[i] = 1;
	s -= k;
	for(int i=1; i<=k; i++) {
		if(s == 0) break;
		if(s <= n - 2) {
			dok[i] += s;
			s = 0;
			break;
		}
		s -= n - 2;
		dok[i] = n - 1;
	}

	LL now = 1;
	bool r = true;
	for(int i=1; i<=k; i++, r ^= 1) {
		if(r) now += dok[i];
		else now -= dok[i];
		if(now < 1 || now > n) 0 / 0;
		if(i < k) std :: cout << now << ' ';
		else std :: cout << now << std :: endl;
	}
	return 0;
}
/*
9 9 9 9 1 1 1 1 5

*/