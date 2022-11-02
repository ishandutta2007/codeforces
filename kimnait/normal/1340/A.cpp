#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define SZ(x) ((int)(x).size())
#define MP  make_pair
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
const int mod = 998244353;
const int N = (int)1e6 + 7;
const long double PI = acos(-1);
int cnt[N], a[N];
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		for (int i = 1; i <= n; i++) 
			scanf("%d", a + i);
		set<int> st;
		set<PII> st2;
		for (int i = 1; i <= n; i++) {
			st.insert(i);
			st2.insert(MP(1, i));
			cnt[i] = 1;
		}
		bool ok = true;
		for (int i = 1; i <= n; i++) {
			int v = a[i];
			PII x = *(--st2.end());
			if (x.F == cnt[v]) {
				st2.erase(MP(cnt[v], v));
				st.erase(v);
				auto it = st.lower_bound(v);
				if (it != st.end()) {
					int u = *it;
					st2.erase(MP(cnt[u], u));
					cnt[u] += cnt[v];
					st2.insert(MP(cnt[u], u));
				}
			} else {
				ok = false;
				break ;
			}
		}
		puts(ok ? "Yes" : "No");
	}
	return 0;
}