#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif

istream &operator>>(istream &in, __int128_t &x){
	char s[40];
	in >> s;
	x = 0;
	for(int i = s[0] == '-'; s[i]; ++ i) x = x * 10 + s[i] - '0';
	if(s[0] == '-') x = -x;
	return in;
}
ostream &operator<<(ostream &out, __int128_t x){
	if(!x) return out << 0;
	if(x < 0) out << "-", x = -x;
	constexpr int block = 1e9;
	array<int, 6> a{};
	int it = 0;
	for(; x; x /= block) a[it ++] = x % block;
	for(-- it; it >= 0; -- it) out << a[it];
	return out;
}
__int128_t abs(__int128_t x){
	return x >= 0 ? x : -x;
}
istream &operator>>(istream &in, __uint128_t &x){
	char s[40];
	in >> s;
	x = 0;
	for(int i = s[0] == '-'; s[i]; ++ i) x = x * 10 + s[i] - '0';
	if(s[0] == '-') x = -x;
	return in;
}
ostream &operator<<(ostream &out, __uint128_t x){
	if(!x) return out << 0;
	constexpr int block = 1e9;
	array<int, 6> a{};
	int it = 0;
	for(; x; x /= block) a[it ++] = x % block;
	for(-- it; it >= 0; -- it) out << a[it];
	return out;
}
__int128_t gcd(__int128_t x, __int128_t y){
	for(x = abs(x), y = abs(y); y; swap(x, y)) x %= y;
	return x;
}
__int128_t lcm(__int128_t x, __int128_t y){
	return x / gcd(x, y) * y;
}
__uint128_t gcd(__uint128_t x, __uint128_t y){
	for(; y; swap(x, y)) x %= y;
	return x;
}
__uint128_t lcm(__uint128_t x, __uint128_t y){
	return x / gcd(x, y) * y;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<int> a(n);
	copy_n(istream_iterator<int>(cin), n, a.begin());
	ranges::sort(a);
	__int128_t num = 0, denom = 1LL * n * (n - 1);
	for(auto i = 0; i < n; ++ i){
		int left = i, right = n - 1 - i;
		num += a[i] * (2LL * left * left - 2LL * right * right + n - 1);
	}
	auto g = gcd(num, denom);
	num /= g, denom /= g;
	cout << num << " " << denom << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////