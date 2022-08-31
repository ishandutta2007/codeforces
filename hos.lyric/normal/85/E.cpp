//  Yandex.Algorithm 2011 Round 1

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
template<class T> void pvp(T a, T b) { for (T i = a; i != b; ++i) cout << "(" << i->first << ", " << i->second << ") "; cout << endl; }
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in_c() { int c; for (; (c = getchar()) <= ' '; ) { if (!~c) throw ~0; } return c; }
int in() { int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -in(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }
Int In() { Int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -In(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }

const Int MO = 1000000007;
const int INF = 1001001;

Int pw(Int x, Int e) {
    Int y = 1;
    for (; e; e >>= 1, x = x * x % MO) if (e & 1) y = y * x % MO;
    return y;
}

int N;
int A[5010], B[5010];

pair<int,Int> solve() {
    int i;
    int p, q, r, s;
    p = q = +INF;
    r = s = -INF;
    for (i = 0; i < N; ++i) {
        chmin(p, A[i]);
        chmin(q, B[i]);
        chmax(r, A[i]);
        chmax(s, B[i]);
    }
//pv(A,A+N);pv(B,B+N);
    int lo = -1, ho = INF;
    for (; lo + 1 < ho; ) {
        int mo = (lo + ho) / 2;
        for (i = 0; i < N; ++i) {
            if (A[i] <= p + mo && B[i] <= q + mo) continue;
            if (r - mo <= A[i] && s - mo <= B[i]) continue;
            break;
        }
        (i < N) ? (lo = mo) : (ho = mo);
    }
    int cnt[4] = {};
    for (i = 0; i < N; ++i) {
        int flg = 0;
        if (A[i] <= p + ho && B[i] <= q + ho) flg |= 1;
        if (r - ho <= A[i] && s - ho <= B[i]) flg |= 2;
        ++cnt[flg];
    }
    Int ret = pw(2, (cnt[1] || cnt[2]) ? (cnt[3] + 1) : cnt[3]);
    return mp(ho, ret);
}
Int both(Int ho) {
    int i, a;
    int p, q, r, s;
    p = q = +INF;
    r = s = -INF;
    for (i = 0; i < N; ++i) {
        chmin(p, A[i]);
        chmin(q, B[i]);
        chmax(r, A[i]);
        chmax(s, B[i]);
    }
    Int ret = 0;
    for (a = 0; a < 2; ++a) {
        int cnt[4] = {};
        for (i = 0; i < N; ++i) {
            int flg = 0;
            if (a == 0) {
                if (A[i] <= p + ho && B[i] <= q + ho && s - ho <= B[i]) flg |= 1;
                if (r - ho <= A[i] && B[i] <= q + ho && s - ho <= B[i]) flg |= 2;
            } else {
                if (B[i] <= q + ho && A[i] <= p + ho && r - ho <= A[i]) flg |= 1;
                if (s - ho <= B[i] && A[i] <= p + ho && r - ho <= A[i]) flg |= 2;
            }
            if (!flg) goto failed;
            ++cnt[flg];
        }
        ret += pw(2, (cnt[1] || cnt[2]) ? (cnt[3] + 1) : cnt[3]);
        ret %= MO;
    failed:;
    }
    //  very orz
    for (i = 0; i < N; ++i) {
        if (A[i] <= p + ho && B[i] <= q + ho && r - ho <= A[i] && s - ho <= B[i]) {
        } else {
            break;
        }
    }
    if (i == N) {
        ret -= pow(2, N);
        ret %= MO;
    }
    ret %= MO; ret += MO; ret %= MO;
//cerr<<"both: "<<ret<<endl;
    return ret;
}

int main() {
    int i;
    int x, y;
    
    for (; ~scanf("%d", &N); ) {
        for (i = 0; i < N; ++i) {
            x = in();
            y = in();
            A[i] = x + y;
            B[i] = x - y;
        }
        pair<int,Int> res0 = solve();
        for (i = 0; i < N; ++i) {
            B[i] = -B[i];
        }
        pair<int,Int> res1 = solve();
        for (i = 0; i < N; ++i) {
            B[i] = -B[i];
        }
//cerr<<"res0: "<<res0.first<<" "<<res0.second<<endl;
//cerr<<"res1: "<<res1.first<<" "<<res1.second<<endl;
        int ansHo = min(res0.first, res1.first);
        Int ans = 0;
        if (ansHo == res0.first) ans += res0.second;
        if (ansHo == res1.first) ans += res1.second;
        if (res0.first == res1.first) {
            ans -= both(ansHo);
        }
        ans %= MO; ans += MO; ans %= MO;
        cout << ansHo << endl;
        cout << ans << endl;
    }
    
    return 0;
}