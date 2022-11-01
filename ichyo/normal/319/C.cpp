// Template {{{
#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)
using namespace std;
typedef long long LL;

#ifdef LOCAL
#include "contest.h"
#else
#define dump(x) 
#endif

class range {
    struct Iterator {
        int val, inc;
        int operator*() {return val;}
        bool operator!=(Iterator& rhs) {return val < rhs.val;}
        void operator++() {val += inc;}
    };
    Iterator i, n;
    public:
    range(int e) : i({0, 1}), n({e, 1}) {}
    range(int b, int e) : i({b, 1}), n({e, 1}) {}
    range(int b, int e, int inc) : i({b, inc}), n({e, inc}) {}
    Iterator& begin() {return i;}
    Iterator& end() {return n;}
};

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
inline bool valid(int x, int w) { return 0 <= x && x < w; }

void iostream_init() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(12);
}
//}}}
typedef long long LL;
const LL INF = 1e18;

struct LowerEnvelope{
    int s, t;
    vector<LL> deq_a;
    vector<LL> deq_b;
    // f_i(x) = deq_a[i] * x + deq_b[i]
    // f2
    inline bool check(LL a1, LL b1, LL a2, LL b2, LL a3, LL b3) const {
        return (long double)(a2 - a1) * (b3 - b2) >= (long double)(b2 - b1) * (a3 - a2);
    }
    LowerEnvelope(int n) :
        s(0), t(0), deq_a(n), deq_b(n) {}
    //  ax + b  
    void push(LL a, LL b){
        while(s + 1 < t && check(deq_a[t - 2], deq_b[t - 2], deq_a[t - 1], deq_b[t - 1], a, b)) t--;
        deq_a[t] = a;
        deq_b[t++] = b;
    }
    LL minimum(LL x){
        assert(s < t);
        while(s + 1 < t && deq_a[s] * x + deq_b[s] >= deq_a[s + 1] * x + deq_b[s + 1]) s++;
        return deq_a[s] * x + deq_b[s];
    }
};

int main(){
    iostream_init();
    int n;
    cin >> n;
    vector<LL> a(n);
    vector<LL> b(n);
    vector<LL> dp(n, INF);
    REP(i, n) cin >> a[i];
    REP(i, n) cin >> b[i];
    dp[0] = 0;

    LowerEnvelope env(n);
    env.push(b[0], dp[0]);
    for(int i = 1; i < n; i++) {
        dp[i] = env.minimum(a[i]);
        env.push(b[i], dp[i]);
    }
    cout << dp[n-1] << endl;
    return 0;
}

/* vim:set foldmethod=marker: */