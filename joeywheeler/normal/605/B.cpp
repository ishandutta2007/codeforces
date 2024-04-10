#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

struct e {
    int ind;
    int a, b;
    int x, y;

    bool operator<(e o) const {
        if (a == o.a) return b > o.b;
        else return a < o.a;
    }
};

bool cmp(e a, e b) {
    return a.ind < b.ind;
}

int n, m;
e g[100005];
vector<int> c[100005];
int x[100005], y[1000005], tr;
set<int> comps;

int main() {
    scanf("%d%d", &n, &m);
    FO(i,0,m) {
        scanf("%d %d", &g[i].a, &g[i].b);
        g[i].ind = i;
    }
    FO(i,0,n) c[i].push_back(i), comps.insert(i);
    sort(g,g+m);
    FO(i,0,m) {
        auto &ed = g[i];
        if (ed.b == 0) {
            if (tr == 0) {
                printf("-1\n");
                return 0;
            }
            ed.x = x[tr-1], ed.y = y[tr-1]; tr--;
        } else {
            int a = *comps.begin();
            comps.erase(a);
            int b = *comps.begin();
            comps.erase(b);
            if (sz(c[b]) < sz(c[a])) swap(a,b);
            ed.x = a; ed.y = b;
            for (int X : c[a]) {
                if (tr >= m+2) break;
                for (int Y : c[b]) {
                    if (tr >= m+2) break;
                    if (X != a || Y != b) {
                        x[tr] = X;
                        y[tr] = Y;
                        tr++;
                    }
                }
            }
            for (int X : c[a]) {
                c[b].push_back(X);
            }
            c[a].clear();
            comps.insert(b);
        }
    }
    sort(g,g+m,cmp);
    FO(i,0,m) printf("%d %d\n", g[i].x+1, g[i].y+1);
}