#include <bits/stdc++.h>

#ifdef HOME
#define db(x) cerr << #x << " = " << x << endl
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")" << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl
#define dbv(a) cerr << #a << " = "; for (auto xxx: a) cerr << xxx  << " "; cerr << endl
#else
#define db(x) ;
#define db3(x, y, z) ;
#define db2(x, y) ;
#define dbv(a) ;
#endif

using namespace std;
typedef long long ll;
typedef double dbl;


const int INF = 1.01e9;

void print(vector<double> v) {
    for (double x : v) {
        if (x < -0.5) printf("-1\n");
        else printf("%.17f\n", x);
    }
}

vector<double> fast(vector<int> tp, vector<int> t, vector<int> s, vector<int> ql, vector<int> qr, vector<int> qv) {
    int q = tp.size();

    vector<int> xx;
    xx.push_back(-1);
    xx.push_back(INF);
    for (auto cx : t) xx.push_back(cx);
    for (auto cx : ql) xx.push_back(cx);
    for (auto cx : qr) xx.push_back(cx);
    sort(xx.begin(), xx.end());
    xx.resize(unique(xx.begin(), xx.end()) - xx.begin());
    for (auto &cx : t) cx = lower_bound(xx.begin(), xx.end(), cx) - xx.begin();
    for (auto &cx : ql) cx = lower_bound(xx.begin(), xx.end(), cx) - xx.begin();
    for (auto &cx : qr) cx = lower_bound(xx.begin(), xx.end(), cx) - xx.begin();

    int m = xx.size();

    vector<int> speed(m);
    vector<ll> val(m);
    set<int> st;
    st.insert(0);
    st.insert(m - 1);

    struct item {
        ll delta;
        ll min;
    };
    vector<item> tt(4 * m);

    function<void(int, int, int, int, ll)> upd = [&](int v, int tl, int tr, int x, ll y) {
        if (tl == tr) {
            tt[v] = {y, min(0LL, y)};
            val[tl] = y;
            return;
        }
        int tm = (tl + tr) >> 1;
        if (x <= tm) upd(v * 2, tl, tm, x, y);
        else upd(v * 2 + 1, tm + 1, tr, x, y);
        tt[v].delta = tt[v * 2].delta + tt[v * 2 + 1].delta;
        tt[v].min = min(tt[v * 2].min, tt[v * 2].delta + tt[v * 2 + 1].min);
    };

    function<pair<ll, int>(int, int, int, int, int, ll)> get = [&](int v, int tl, int tr, int l, int r, ll x) {
        if (l > r) return make_pair(x, -1);
        int tm = (tl + tr) >> 1;
        if (l == tl && r == tr) {
            if (x + tt[v].min > 0) {
                return make_pair(x + tt[v].delta, -1);
            } else {
                if (tl == tr) {
                    return make_pair(x + tt[v].delta, tl);
                }
                if (x + tt[v * 2].min > 0) {
                    return get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, x + tt[v * 2].delta);
                }
                return get(v * 2, tl, tm, l, min(r, tm), x);
            }
        }
        auto o = get(v * 2, tl, tm, l, min(r, tm), x);
        if (o.first <= 0) return o;
        x = o.first;
        return get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, x);
    };

    vector<double> ans;
    for (int i = 0; i < q; i++) {
        if (tp[i] == 1) {
            auto nxtIt = st.lower_bound(t[i]);
            auto prvIt = nxtIt;
            prvIt--;
            auto nxt = *nxtIt, prv = *prvIt;
            int cur = t[i];
            speed[cur] = s[i];

            upd(1, 0, m - 1, prv, 1LL * speed[prv] * (xx[cur] - xx[prv]));
            upd(1, 0, m - 1, cur, 1LL * speed[cur] * (xx[nxt] - xx[cur]));
            st.insert(cur);
        }
        if (tp[i] == 2) {
            auto nxtIt = st.lower_bound(t[i]);
            auto prvIt = nxtIt;
            prvIt--;
            nxtIt++;
            auto nxt = *nxtIt, prv = *prvIt;
            int cur = t[i];
            speed[cur] = 0;

            upd(1, 0, m - 1, prv, 1LL * speed[prv] * (xx[nxt] - xx[prv]));
            upd(1, 0, m - 1, cur, 0);
            st.erase(cur);
        }
        if (tp[i] == 3) {
            auto o = get(1, 0, m - 1, ql[i], qr[i] - 1, qv[i]);
            double res;
            if (qv[i] == 0) {
                res = xx[ql[i]];
            } else
            if (o.first > 0) {
                res = -1;
            } else {
                o.first -= val[o.second];
                res = xx[o.second] + o.first * 1.0 / -speed[o.second];
                if (xx[o.second] * 1LL * -speed[o.second] + o.first > xx[qr[i]] * 1LL * -speed[o.second] ) {
                    res = -1;
                }
            }
            ans.push_back(res);
        }
    }
    return ans;
}

int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif

    int q;
    bool first = 1;
    while (scanf("%d", &q) == 1) {
        if (first) first = 0;
        else printf("\n");

        vector<int> tp(q), t(q), s(q), ql(q), qr(q), qv(q);
        for (int i = 0; i < q; i++) {
            scanf("%d", &tp[i]);
            if (tp[i] == 1) {
                scanf("%d%d", &t[i], &s[i]);
            }
            if (tp[i] == 2) {
                scanf("%d", &t[i]);
            }
            if (tp[i] == 3) {
                scanf("%d%d%d", &ql[i], &qr[i], &qv[i]);
            }
        }
        print(fast(tp, t, s, ql, qr, qv));
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}