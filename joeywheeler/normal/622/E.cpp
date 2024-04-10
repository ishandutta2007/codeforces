#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

vector<int> u[500005];
int n;
vector<int> t;

void go(int i, int p, int d) {
    int lf = 1;
    for (int j : u[i]) if (j != p) {
        lf = 0;
        go(j, i, d+1);
    }
    if (lf) t.push_back(d);
}

int main() {
    scanf("%d", &n);
    FO(i,0,n-1) {
        int x, y; scanf("%d%d", &x, &y);
        u[x].push_back(y);
        u[y].push_back(x);
    }
    int ans = 0;
    for (int j : u[1]) {
        t.clear();
        go(j,1,1);
        sort(t.begin(),t.end());
        FO(i,1,sz(t)) t[i] = max(t[i],t[i-1]+1);
        ans = max(ans,t.back());
    }
    printf("%d\n", ans);
}