#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
#include <map>
using namespace std;

int n;
long long l[30], m[30], w[30];

map<pair<long long, long long> , int> sb;
map<pair<long long, long long>, int> fuck;
set<pair<long long, long long> > S;

void dfs(int u, int s, long long a, long long b, long long c) {
    if (u == n / 2) {
        b -= a;
        c -= a;
        S.insert(make_pair(b, c));
        if (sb.count(make_pair(b, c))) {
            if (fuck[make_pair(b, c)] < a) {
                sb[make_pair(b, c)] = s;
                fuck[make_pair(b, c)] = a;
            }
        } else {
            sb[make_pair(b, c)] = s;
            fuck[make_pair(b, c)] = a;
        }
        return;
    }
    dfs(u + 1, s * 3, a + l[u], b + m[u], c);
    dfs(u + 1, s * 3 + 1, a + l[u], b, c + w[u]);
    dfs(u + 1, s * 3 + 2, a, b + m[u], c + w[u]);
}

int ans[105];
int flag = 0;
long long Max = -1000000000000000LL;

void dfs2(int u, int s, long long a, long long b, long long c) {
    if (u == n) {
        b -= a;
        c -= a;
        if (S.find(make_pair(-b, -c)) != S.end()) {
            flag = 1;
            if (Max < a + fuck[make_pair(-b, -c)]) {
                Max = a + fuck[make_pair(-b, -c)];
                int cao = sb[make_pair(-b, -c)];
                for (int i = 0; i < n / 2; i++) {
                    ans[n / 2 - i - 1] = cao % 3;
                    cao /= 3;
                }
                for (int i = n / 2; i < n; i++) {
                    ans[n - i + n / 2 - 1] = s % 3;
                    s /= 3;
                }
            }
           /* long long aa = 0, bb = 0, cc = 0;
            for (int i = 0; i < n; i++) {
             //       printf("%lld %lld %lld\n", l[i], m[i], w[i]);
                if (ans[i] == 0) {
                    aa += l[i];
                    bb += m[i];
                    printf("LM\n");
                }
                if (ans[i] == 1) {
                    aa += l[i];
                    cc += w[i];
                    printf("LW\n");
                }
                if (ans[i] == 2) {
                    bb += m[i];
                    cc += w[i];
                    printf("MW\n");
                }
            }
           // printf("%lld %lld %lld\n", aa, bb, cc);*/
        }
        return;
    }
    dfs2(u + 1, s * 3, a + l[u], b + m[u], c);
    dfs2(u + 1, s * 3 + 1, a + l[u], b, c + w[u]);
    dfs2(u + 1, s * 3 + 2, a, b + m[u], c + w[u]);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld%lld", &l[i], &m[i], &w[i]);
    }
    dfs(0, 0, 0, 0, 0);
    dfs2(n / 2, 0, 0, 0, 0);
    if (flag) {
        for (int i = 0; i < n; i++) {
             //       printf("%lld %lld %lld\n", l[i], m[i], w[i]);
                if (ans[i] == 0) {

                    printf("LM\n");
                }
                if (ans[i] == 1) {

                    printf("LW\n");
                }
                if (ans[i] == 2) {

                    printf("MW\n");
                }
            }
    } else printf("Impossible\n");
    return 0;
}