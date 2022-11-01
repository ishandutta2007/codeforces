#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n, m, k;

vector<int> u[200005];
int o[400005], oi;
bool s[200005];

void go(int i, int p) {
    s[i] = true;
    o[oi++] = i;
    for (int j : u[i]) if (!s[j]) {
        go(j, i);
        o[oi++] = i;
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    FO(i,0,m) {
        int x, y; scanf("%d %d", &x, &y);
        u[x].push_back(y);
        u[y].push_back(x);
    }
    go(1,0);
    int l = (2*n+k-1)/k;
    int j = 0;
    FO(i,0,k) {
        vector<int> v;
        FO(t,0,l) {
            v.push_back(o[j++]);
            if (j == oi) break;
        }
        if (j == oi) j = 0;
        printf("%d", sz(v));
        for (int x : v) printf(" %d", x);
        printf("\n");
    }
}