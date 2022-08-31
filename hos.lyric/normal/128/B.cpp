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

typedef unsigned uint;
typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

namespace SA {
    #define MAXN 200010
    int n;
    char t[MAXN];
    int ki[MAXN], ik[MAXN], is[MAXN], hh;
    bool cmp(const int &a, const int &b) {
        return (a == b) ? 0 : (ik[a] != ik[b]) ? (ik[a] < ik[b]) : (ik[a + hh] < ik[b + hh]);
    }
    void makeSA() {
        n = strlen(t);
        int i;
        for (i = 0; i <= n; ++i) ik[ki[i] = i] = t[i];
        is[0] = is[n] = hh = 0;
        sort(ki, ki + n + 1, cmp);
        for (hh = 1; is[n] != n; hh <<= 1) {
            sort(ki, ki + n + 1, cmp);
            for (i = 0; i < n; ++i) is[i + 1] = is[i] + (cmp(ki[i], ki[i + 1]) ? 1 : 0);
            for (i = 0; i <= n; ++i) ik[ki[i]] = is[i];
        }
    }
    int lcp[MAXN];
    void makeHA() {
        int h = 0, i, j;
        for (i = 0; i < n; ++i) {
            for (j = ki[ik[i] - 1]; t[j + h] == t[i + h]; ++h);
            lcp[ik[i] - 1] = h;
            if (h) --h;
        }
    }
}

Int K;
Int sum[MAXN];
pint ps[MAXN];
char ans[MAXN];

int main() {
    using namespace SA;
    
    int i, j;
    int l, x, y;
    
    for (; ~scanf("%s", t); ) {
        K = in();
        SA::makeSA();
        SA::makeHA();
        if (K > (Int)n * (n + 1) / 2) {
            puts("No such line.");
            continue;
        }
        for (i = 0; i <= n; ++i) {
            sum[i + 1] = sum[i] + (n - ki[i]);
        }
//cout<<"SA : ";for(i=0;i<=n;++i)cout<<t+ki[i]<<" ";cout<<endl;
//cout<<"sum : ";pv(sum,sum+n+2);
        for (i = 1; i < n; ++i) {
            ps[i - 1] = mp(lcp[i], i + 1);
        }
        sort(ps, ps + n - 1);
        memset(ans, 0, sizeof(ans));
        Int k = K;
        int a = 1, b = n + 1;
        for (x = 0, l = 0; ; x = y, ++l) {
//cout<<"l = "<<l<<", a = "<<a<<", b = "<<b<<", k = "<<k<<endl;
            for (y = x; y < n - 1 && ps[y].first == l; ++y);
            for (j = x; j < y; ++j) {
                int c = ps[j].second;
//cout<<"c = "<<c<<endl;
                if (!(a <= c && c <= b)) continue;
                Int tmp = (sum[c] - sum[a]) - (Int)l * (c - a);
//cout<<"c = "<<c<<", tmp = "<<tmp<<endl;
                if (k <= tmp) {
                    b = c;
                    break;
                } else {
                    k -= tmp;
                    a = c;
                }
            }
            ans[l] = t[ki[a] + l];
            if (k <= b - a) {
                ans[l + 1] = 0;
                goto found;
            } else {
                k -= b - a;
            }
        }
    found:;
        puts(ans);
    }
    
    return 0;
}