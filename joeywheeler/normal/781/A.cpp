#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

vector<int> u[200005];
int c[200005];
set<int> s[200005]; int us[200005];
int n;
int mx;

void sc(int i, int cl) {
    mx = max(mx,cl);
    c[i] = cl;
    s[i].insert(cl);
    for (int j : u[i]) s[j].insert(cl);
}

void go(int i, int p) {
    while (s[p].count(++us[p]));
    sc(i, us[p]);
    for (int j : u[i]) if (j != p) go(j, i);
}

int main() {
    scanf("%d", &n);
    FO(i,0,n-1) {
        int x, y;
        scanf("%d %d", &x, &y);
        u[x].push_back(y);
        u[y].push_back(x);
    }
    go(1,0);
    printf("%d\n", mx);
    FO(i,1,n+1) printf("%d%c", c[i], " \n"[i==n]);
}