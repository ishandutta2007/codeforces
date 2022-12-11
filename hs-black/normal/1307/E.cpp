#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#define ll long long
using namespace std;

template <typename T>
void read(T &x) {
    x = 0; bool f = 0;
    char c = getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=1;
    for (;isdigit(c);c=getchar()) x=x*10+(c^48);
    if (f) x=-x;
}

template <typename T>
void write(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x >= 10) write(x / 10);
    putchar('0' + x % 10);
}

const int N = 5005;
const int P = 1e9+7;
ll mi[N], n, m;
int cnt[N], col[N];
map<pair<int, int>, int> Mp;

#define MP make_pair
int vis[N], qaq[N], pap[N];
int s[N];
vector<int> A[N], B[N];
int main() {
	mi[0] = 1;
	for (int i = 1;i <= 5000; i++) mi[i] = (mi[i-1] << 1) % P;
	read(n), read(m);
	for (int i = 1;i <= n; i++) read(col[i]);
	for (int i = 1;i <= m; i++) {
		int f; read(s[i]), read(f);
		Mp[MP(s[i], f)] = i;
	}
	for (int i = 1;i <= n; i++) {
		cnt[col[i]]++;
		pair<int, int> tmp = MP(col[i], cnt[col[i]]);
		if (Mp.find(tmp) != Mp.end()) A[col[i]].push_back(i), qaq[i] = Mp[tmp], vis[i] = 1;
	}
	memset(cnt, 0, sizeof(cnt));
	for (int i = n;i >= 1; i--) {
		cnt[col[i]]++;
		pair<int, int> tmp = MP(col[i], cnt[col[i]]);
		if (Mp.find(tmp) != Mp.end()) B[col[i]].push_back(i), pap[Mp[tmp]] = i;
	}
	
	vis[0] = 1;
	ll ans = 0, cnt = 0;
	for (int i = 0;i <= n; i++) {
		if (!vis[i]) continue;
		ll mx = 1, res = 1;
		if (i == 0) mx--;
		for (int j = 1;j <= n; j++) {
			int cnt1 = 0, cnt2 = 0;
			for (int k = A[j].size()-1; ~k; --k) 
				if (A[j][k] < i && j != s[qaq[i]]) cnt1++;
			for (int k = B[j].size()-1; ~k; --k)
				if (B[j][k] > i && pap[qaq[i]] != B[j][k]) cnt2++;
			if (cnt1 < cnt2) swap(cnt1, cnt2);
			if (cnt2 == 1) {
				if (cnt1 <= 1) mx++, res = res * 2 % P;
				else mx += 2, res = res * (cnt1 - 1) % P;
			}
			else if (cnt2 == 0 && cnt1 > 0) mx++, res = res * cnt1 % P;
			else if (cnt2 > 1) mx += 2, res = res * cnt2 % P * (cnt1 - 1) % P;
		}
		if (mx > ans) ans = mx, cnt = res;
		else if (mx == ans) (cnt += res) %= P;
	}
	cout << ans << ' ' << cnt << endl;
	return 0;
}