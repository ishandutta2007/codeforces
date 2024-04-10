#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
template <typename T>
void read(T &x) {
	x = 0; int f = 1; char c = getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-1;
	for (;isdigit(c);c=getchar()) x = (x << 3) + (x << 1) + c - '0';
	x *= f;
}
ll n1, n2, p1, p2;
bool check(ll mid) {
	ll k1 = mid / p1, k2 = mid / p2, k3 = mid / (p1 * p2);
	k1 -= k3, k2 -= k3;
	ll tmp1 = n1 - k2, tmp2 = n2 - k1;
	if (tmp1 < 0) tmp1 = 0;
	if (tmp2 < 0) tmp2 = 0;
	mid = mid - k1 - k2 - k3;
	return tmp1 + tmp2 <= mid;
}
int main() {
	read(n1), read(n2), read(p1), read(p2);
	ll l = n1 + n2, r = l * 2 + 1;
	while (l <= r) {
		ll mid = (l + r) >> 1;
		if (check(mid)) r = mid - 1;
		else l = mid + 1;
	}
	cout << l << endl;
	return 0;
}