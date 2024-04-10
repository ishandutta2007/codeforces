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

string fast(int n, int k, vector<pair<int, int>> a) {
    for (int i = 0; i < k; i++) {
        if (a[i].first > a[i].second) {
            swap(a[i].first, a[i].second);
        }

        if (n - a[i].second + a[i].first < a[i].second - a[i].first) {
            swap(a[i].first, a[i].second);
        }
    }


    vector<vector<int>> vct(n + 1);
    for (int i = 0; i < k; i++) {
        int d = a[i].second - a[i].first;
        if (d < 0) d += n;
        vct[d].push_back(a[i].first);
    }

    vector<int> last(n + 1);
    int tmr = 0;
    vector<int> cnt(n + 1);

    auto inc = [&](int x) {
        if (last[x] != tmr) {
            last[x] = tmr;
            cnt[x] = 0;
        }
        cnt[x]++;
    };

    bool ans = 0;
    for (int t = 1; t < n; t++) {
        if (n % t) continue;
        bool ok = 1;
        for (int d = 0; d <= n; d++) {
            tmr++;


            int need = n / t;
            if (d * 2 == n) {
                need = n / 2 / t;
                for (int i = 0; i < (int)vct[d].size(); i++) {
                    int dif = vct[d][(i + 1) % vct[d].size()] - vct[d][i];
                    if (dif < 0) dif += n;
                    ok &= dif == t;
                }
                continue;
            }

            for (int l : vct[d]) {
                inc(l % t);
            }
            for (int l : vct[d]) {
                ok &= cnt[l % t] == need;
            }
        }
        ans |= ok;
    }
    string s = ans ? "Yes" :"No";

    return s;
}

string slow(int n, int k, vector<pair<int, int>> a) {
    auto fix = [&](vector<pair<int, int>> c) {
        for (auto &o : c) {
            if (o.first > o.second) swap(o.first, o.second);
        }
        sort(c.begin(), c.end());
        return c;
    };

    a = fix(a);
    for (int d = 1; d < n; d++) {
        auto b = a;
        for (auto &o : b) {
            o.first = (o.first + d) % n;
            o.second = (o.second + d) % n;
        }
        b = fix(b);
        if (a == b) {
            return "Yes";
        }
    }
    return "No";
}

string slow2(int n, int k, vector<pair<int, int>> a) {
    auto fix = [&](vector<pair<int, int>> c) {
        for (auto &o : c) {
            if (o.first > o.second) swap(o.first, o.second);
        }
        sort(c.begin(), c.end());
        return c;
    };

    a = fix(a);
    for (int d = 1; d < n; d++) {
        if (n % d) continue;
        auto b = a;
        for (auto &o : b) {
            o.first = (o.first + d) % n;
            o.second = (o.second + d) % n;
        }
        b = fix(b);
        if (a == b) {
            return "Yes";
        }
    }
    return "No";
}

void stress() {
    for (int it = 241;; it++) {
        srand(it);
        db(it);

        //int n = rand() % 15 + 4;
        int n = 102960;

        vector<pair<int, int>> a;
        /*for (int i = 0; i < n; i++) {
            for (int j = i + 2; j < n; j++) {
                if (i == 0 && j == n -1) continue;
                a.push_back({i, j});
            }
        }*/
        for (int i = 0; i < n / 2;i++) a.push_back({i, i + n / 2});
        random_shuffle(a.begin(), a.end());
        int k = rand() % a.size() + 1;

        a.resize(k);

        auto ans1 = slow2(n, k, a);
        auto ans2 = ans1;
//        auto ans2 = slow(n, k, a);
        if (ans1 != ans2) {
            cout << ans1 << " instead of " << ans2 << endl;
            cout << n << " " << k << endl;
            for (auto o : a) cout << o.first << " " << o.second << endl;
            exit(0);
        }
    }
}

int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif
//    stress();

    int n, k;
    while (scanf("%d%d", &n, &k) == 2) {
        vector<pair<int, int>> a(k);
        for (int i = 0; i < k; i++) {
            scanf("%d%d", &a[i].first, &a[i].second);
            a[i].first--;
            a[i].second--;
        }

        cout << slow2(n, k, a) << endl;
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}