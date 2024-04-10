// Hydro submission #61891bdc1edf93b3ad658810@1636375517463
#include <bits/stdc++.h>
using namespace std;

inline int read() {
	int x = 0, f = 0; char c = 0;
	while (!isdigit(c)) f |= c == '-', c = getchar();
	while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return f ? -x : x;
}

#define N 2010
#define pb push_back

int n, low[N], dfn[N], vis[N], cnt = 0, num = 0;
vector<int> e[N];
stack<int> st;

void Tarjan(int x) {
	dfn[x] = low[x] = ++ cnt;
	st.push(x), vis[x] = 1;
	for (auto y : e[x]) {
		if (!dfn[y]) Tarjan(y), low[x] = min(low[x], low[y]);
		else if (vis[y]) low[x] = min(low[x], dfn[y]);
	}
	if (dfn[x] == low[x]) {
		int y; num ++;
		do {
			y = st.top(); st.pop();
			vis[y] = 0;
		} while(y != x);
	}
}

int main() {
	n = read();
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			if (read() && i != j) e[i].pb(j);
		}
	}

	for (int i = 1; i <= n; i ++) {
		if (!dfn[i]) Tarjan(i);
	}

	(num == 1) ? puts("YES") : puts("NO");
	return 0;
}