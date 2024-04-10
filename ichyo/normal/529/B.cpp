// Template {{{
#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)
using namespace std;
typedef long long LL;

template<typename T1, typename T2>
ostream& operator << (ostream& os, const pair<T1, T2>& p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}

template<typename T>
ostream& operator << (ostream& os, const vector<T>& v) {
    os << "{";
    for(int i = 0; i < v.size(); i++)
        os << v[i] << (i+1<v.size()?", ":"");
    os << "}";
    return os;
}

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

typedef pair<int, int> P;
int max(const P& p) {
    return max(p.first, p.second);
}
int min(const P& p) {
    return min(p.first, p.second);
}
const int INF = 1000000000;
void update(vector<int>& dp, const P& p) {
    const int M = dp.size();
    vector<int> ndp(M, INF);
    for(int i = 0; i < M; i++) {
        ndp[i] = min(ndp[i], dp[i] + p.first);
        if(i+1 < M) ndp[i+1] = min(ndp[i+1], dp[i] + p.second);
    }
    dp.swap(ndp);
}
int main(){
    iostream_init();
    int n;
    while(cin >> n) {
        vector<pair<int, int>> vp(n);
        REP(i, n) cin >> vp[i].first >> vp[i].second;
        sort(vp.begin(), vp.end(), [&](const pair<int, int>& a, const pair<int, int>& b) {
                return max(a) < max(b);
                });
        int lb = INT_MIN;
        REP(i, n) lb = max(lb, min(vp[i].first, vp[i].second));

        vector<int> all;
        REP(i, n) if(vp[i].first >= lb) all.push_back(vp[i].first);
        REP(i, n) if(vp[i].second >= lb) all.push_back(vp[i].second);
        sort(all.begin(), all.end());
        all.erase(unique(all.begin(), all.end()), all.end());

        int cur = 0;
        int swap_cnt = 0;
        int width = 0;
        // max, min
        // max == width
        // min == height
        REP(i, n) if(vp[i].second != min(vp[i])) swap_cnt++;
        REP(i, n) width += max(vp[i]);
        const int L = n/2 + 1;

        vector<int> dp(L, INF); // minimum sum
        dp[0] = 0;

        long long ans = LLONG_MAX;
        for(int H : all) {
            while(cur < n && max(vp[cur]) <= H) {
                width -= max(vp[cur]);
                if(vp[cur].second != min(vp[cur])) swap_cnt--;
                update(dp, vp[cur++]);
            }
            for(int i = 0; i+swap_cnt <= n/2; i++) if(dp[i] < INF) {
                long long width_all = width + dp[i];
                ans = min(ans, width_all * H);
            }
        }

        cout << ans << endl;
    }

    return 0;
}

/* vim:set foldmethod=marker: */