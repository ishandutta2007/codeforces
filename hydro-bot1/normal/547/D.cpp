// Hydro submission #6190ff0a01410992b6875d72@1636892426899
#include <bits/stdc++.h>
using namespace std;

inline int read() {
	int x = 0, f = 0; char c = 0;
	while (!isdigit(c)) f |= c == '-', c = getchar();
	while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return f ? -x : x;
}

#define N 200010
#define pb push_back

int n, c[N], u[N], v[N];
vector<int> e[N];

void dfs(int x, int col) {
    c[x] = col;
    for (auto y : e[x]) {
        if (!c[y]) dfs(y, 3 - col);
    }
}

int main() {
    n = read();

    for (int i = 1; i <= n; i ++) {
        int x = read(), y = read();
        if (u[x]) {
            e[u[x]].pb(i), e[i].pb(u[x]), u[x] = 0;
        } else u[x] = i;
        if (v[y]) {
            e[v[y]].pb(i), e[i].pb(v[y]), v[y] = 0;
        } else v[y] = i;
    }

    for (int i = 1; i <= n; i ++) {
        if (!c[i]) dfs(i, 1);
    }

    for (int i = 1; i <= n; i ++) {
        (c[i] == 1)? printf("r") : printf("b");
    }
    return puts(""), 0;
}