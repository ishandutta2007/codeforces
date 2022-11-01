#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

int len[1000005];
int ls[1000005];

ll b;
int n;
ll s[2000005];
ll cs[2000005];
ll T;

void build_cover() {
    int p = 0;
    FO(i,0,n) {
        while (p < 2*n && cs[p+1]-cs[i] <= b) p++;
        len[i] = p-i;
    }
}

int solve() {
    if (len[0] >= n) return 1;

    int res = 1e9;
    FO(i,0,n) ls[i] = 0;
    FO(i,0,n) {
        int X = i+1, c = i;
        while (ls[c] == 0) {
            ls[c] = X;
            c = (c+len[c])%n;
        }
        if (ls[c] != X) continue;
        int p = c, q = c, cl = 0, r = 0;
        do {
            while (cl < n) {
                cl += len[q];
                q = (p+cl)%n;
                r++;
            }
            res = min(res, r);
            cl -= len[p];
            p = (p+len[p])%n;
        } while (p != c);
    }

    return res;
}

void input() {
    scanf("%d", &n);
    int q; scanf("%d", &q);
    FO(i,0,n) scanf("%lld", s+i);
    FO(i,0,n) s[i+n] = s[i];
    FO(i,1,2*n+1) {
        cs[i] = cs[i-1] + s[i-1];
    }
    T = cs[n];
    FO(Z,0,q) {
        scanf("%lld", &b);
        build_cover();
        printf("%d\n", solve());
    }
}

int main() {
    input();
}