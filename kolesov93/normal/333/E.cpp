#include <iostream>
#include <stdio.h>
#include <math.h>
#include <memory.h>
#include <algorithm>
#include <stdlib.h>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <string.h>
#include <string>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

inline int sqr(int x) {
    return x * x;
}

const int N = 3333;
pair<int, int> a[N];
int dist[N][N];
vector<int> D;

int ls[N], rs[N], lcnt, rcnt;

inline int mul(int i, int j, int k) {
    return (a[i].first - a[k].first) * (a[j].second - a[k].second) - (a[j].first - a[k].first) * (a[i].second - a[k].second);
}


int b[N], cnt;
int calc() {
    if (cnt < 2) return -1;
    if (cnt <= 10) {
        int ans = 0;
        for (int i = 0; i < cnt; ++i)
            for (int j = i + 1; j < cnt; ++j)
                ans = max(ans, dist[ b[i] ][ b[j] ]);
        return ans;
    }

    memcpy(b + cnt, b, sizeof(int) * cnt);
    int ans = 0;
    int p = 0;
    int lim = cnt + cnt;
    for (int i = 0; i < cnt; ++i) {
        while (p + 1 < lim && dist[ b[i] ][ b[p] ] < dist[ b[i] ][ b[p + 1] ]) ++p;

        int l1 = max(p - 2, 0), l2 = min(p + 2, lim - 1);
        for (int j = l1; j <= l2; ++j) ans = max(ans, dist[ b[i] ][ b[j] ]);
    }

    return ans;
}

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a[i].first, &a[i].second);
    }
    sort(a, a + n);
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j) {
            dist[i][j] = dist[j][i] = sqr(a[i].first - a[j].first) + sqr(a[i].second - a[j].second);
            D.push_back(dist[i][j]);
        }
    sort(D.begin(), D.end());
    D.resize(unique(D.begin(), D.end()) - D.begin());

    int L = 0, R = D.size();
    while (L + 1 < R) {
        int mid = (L + R) >> 1;
        int d = D[mid];
        
        bool cool = false;
        for (int c = 0; c < n; ++c) {
            lcnt = rcnt = 0; 

            for (int i = 0; i < n; ++i)
                if (dist[i][c] >= d) {
                    while (lcnt > 1 && mul(ls[lcnt - 1], i, ls[lcnt - 2]) <= 0) --lcnt;   
                    while (rcnt > 1 && mul(rs[rcnt - 1], i, rs[rcnt - 2]) >= 0) --rcnt;   
                    ls[lcnt++] = i;
                    rs[rcnt++] = i;
                }
            
            memcpy(b, ls, sizeof(int) * lcnt);
            cnt = lcnt;
            for (int i = rcnt - 2; i >= 1; --i) {
               b[cnt++] = rs[i]; 
            }

            if (calc() >= d) {
                cool = true;
                break;
            }
        }

        if (cool) L = mid;
        else R = mid;
    }

    cout.precision(20); cout << fixed;
    cout << sqrtl((long double) D[L]) / 2. << endl; 

    return 0;
}