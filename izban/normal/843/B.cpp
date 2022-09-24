#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = (int)1.01e9;
const int N = 1 << 18;

#define next nexttt
//#undef HOME
int cnt;
int n, start, x;

#ifdef HOME
int value[N], next[N];
#endif
void init() {
    cnt = 0;
#ifdef HOME
    /*cin >> n >> start >> x;
    for (int i = 1; i <= n; i++) {
        cin >> value[i] >> next[i];
    }*/
    //n = 50000;
    //n = rand() % 50000 + 1;
    n = 50000;
    set<int> st;
    while (st.size() < n) {
        st.insert(rand() % (int)1e9);
    }
    vector<pair<int, int> > a;
    for (int x : st) {
        a.push_back({x, a.size()});
    }
    random_shuffle(a.begin(), a.end());
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        p[a[i].second] = i;
    }
    for (int i = 1; i <= n; i++) {
        value[i] = a[i - 1].first;
        if (a[i - 1].second == n - 1) {
            next[i] = -1;
        } else {
            next[i] = p[a[i - 1].second + 1] + 1;
        }
    }
    start = p[0] + 1;
    x = rand() % (int)1e9;

    /*cout << n << " " << start << " " << x << endl;
    for (int i = 1; i <= n; i++) {
        cout << value[i] << " " << next[i] << endl;
    }*/
#else
    cin >> n >> start >> x;
#endif
}

const int T = 1000;

pair<int, int> ask(int i) {
    ++cnt;
    assert(cnt <= 1999);
#ifdef HOME
    //cerr << i << " " << value[i] << " " << next[i] << endl;
    return {value[i], next[i]};
#else
    cout << "? " << i << endl;
    int val, nxt;
    cin >> val >> nxt;
    return {val, nxt};
#endif
};

void answer(int ans) {
#ifdef HOME
    int mn = INF;
    for (int i = 1; i <= n; i++) if (value[i] >= x) mn = min(mn, value[i]);
    if (mn == INF) mn = -1;
    //cout << "! " << ans << " instead of " << mn << endl;
    assert(mn == ans);
#else
    cout << "! " << ans << endl;
    exit(0);
#endif
}

int Rand() {
    int res = (rand() << 15) ^ rand();
    res = abs(res);
    if (res < 0) res = 0;
    return res;
}

void solve() {
    init();
    vector<pair<pair<int, int>, int> > vct;

    set<int> st;
    vct.push_back({ask(start), start});
    st.insert(start);
    for (int i = 1; i < T; i++) {
        if (st.size() == n) break;
        int id = Rand() % n + 1;
        while (st.find(id) != st.end()) {
            id = Rand() % n + 1;
        }
        pair<int, int> o = ask(id);
        vct.push_back({o, id});
        st.insert(id);
    }
    sort(vct.begin(), vct.end());
    int id = lower_bound(vct.begin(), vct.end(), make_pair(make_pair(x, -2), -1)) - vct.begin();

    if (id == 0) {
        answer(vct[id].first.first);
        return;
    }

    if (id < (int)vct.size() && vct[id].first.first == x) {
        answer(vct[id].first.first);
        return;
    }
    int pos = vct[id - 1].first.second;

    while (1) {
        if (pos == -1) {
            answer(-1);
            return;
        }
        auto o = ask(pos);
        if (o.first >= x) {
            answer(o.first);
            return;
        }
        pos = o.second;
    }
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    for (int it = 11;; it++) {
        srand(it);
        solve();
        //cout << it << " " << cnt << endl;
        //cerr << cnt << endl;
    }


#ifdef HOME
    cerr << clock() / (double)CLOCKS_PER_SEC << endl;
#endif
    return 0;
}