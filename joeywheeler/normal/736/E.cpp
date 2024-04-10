#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n, m;
int a[3005];
pair<int,int> v[3005]; int vs;
int g[3005][3005];
char u[3005][3005];

bool fn[3005];

int main() {
    scanf("%d %d", &n, &m);
    FO(i,0,m) scanf("%d", a+i);
    int s = 0, p = 6000;
    FO(i,1,n+1) {
        int mx = min(i*(i-1) + (n-i)*i*2 - s, p);
        if (i <= m) {
            if (a[i-1] > mx) {
                printf("no\n");
                return 0;
            }
        } else a[i-1] = mx;
        s += a[i-1];
        p = a[i-1];
    }
    if (s != n*(n-1)) {
        printf("no\n");
        return 0;
    }

    printf("yes\n");
    FO(i,0,n) {
        vs = 0;
        FO(j,0,n) if (!fn[j]) v[vs++] = make_pair(-a[j], j);
        sort(v,v+vs);
        p = v[0].second;
        int o = 2*(n-i-1) - a[p];
        for (int k = 1; k < vs; ) {
            int j;
            FO(z,0,2) for (j = k; j < vs && v[k].first == v[j].first; j++) if (o) {
                a[v[j].second]--;
                g[p][v[j].second]++;
                o--;
            } else g[v[j].second][p]++;
            k = j;
        }
        fn[p] = true;
    }
    FO(i,0,n) FO(j,0,n) u[i][j] = i == j ? 'X' : "WDL"[g[i][j]];
    FO(i,0,n) printf("%s\n", u[i]);
}