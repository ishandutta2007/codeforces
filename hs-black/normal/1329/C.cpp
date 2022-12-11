#include <queue>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
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

const int N = 8005000;
int sum[N], val[N], an, ag, n, g;

#define ls x << 1
#define rs ls | 1
bool can(int x) {
	if (!val[x]) return 0;
	if (x > ag) return 1;
	if (val[ls] > val[rs]) return can(ls);
	return can(rs);
}

void work(int x) {
	if (!val[ls] && !val[rs]) 
		return val[x] = 0, void();
	if (val[ls] > val[rs]) {
		val[x] = val[ls];
		return work(ls);
	}
	val[x] = val[rs]; return work(rs);
}

int main() {
	int T; read(T);
	while (T--) {
		vector<int> q;
		read(n), read(g);
		an = (1 << n) - 1, ag = (1 << g) - 1;
		for (int i = 1;i <= an; i++) read(val[i]);
		for (int i = an + 1;i <= an * 4; i++) val[i] = 0; 
		for (int i = 1;i <= an; i++) while (can(i)) work(i), q.push_back(i);
		ll ans = 0;
		for (int i = 1;i <= ag; i++) ans += val[i];
		printf ("%lld\n", ans);
		for (auto j: q) printf ("%d ", j);
		printf ("\n");
	}
	return 0;
}