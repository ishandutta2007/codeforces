#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2005;
char a[25], b[25], s[25];
int n, u[N], v[N];
map<string, int> h;
int hn;
string to[N];

int get(char *s) {
    if (!h.count(s)) h[s] = ++hn;
    return h[s];
}

int du[N];
int vis[N];
int ans[N];
int vi[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s%s", a, b);
        s[0] = a[0]; s[1] = a[1]; s[2] = a[2]; s[3] = 0;
        u[i] = get(s);
        to[u[i]] = s;
        s[2] = b[0];
        v[i] = get(s);
        to[v[i]] = s;
        du[u[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        if (du[u[i]] > 1) {
            if (vis[v[i]]) {
                printf("NO\n");
                return 0;
            }
            ans[i] = v[i];
            vis[v[i]] = 1;
        }
    }
    while (1) {
        int f = 1;
        for (int i = 1; i <= n; i++) {
            if (vi[i]) continue;
            if (!vis[u[i]] && !vis[v[i]]) continue;
            if (du[u[i]] != 1) continue;
            f = 0;
            if (du[u[i]] == 1) {
                if (vis[u[i]] && vis[v[i]]) {
                    printf("NO\n");
                    return 0;
                }
                if (vis[u[i]]) {
                    ans[i] = v[i];
                    vis[v[i]] = 1;
                    vi[i] = 1;
                }
            }
        }
        if (f) break;
    }
    for (int i = 1; i <= n; i++) {
        if (vi[i]) continue;
        if (du[u[i]] != 1) continue;
        ans[i] = u[i];
    }
    printf("YES\n");
     for (int i = 1; i <= n; i++) {
        printf("%s\n", to[ans[i]].c_str());
    }
    return 0;
}