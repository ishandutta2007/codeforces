#include <bits/stdc++.h>
using namespace std;

const int N = 5005;

int n, t[N], g[N];

int Find (int a) {
    return a == g[a] ? a : g[a] = Find(g[a]);
}

void Union (int a, int b) {
    g[Find(a)] = Find(b);
}

int main () {

	int ti;
	scanf("%d", &ti);
	while (ti--) {
        iota(g, g+N-2, 0);

		scanf("%d", &n);

        bool ok = false;
        for (int i = 0; i < n; i++) {
            scanf("%d", &t[i+1]);
            
            if (i > 0 and t[i+1] != t[i])
                ok = true;
        }

        if (!ok) {
            printf("NO\n");
            continue;
        }

        printf("YES\n");
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (t[i] != t[j] and Find(i) != Find(j)) {
                    Union(i, j);
                    printf("%d %d\n", i, j);
                } 
            }
        }
    }

	return 0;
}