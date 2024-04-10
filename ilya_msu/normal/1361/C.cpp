#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#define _USE_MATH_DEFINES
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<utility>
#include<map>
#include<ctime>
#include<cstdio>
#include<cassert>
#include<functional>
#include<unordered_map>
#include<deque>
#include<cmath>





using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<char, char> pcc;
typedef pair<double, double> pdd;

#define show(x) cerr << x
#define debug(x) show(#x << ": " << (x) << endl)

const long double PI = 3.14159265358979323846;
const long double eps = 1e-5;
const ll INF = numeric_limits<int>::max();
const ll LINF = numeric_limits<ll>::max();
const ll mod = 1000 * 1000 * 1000 + 7;


vector<vector<pii> > g;
vector<int> getC(int ed) {
    vector<int> used(ed, 0);
    vector<pii> st;
    vector<int> res;
    int n = g.size();
    int id = 0;
    while (g[id].empty())
        ++id;
    st.push_back(pii(id, -1));
    res.push_back(id);
    vector<int> p(n, 0);
    while (!st.empty()) {
        int v = st.back().first;
        int e = st.back().second;
        int ph = 0;
        for (int i = p[v]; i < g[v].size(); ++i, ++p[v]) {
            int id = g[v][i].second;
            if (used[id])
                continue;
            used[id] = 1;
            st.push_back(pii(g[v][i].first, id));
            ph = 1;
            break;
        }
        if (ph == 0) {
            res.push_back(e);
            st.pop_back();
        }
    }
    /*cout << "gr\n";
    for (int i = 0; i < n; ++i) {
        cout << i << ": ";
        for (int j = 0; j < g[i].size(); ++j) {
            cout << "(" << g[i][j].first << ", " << g[i][j].second << ") ";
        }
        cout << endl;
    }
    cout << "res" << res.size() << endl;*/
    res.resize(ed + 1);
    return res;
}


vector<int> us;


void dfs(int pos) {
    us[pos] = 1;
    for (auto to:g[pos]) {
        if (us[to.first])
            continue;
        dfs(to.first);
    }
    return;
}


bool check(vector<int> ans, const vector<int>& a, const vector<int>& b, int M) {
    for (int i = 0; i < ans.size(); ++i) {
        if (ans[i] & 1) {
            ans[i] = a[ans[i] / 2];
        }
        else {
            ans[i] = b[ans[i] / 2 - 1];
        }
    }
    ans.push_back(ans[0]);
    bool ok = 1;
    for (int i = 1; i + 1 < ans.size(); i += 2) {
        if ((ans[i] & M) != (ans[i + 1] & M))
            return 0;
    }
    return 1;
}


void solve() {
    int n;
    cin >> n;
    vector<int> cnt(1 << 20, 0);
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        ++cnt[a[i]];
        ++cnt[b[i]];
    }
    int k = 20;
    while (true) {
        int ok = 1;
        for (int i = 0; i < cnt.size(); ++i) {
            if (cnt[i] & 1) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            int N = 1 << k;
            int M = N - 1;
            g.assign(N, vector<pii>());
            for (int i = 0; i < n; ++i) {
                int aa = a[i] & M;
                int bb = b[i] & M;
                g[bb].push_back(pii(aa, i));
                g[aa].push_back(pii(bb, i));
            }
            int id = 0;
            us.assign(N, 0);
            while (g[id].size() == 0) {
                ++id;
            }
            dfs(id);
            for (int i = 0; i < N; ++i) {
                if ((!g[i].empty()) && (us[i] == 0)) {
                    //cerr << i << endl;
                    ok = 0;
                    break;
                }
            }
            if (ok)
                break;
        }
        --k;
        int sz = cnt.size() / 2;
        for (int i = 0; i < sz; ++i) {
            cnt[i] += cnt[i + sz];
        }
        cnt.resize(sz);
    }
    cout << k << endl;
    
    vector<int> cyc = getC(n);
    /*for (int i = 0; i < cyc.size(); ++i) {
        cout << cyc[i] << " ";
    }
    cout << endl;*/
    //cout << 2 * cyc[0] + 1 << " " << 2 * cyc[0] + 2 << " ";
    //int lst = b[cyc[0]];

    int lst1 = a[cyc[1]], lst2 = b[cyc[1]];
    vector<int> ans1, ans2;
    int N = 1 << k;
    int M = N - 1;
    for (int i = 1; i <= n; ++i) {
        int id = cyc[i];
        if ((lst1 & M) == (a[id] & M)) {
            ans1.push_back(2 * id + 1);
            ans1.push_back(2 * id + 2);
            lst1 = b[id];
        }
        else {
            ans1.push_back(2 * id + 2);
            ans1.push_back(2 * id + 1);
            lst1 = a[id];
        }

        if ((lst2 & M) == (a[id] & M)) {
            ans2.push_back(2 * id + 1);
            ans2.push_back(2 * id + 2);
            lst2 = b[id];
        }
        else {
            ans2.push_back(2 * id + 2);
            ans2.push_back(2 * id + 1);
            lst2 = a[id];
        }
    }
    int ok1 = check(ans1, a, b, M);
    int ok2 = check(ans2, a, b, M);
    if (ok1) {
        for (int i = 0; i < ans1.size(); ++i) {
            cout << ans1[i] << " ";
        }
    }
    else {
        if (ok2) {
            for (int i = 0; i < ans2.size(); ++i) {
                cout << ans2[i] << " ";
            }
        }
        else {
            assert(0);
        }

    }
    cout << endl;

}


//#define LOCAL

int main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    solve();



#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
    return 0;
}