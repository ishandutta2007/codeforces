//  UOI 2011.04.12.

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>

using namespace std;

typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t > f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

const int INF = 1001001001;

int M, N;
int A[100010], B[100010];
int pslen;
pint ps[200010];
int is[200010];

int main() {
    int i, j, k;
    
    for (; ~scanf("%d%d%*d%*d", &M, &N); ) {
        for (i = 0; i < M; ++i) {
            A[i] = in();
        }
        for (j = 0; j < N; ++j) {
            B[j] = in();
        }
        pslen = 0;
        for (i = 0; i < M; ++i) {
            ps[pslen++] = mp(A[i], 0);
        }
        for (j = 0; j < N; ++j) {
            ps[pslen++] = mp(B[j], 1);
        }
        ps[pslen++] = mp(-INF, 0);
        ps[pslen++] = mp(+INF, 0);
        sort(ps, ps + pslen);
        --pslen;
        memset(is, 0, sizeof(is));
        for (i = 1; i < pslen; ++i) if (!ps[i].second) {
            int d = INF;
            j = lower_bound(B, B + N, ps[i].first) - B;
            if (j < N) chmin(d, B[j] - ps[i].first);
            if (j > 0) chmin(d, ps[i].first - B[j - 1]);
            int dl = ps[i - 1].second ? (ps[i].first - ps[i - 1].first) : INF;
            int dr = ps[i + 1].second ? (ps[i + 1].first - ps[i].first) : INF;
            if (d < INF && d == dl) is[i - 1] = 1;
            if (d < INF && d == dr) is[i] = 1;
        }
//for(i=0;i<=pslen;++i)cout<<"("<<ps[i].first<<", "<<ps[i].second<<")"<<(i==pslen?"":is[i]?"-":" ");cout<<endl;
        int ans = 0;
        for (i = 0; i < pslen; i = j) {
            if (is[i]) {
                for (j = i; j < pslen && is[j]; ++j);
//cout<<i<<" "<<j<<endl;
                bool share = 0;
                for (k = i + 1; k < j; ++k) if (ps[k].second) {
                    if (ps[k].first - ps[k - 1].first == ps[k + 1].first - ps[k].first) {
                        share = 1;
//cout<<"share: k = "<<k<<endl;
                    }
                }
                ans += (j - i + 1) / 2;
                if (!ps[i].second && !ps[j].second && share) ++ans;
            } else {
                j = i + 1;
            }
        }
        printf("%d\n", M - ans);
    }
    
    return 0;
}