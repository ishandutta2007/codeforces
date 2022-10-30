#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int f[205];
int g[205];
int ng[205];
int n;

int l[205];
bool bad[205];
vector<int> d[205];

int gl(int i) {
    return i==l[i]?i:l[i]=gl(l[i]);
}

long long gcd(long long a, long long b) {
    if (a==0) return b;
    else return gcd(b%a, a);
}

int main() {
    scanf("%d", &n);
    FO(i,0,n) l[i] = i;
    FO(i,0,n) {
        scanf("%d", f+i);
        f[i]--;
        g[i] = f[i];
        l[gl(i)] = gl(f[i]);
    }
    for (int k = 1; ; k++) {
        int ms = 10;
        FO(i,0,n) if (i == gl(i)) {
            ms = min(ms, sz(d[i]));
            bad[i] = false;
        }
        if (ms >= 3) break;
        FO(i,0,n) if (g[g[i]] != g[i]) {
            bad[gl(i)] = true;
        }
        FO(i,0,n) if (i == gl(i) && !bad[i]) d[i].push_back(k);

        FO(i,0,n) ng[i] = f[g[i]];
        FO(i,0,n) g[i] = ng[i];
    }
    FO(i,0,n) if (i == gl(i)) {
        assert(d[i][1]-d[i][0]==d[i][2]-d[i][1]);
    }

    long long lcm = 1, mn = 0;
    FO(i,0,n) if (i == gl(i)) {
        mn = max(mn,(long long)d[i][0]);
        lcm = (lcm / gcd(lcm,d[i][1]-d[i][0])) * (d[i][1]-d[i][0]);
    }
    long long res = (mn / lcm - 5) * lcm;
    while (res < mn) res += lcm;
    printf("%lld\n", res);
}