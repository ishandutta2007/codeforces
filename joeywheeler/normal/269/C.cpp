#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

vector<pair<int,int> > u[200005];
int p[200005], pi;
int l[200005];
int s[200005], t[200005];
int n, m;

int main() {
    scanf("%d %d", &n, &m);
    FO(i,0,m) {
        int x,y,c; scanf("%d%d%d", &x, &y, &c);
        u[x].emplace_back(y,c);
        u[y].emplace_back(x,c);
        s[x] += c; s[y] += c;
    }
    s[n] = -1; s[1] = -1;
    p[pi++] = 1;
    FO(i,0,pi) {
        int f = p[i];
        for (auto e : u[f]) {
            int g, c; tie(g,c) = e;
            t[g] += c;
            if (t[g]*2 == s[g]) {
                p[pi++] = g;
            }
        }
    }
    p[pi++] = n;
    FO(i,0,n) l[p[i]] = i;
    rewind(stdin);
    scanf("%d %d", &n, &m);
    FO(i,0,m) {
        int x,y,c; scanf("%d%d%d", &x, &y, &c);
        printf("%d\n", l[x]>l[y]);
    }
}