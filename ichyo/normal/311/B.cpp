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
struct LowerEnvelope{
    int s, t;
    vector<LL> deq_a;
    vector<LL> deq_b;
    inline bool check(LL a1, LL b1, LL a2, LL b2, LL a3, LL b3) const {
        return (double)(a2 - a1) * (b3 - b2) >= (double)(b2 - b1) * (a3 - a2);
    }
    LowerEnvelope(int n) :
        s(0), t(0), deq_a(n), deq_b(n) {}
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
// dp[i, j] = dp[i-1, k] + a[j] * (j - k) + s[k] - s[j]
//          = (a[j] * j - s[j]) - k * a[j] + (s[k] + dp[i-1, k])
int main(){
    iostream_init();
    int n, m, p;
    cin >> n >> m >> p;
    vector<LL> d(n);
    REP(i, n-1) {
        LL x;
        cin >> x;
        d[i+1] = d[i] + x;
    }
    vector<LL> times;
    REP(i, m) {
        int h; LL t;
        cin >> h >> t;
        times.push_back(t - d[h-1]);
    }
    sort(times.begin(), times.end());

    vector<LowerEnvelope> envs(p+1, LowerEnvelope(m+1));
    vector<LL> s(m+1);
    REP(i, m) s[i+1] = s[i] + times[i];
    static LL dp[101][100001] = {};
    REP(i, p) envs[i].push(0, s[0] + dp[i][0]);
    for(int i = 1; i <= p; i++) for(int j = 1; j <= m; j++) {
        dp[i][j] = envs[i-1].minimum(times[j-1]) + times[j-1] * j - s[j];
        envs[i].push(-j, s[j] + dp[i][j]);
    }
    cout << dp[p][m] << endl;
    return 0;
}

/* vim:set foldmethod=marker: */