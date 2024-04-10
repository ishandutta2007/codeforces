#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
ll key;
string s, t;
struct ht {
	const static ll p = 1000000007;
	const static ll q = 1000000009;
	ll num1, num2;
	ht operator+(ht ot) {
		return {( (num1 + ot.num1) % p+p)%p,((num2 + ot.num2) % q + q) % q };
	}
	ht operator-(ht ot) {
		return {( (num1 - ot.num1) % p + p) % p,((num2 - ot.num2) % q + q) % q };
	}
	ht operator*(ht ot) {
		return {( (num1 * ot.num1) % p + p) % p,((num2 * ot.num2) % q+q)%q };
	}
	bool operator==(ht ot) {
		return num1 == ot.num1&&num2 == ot.num2;
	}
	bool operator!=(ht ot) {
		return num1 != ot.num1||num2 != ot.num2;
	}
	ht(ll x) {
		num1 = num2 = x;
	}
	ht(ll a, ll b) {
		num1 = a, num2 = b;
	}
	ht() { num1 = num2 = 0; }
};
ht h[1000001];
ht pkey[1000001];
ht has(int a, int b) {
	if (a == 0)return h[b];
	return h[b] - h[a-1] * pkey[b - a+1];
}
bool check(int a, int b) {
	int cur=0;
	ht aa=ht(0), bb= ht(0);
	for (char c : s) {
		if (c == '0') {
			ht ha = has(cur, cur + a - 1);
			if (aa == ht(0))aa = ha;
			else if (aa != ha)return 0;
			cur += a;
		}
		else {
			ht ha = has(cur, cur + b - 1);
			if (bb == ht(0))bb = ha;
			else if (bb != ha)return 0;
			cur += b;
		}
	}
	if (aa == bb)return 0;
	return 1;
}
int main() {
	srand((uintptr_t)make_unique<char>().get());
	key = rand() * 2 + 10001;
	pkey[0] = ht(1);
	int i;
	cin >> s >> t;
	for (i = 1; i < t.size(); i++)pkey[i] = pkey[i - 1] * ht(key);
	h[0] = ht(t[0]);
	for (i = 1; i < t.size(); i++)h[i] = h[i - 1] * ht(key) + ht(t[i]);
	int num0=0, num1=0;
	for (char c : s) {
		if (c == '0')num0++;
		else num1++;
	}
	int ans = 0;
	for (i = 1; num0*i <= t.size(); i++) {
		int b = (t.size() - num0 * i) / num1;
		if (i*num0 + b * num1 != t.size())continue;
		if (b <= 0)continue;
		ans += check(i, b);
	}
	printf("%d", ans);
	getchar(); getchar();
}