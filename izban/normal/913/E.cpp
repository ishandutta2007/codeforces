#include <bits/stdc++.h>
#define eprintf(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
using namespace std;
typedef long long ll;

struct cmp {
    bool operator()(const string &x, const string &y) {
        if (x.length() != y.length()) return x.length() < y.length();
        return x < y;
    }
} comp;

int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif


    map<string, pair<int, vector<int> > > mp;
    set<string, cmp> st;
    vector<map<vector<int>, string> > vct(3);
    vector<vector<string> > all(3);

    auto upd = [&](int tp, string x, vector<int> y) {
        auto it = vct[tp].find(y);
        if (it != vct[tp].end()) {
            if (comp(x, it->second)) {
                st.erase(it->second);
                vct[tp].erase(it);
            }
        }
        if (!vct[tp].count(y)) {
            vct[tp][y] = x;
            mp[x] = {tp, y};
            st.insert(x);
        }
    };
    upd(2, "x", {0,0,0,0,1,1,1,1});
    upd(2, "y", {0,0,1,1,0,0,1,1});
    upd(2, "z", {0,1,0,1,0,1,0,1});

    auto fix = [&](string s, char c) {
        int n = s.length();

        vector<char> f(n);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                cnt++;
            } else if (s[i] == ')') {
                cnt--;
            } else if (s[i] == c) {
                if (cnt == 0) {
                    f[i] = 1;
                }
            }
        }
        vector<string> vct;
        string cur = "";
        for (int i = 0; i < n; i++) {
            if (f[i]) {
                vct.push_back(cur);
                cur = "";
                continue;
            }
            cur += s[i];
        }
        vct.push_back(cur);
        sort(vct.begin(), vct.end());
        string res = "";
        res += vct[0];
        for (int i = 1; i < (int)vct.size(); i++) {
            res += c;
            res += vct[i];
        }
        return res;
    };

    int iters = 0;
    while (!st.empty()) {
        iters++;
        string s = *st.begin();
        st.erase(st.begin());

        auto o = mp[s];
        auto val = o.second;
        if (o.first == 2) {
            auto nval = val;
            for (int i = 0; i < 8; i++) nval[i] ^= 1;
            upd(2, "!" + s, nval);

            upd(1, s, val);
            for (auto t : all[1]) {
                nval = val;
                auto tval = mp[t].second;
                for (int i = 0; i < 8; i++) nval[i] &= tval[i];
                upd(1, fix(t + "&" + s, '&'), nval);
            }
        } else if (o.first == 1) {
            upd(0, s, val);
            for (auto e : all[0]) {
                auto nval = val;
                auto tval = mp[e].second;
                for (int i = 0; i < 8; i++) nval[i] |= tval[i];
                upd(0, fix(e + "|" + s, '|'), nval);
            }
            for (auto f : all[2]) {
                auto nval = val;
                auto tval = mp[f].second;
                for (int i = 0; i < 8; i++) nval[i] &= tval[i];
                upd(1, fix(f + "&" + s, '&'), nval);
            }
        } else if (o.first == 0) {
            upd(2, "(" + s + ")", val);

            for (auto t : all[1]) {
                auto nval = val;
                auto tval = mp[t].second;
                for (int i = 0; i < 8; i++) nval[i] |= tval[i];
                upd(0, fix(t + "|" + s, '|'), nval);
            }
        }
        all[o.first].push_back(s);
    }

    auto solve = [&](vector<int> val) {
        string ans = "";
        for (int i = 0; i < 2; i++) {
            if (vct[i].count(val)) {
                if (ans == "" || comp(vct[i][val], ans)) {
                    ans = vct[i][val];
                }
            }
        }
        return ans;
    };

    int T;
    cin >> T;
    while (T--) {
        string o;
        cin >> o;
        vector<int> val(8);
        for (int i = 0; i < 8; i++) val[i] = o[i] - '0';

        auto ans = solve(val);
        cout << ans << endl;
    }

    /*for (int mask = 0; mask < (1 << 8); mask++) {
        vector<int> val(8);
        for (int i = 0; i < 8; i++) val[i] = (mask >> i) & 1;

        auto ans = solve(val);
        cout << ans << endl;
    }*/

#ifdef HOME
    eprintf("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}