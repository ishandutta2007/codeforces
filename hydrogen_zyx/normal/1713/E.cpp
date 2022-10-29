///
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int inf = 0x3f3f3f3f, N = 2e3 + 9;

int fa[N], fv[N];
int a[N][N];

int fd(int x) {
    if (fa[x] == x)return x;
    int tmp = fd(fa[x]);
    fv[x] ^= fv[fa[x]];
    fa[x] = tmp;
    return fa[x];
}

void unite(int u, int v, bool f) {
    int l = fd(u), r = fd(v);
    if (l == r) return;
    fv[l] = fv[u] ^ fv[v] ^ f;
    fa[l] = r;
}

int main() {
#ifdef ONLINE_JUDGE
    //std::ios::sync_with_stdio(false);
#else
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
//        n = 10;
        for (int i = 1; i <= n; i++) {
            fa[i] = i;
            fv[i] = 0;
            for (int j = 1; j <= n; j++) {
//                a[i][j] = rand();
                scanf("%d", &a[i][j]);
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (a[i][j] == a[j][i])continue;
                else if (a[i][j] < a[j][i]) {
                    unite(i, j, 0);
                } else if (a[i][j] > a[j][i]) {
                    unite(i, j, 1);
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            fd(i);
            if (fv[i]) {
                for (int j = 1; j <= n; j++) {
                    swap(a[i][j], a[j][i]);
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                printf("%d%c", a[i][j], " \n"[j == n]);
            }
        }
    }
    return 0;
}