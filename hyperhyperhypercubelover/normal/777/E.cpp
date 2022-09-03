#include <cstdio>
#include <algorithm>

using namespace std;

pair<pair<int, int>, int> a[100001];
pair<int, long long> s[100001];
int sn;

int main() {
	long long t, r = 0;
	int i, j, n;
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d%d%d", &a[i].first.first, &a[i].first.second, &a[i].second);
	sort(a, a + n, [](auto &u, auto &v) { return u.first.second == v.first.second ? u.first.first > v.first.first : u.first.second > v.first.second; });
	for (i = 0; i < n; i++) {
		while (s[sn].first >= a[i].first.second) sn--;
		t = s[sn].second + a[i].second;
		if (t > r) r = t;
		while (s[sn].first >= a[i].first.first) sn--;
		sn++;
		s[sn].first = a[i].first.first;
		s[sn].second = t;
	}
	printf("%lld", r);
}