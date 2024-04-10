#include <bits/stdc++.h>
using namespace std;
#define ever (;;)

multiset<long long> x; long long n, a[3], _;

int main()
{
	cin >> n >> a[0] >> a[1] >> a[2]; sort(a, a+3);
	while (n--) { cin >> _; x.insert(_); }
	if (*x.rbegin() > a[0]+a[1]+a[2]) { printf("-1\n"); return 0; }
	_ = 0;
	while (x.size() && *x.rbegin() > a[1]+a[2])
	{ x.erase(--x.end()); _++; }
	while (x.size() && *x.rbegin() > a[0]+a[2])
	{ x.erase(--x.end()); auto it = x.upper_bound(a[0]); if (it != x.begin()) x.erase(--it); _++; }
	while (x.size() && *x.rbegin() > max(a[0]+a[1], a[2]))
	{ x.erase(--x.end()); auto it = x.upper_bound(a[1]); if (it != x.begin()) x.erase(--it); _++; }
	if (a[0]+a[1] > a[2]) while (x.size() && *x.rbegin() > a[2])
	{ x.erase(--x.end()); auto it = x.upper_bound(a[2]); if (it != x.begin()) x.erase(--it); _++; }
	for ever
	{	auto it = x.upper_bound(a[1]); if (it == x.begin()) break; x.erase(--it);
		it = x.upper_bound(a[0]); if (it != x.begin()) x.erase(--it);
		it = x.upper_bound(a[2]); if (it != x.begin()) x.erase(--it); _++; }
	while (x.size())
	{	auto it = x.upper_bound(a[2]); if (it != x.begin()) x.erase(--it);
		it = x.upper_bound(a[0]+a[1]); if (it != x.begin()) x.erase(--it); _++; }
	cout << _ << "\n";
	return 0;
}