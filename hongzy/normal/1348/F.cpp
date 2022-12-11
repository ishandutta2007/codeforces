#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const int N = 2e5 + 10;
struct Node {
	int l, r, id;
	bool operator < (const Node &b) {
		return r < b.r;
	}
} a[N];
int n, fir[N], sec[N], nxt[N], p1[N], p2[N], le[N];
vector<int> G[N]; 
set<int> S;
bool res[N];
int ans[N];
int Minl(int u) {
	if(res[u]) return ans[u];
	ans[u] = le[u]; res[u] = 1;
	if(nxt[u] == -1) return ans[u];
	return ans[u] = min(ans[u], Minl(nxt[u]));
}
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		scanf("%d%d", &a[i].l, &a[i].r); a[i].id = i;
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i ++) S.insert(i);
	for(int i = 1; i <= n; i ++) {
		set<int>::iterator it = S.lower_bound(a[i].l);
		fir[i] = *it; sec[i] = -1; it ++;
		if(it != S.end() && *it <= a[i].r) sec[i] = *it;
		p1[a[i].id] = fir[i]; S.erase(fir[i]);
		nxt[fir[i]] = sec[i];
		le[fir[i]] = a[i].l;
	}
	copy(p1 + 1, p1 + n + 1, p2 + 1);
	bool tag = 0;
	for(int i = 1; i <= n; i ++) {
		set<int>::iterator it = S.lower_bound(a[i].l);
		if(it != S.end()) {
			p2[a[i].id] = *it; tag = 1; break ;
		}
	}
	if(tag) {
		puts("NO");
		for(int i = 1; i <= n; i ++) printf("%d%c", p1[i], " \n"[i == n]);
		for(int i = 1; i <= n; i ++) printf("%d%c", p2[i], " \n"[i == n]);
		return 0;
	}
	int pos = 0;
	for(int i = 1; i <= n; i ++) {
		if(~ sec[i] && Minl(sec[i]) <= fir[i]) {
			pos = i; break ;
		}
	}
	if(!pos) {
		puts("YES");
		for(int i = 1; i <= n; i ++) printf("%d%c", p1[i], " \n"[i == n]);
		return 0;
	}
	S.clear();
	for(int i = 1; i <= n; i ++) S.insert(i);
	for(int i = 1; i <= n; i ++) {
		set<int>::iterator it = S.lower_bound(a[i].l);
		fir[i] = *it; sec[i] = -1; it ++;
		if(it != S.end()) sec[i] = *it;
		if(pos == i) {
			p2[a[i].id] = sec[i]; S.erase(sec[i]);
		} else {
			p2[a[i].id] = fir[i]; S.erase(fir[i]);
		}
	}
	puts("NO");
	for(int i = 1; i <= n; i ++) printf("%d%c", p1[i], " \n"[i == n]);
	for(int i = 1; i <= n; i ++) printf("%d%c", p2[i], " \n"[i == n]);
	return 0;
}