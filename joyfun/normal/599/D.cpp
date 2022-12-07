#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N = 100005;
const int INF = 0x3f3f3f3f;
ll x;
#define mp(a,b) make_pair(a,b)

vector<pair<long long, long long> > ans;

int main() {
	scanf("%lld", &x);
	for (ll i = 1; i * i * i - i <= x * 6; i++) {
		ll sb = x;
		sb -= i * (i - 1) * (2 * i - 1) / 6;
		sb += i * (i - 1) * i / 2;
		if (sb <= 0) continue;
		ll tmp = (i * i + i) / 2;
		if (sb % tmp) continue;
		ll m = sb / tmp;
		if (i > m) break;
		ans.push_back(mp(i, m));
		if (i != m) ans.push_back(mp(m, i));
	}
	sort(ans.begin(), ans.end());
	printf("%d\n", (int)ans.size());
	for (int i = 0; i < ans.size(); i++)
		printf("%lld %lld\n", ans[i].first, ans[i].second);
	return 0;
}