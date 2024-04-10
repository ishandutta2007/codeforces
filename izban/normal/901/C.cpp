#include <bits/stdc++.h>
#define eprintf(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
using namespace std;
typedef long long ll;

const int N = 300300;

int n, m;
vector<int> e[N];
int c[N];
vector<pair<int, int> > segs;

void print(vector<ll> v) {
    for (ll x : v) printf("%lld\n", x);
}

vector<int> st;

void dfs(int v, int pr) {
    c[v] = 1;
    st.push_back(v);
    for (int to : e[v]) {
        if (to == pr) continue;
        if (c[to] == 0) {
            dfs(to, v);
        } else if (c[to] == 1) {
            int cmn = to, cmx = to;
            for (int i = 0; st[(int)st.size() - 1 - i] != to; i++) {
                cmn = min(cmn, st[st.size() - 1 - i]);
                cmx = max(cmx, st[st.size() - 1 - i]);
            }
            segs.push_back({cmn, cmx});
        } else {
            continue;
        }
    }
    st.pop_back();
    c[v] = 2;
}

ll sum(ll n) {
    return n * (n + 1) / 2;
}

ll sum(ll l, ll r) {
    return sum(r) - sum(l - 1);
}

vector<ll> fast(int n, vector<pair<int, int> > ed, vector<pair<int, int> > b) {
    vector<ll> ans(b.size());

    for (int i = 0; i < n; i++) {
        e[i].clear();
    }
    for (auto o : ed) {
        e[o.first].push_back(o.second);
        e[o.second].push_back(o.first);
    }

    for (int i = 0; i < n; i++) {
        c[i] = 0;
    }

    segs.clear();
    for (int i = 0; i < n; i++) {
        if (c[i] != 0) continue;
        dfs(i, -1);
    }

    sort(segs.begin(), segs.end(), [&](pair<int, int> x, pair<int, int> y) {
        if (x.first != y.first) return x.first < y.first;
        return x.second > y.second;
    });
    vector<pair<int, int> > nsegs;
    for (auto o : segs) {
        /*if (nsegs.empty() || o.second > nsegs.back().second) {
            nsegs.push_back(o);
        }*/
        while (!nsegs.empty() && nsegs.back().second >= o.second) {
            nsegs.pop_back();
        }
        nsegs.push_back(o);
    }
    auto segs1 = nsegs;
    auto segs2 = nsegs;
    for (auto &o : segs2) swap(o.first, o.second);

    int k = segs1.size();
    vector<ll> pref(k + 1);
    for (int i = 1; i <= k; i++) {
        pref[i] = pref[i - 1];
        if (i < k) {
            pref[i] += sum(segs1[i].second - segs1[i].first, segs1[i].second - segs1[i - 1].first - 1);
        }
    }

    auto getSum = [&](int l, int r) {
        return pref[r + 1] - pref[l];
    };

    //for (auto o : segs1) cout << o.first << " " << o.second << endl;
    for (int i = 0; i < (int)b.size(); i++) {
        int l = b[i].first, r = b[i].second;

        ll cur = 1LL * (r - l + 1) * (r - l + 2) / 2;
        int id1 = lower_bound(segs1.begin(), segs1.end(), make_pair(l, -1)) - segs1.begin();
        int id2 = lower_bound(segs2.begin(), segs2.end(), make_pair(r + 1, -1)) - segs2.begin();

        if (id1 < id2) {
            cur = 0;
            cur += getSum(id1, id2 - 2);
            cur += sum(segs1[id1].second - segs1[id1].first, segs1[id1].second - l);
            cur += sum(1, r - segs1[id2 - 1].first);
        }
        ans[i] = cur;
    }
    return ans;
}

vector<ll> slow(int n, vector<pair<int, int> > ed, vector<pair<int, int> > b) {
    vector<ll> ans(b.size());

    for (int i = 0; i < n; i++) {
        e[i].clear();
    }
    for (auto o : ed) {
        e[o.first].push_back(o.second);
        e[o.second].push_back(o.first);
    }

    for (int i = 0; i < n; i++) {
        c[i] = 0;
    }

    segs.clear();
    for (int i = 0; i < n; i++) {
        if (c[i] != 0) continue;
        dfs(i, -1);
    }
    //for (auto o : segs) cout << o.first << " " << o.second << endl;
    for (int i = 0; i < (int)b.size(); i++) {
        int l = b[i].first, r = b[i].second;

        ll res = 0;
        for (int x = l; x <= r; x++) {
            for (int y = x; y <= r; y++) {
                bool ok = 1;
                for (auto o : segs) {
                    if (x <= o.first && o.second <= y) {
                        ok = 0;
                        break;
                    }
                }
                res += ok;
            }
        }
        ans[i] = res;
    }
    return ans;
}

void stress() {
    for (int it = 0;; it++) {
        cout << it << endl;
        srand(it);

        int n = rand() % 10 + 3;
        vector<pair<int, int> > ed;
        for (int i = 1; i < n; i++) {
            ed.push_back({rand() % i, i});
        }
        for (int it = 0; it < 2; it++) {
            while (1) {
                int x = rand() % n;
                int y = rand() % n;
                if (x >= y) continue;
                /*if (find(ed.begin(), ed.end(), make_pair(x, y)) != ed.end()) {
                    continue;
                }*/
                ed.push_back({x, y});
                break;
            }
        }
        int q = rand() % 1 + 1;
        vector<pair<int, int> > b;
        for (int i = 0; i < q; i++) {
            int x = rand() % n;
            int y = rand() % n;
            if (x > y) swap(x, y);
            b.push_back({x, y});
        }

        auto ans1 = fast(n, ed, b);
        auto ans2 = slow(n, ed, b);

        if (ans1 != ans2) {
            cout << "----" << endl;
            print(ans1);
            cout << "instead of " << endl;
            print(ans2);
            cout << "----" << endl;
            cout << n << " " << ed.size() << endl;
            for (auto o : ed) cout << o.first + 1 << " " << o.second + 1 << endl;
            cout << q << endl;
            for (auto o : b) cout << o.first +  1 << " " << o.second + 1 << endl;
            cout << endl;
            fast(n, ed, b);
            cout << endl;
            slow(n, ed, b);
            exit(0);
        }
    }
}

int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif
    //stress();

    while (scanf("%d%d", &n, &m) == 2) {
        vector<pair<int, int> > ed;
        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            --u; --v;
            ed.push_back({u, v});
        }
        int q;
        scanf("%d", &q);
        vector<pair<int, int> > b(q);
        for (int i = 0; i < q; i++) {
            scanf("%d%d", &b[i].first, &b[i].second);
            b[i].first--; b[i].second--;
        }

        print(fast(n, ed, b));
    }

#ifdef HOME
    eprintf("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}