#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <bitset>

#define mp make_pair
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int, int> ii;

template<class T> T abs(T x) { return x > 0 ? x : -x; }
template<class T> T sqr(T x) { return x * x; }

char ts[1100 * 1000];

//int d[30][30];
bool u[30];

int64 C[30][30];
int n;

int nx[1100 * 1000][26];

//int cnt[1 << 26];

int vcnt[26 * 1100 * 1000];
int vsz = 0;

int getNext(int ind, int mask) {
    int res = n;
    for (int i = 0; i < 26; ++i)
        if (!((mask >> i) & 1)) {
            if (res > nx[ind][i]) res = nx[ind][i];
        }
    return res;
}

int main() {    
    /*memset(C, 0, sizeof(C));
    C[0][0] = 1;
    for (int i = 0; i < 30; ++i) {
        C[i][0] = 1;
        for (int j = 1; j < 30; ++j)
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    }*/
//  memset(d, 0, sizeof(d));
    scanf("%s", ts);
    n = strlen(ts);
    ts[n] = 'z' + 1;
    for (int i = 0; i < 26; ++i)
        nx[n][i] = n;
    for (int i = n - 1; i >= 0; --i) {
        memcpy(nx[i], nx[i + 1], sizeof(nx[i + 1]));
        nx[i][ts[i] - 'a'] = i;
    }
    //fprintf(stderr, "Phase 0\n");
    for (int i = 0; i < n; ++i) {
        int prev = i == 0 ? 29 : (ts[i - 1] - 'a');
        int cur = i;
        int cs = 1 << (int)(ts[i] - 'a');
        while (cur < n) {
            if (!((cs >> prev) & 1))
                //++cnt[cs];
                vcnt[vsz++] = cs;
            else
                break;
            //cerr << i << " " << cur << "\n";
            cur = getNext(cur, cs);
            if (cur < n)
                cs |= (1 << (int)(ts[cur] - 'a'));
        }
    }
    //fprintf(stderr, "Phase 1\n");
    sort(vcnt, vcnt + vsz);
    /*for (int i = 0; i < (1 << 26); ++i) {
        for (int j = 0; j < 26; ++j) if ((i >> j) & 1) {
            cnt[i] += cnt[i ^ (1 << j)];
        }
    }*/
    /*for (int i = 0; i < n; ++i)
        d[ts[i] - 'a'][ts[i + 1] - 'a'] += 1;*/
    //fprintf(stderr, "Phase 2\n");
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        scanf("%s", ts);
        int mask = 0;
        for (int j = 0; ts[j]; ++j) {
            mask |= 1 << (int)(ts[j] - 'a');
        }
        /*for (int p = 0; p < 30; ++p) if (u[p])
            for (int q = 0; q < 30; ++q) if (p != q) {
                int64 val = 0;
                for (int t = 1; t <= l; ++t) {
                    int64 cur;
                    if (u[q]) {
                        if (t == l) cur = 0;
                        else cur = C[l - 2][t - 1];
                    } else {
                        cur = C[l - 1][t - 1];
                    }
                    if ((l - t) % 2 == 0) val += cur;
                    else val -= cur;
                }
                res += val * (int64)(d[p][q]);
            }*/
        int res = lower_bound(vcnt, vcnt + vsz, mask + 1) - lower_bound(vcnt, vcnt + vsz, mask);
        printf("%d\n", res);
    }
    return 0;
}