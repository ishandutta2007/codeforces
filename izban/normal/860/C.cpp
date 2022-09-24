#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = (int)1.01e9;
const int N = 1 << 18;
const int MOD = (int)1e9 + 7;

char buf[N];
int n;

int parse(string s) {
    bool ok = 1;
    ok &= s[0] != '0';

    int cur = 0;
    for (int j = 0; j < (int)s.length(); j++) {
        if (!(s[j] >= '0' && s[j] <= '9')) {
            ok = 0;
        } else {
            cur = 10 * cur + (s[j] - '0');
        }
    }
    ok &= cur >= 1 && cur <= n;
    if (!ok) return 0;
    return cur;
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    while (scanf("%d", &n) == 1) {
        vector<string> a(n);
        vector<int> t(n);
        for (int i = 0; i < n; i++) {
            scanf("%s%d", buf, &t[i]);
            a[i] = buf;
        }

        int samples = 0;
        for (int i = 0; i < n; i++) {
            t[i] ^= 1;
            if (t[i] == 0) samples++;
        }

        vector<vector<vector<int> > > g(2, vector<vector<int> >(3)); // sample|test; samle|test|trash
        for (int i = 0; i < n; i++) {
            int cur = parse(a[i]);

            int tp = -1;
            if (cur == 0 || cur > n) {
                tp = 2;
            } else {
                tp = cur > samples;
            }
            g[t[i]][tp].push_back(i);
        }
        vector<vector<int> > cnt(2, vector<int>(3));
        for (int i = 0; i < 2; i++) for (int j = 0; j < 3; j++) cnt[i][j] = g[i][j].size();

        int res;
        res = cnt[0][1] + cnt[0][2] + cnt[1][0] + cnt[1][2];
        if (cnt[0][2] == 0 && cnt[1][2] == 0 && cnt[0][0] + cnt[1][1] != n) {
            res++;
        }

        vector<int> used(n + 1);
        for (int i = 0; i < n; i++) used[parse(a[i])] = 1;

        set<int> s0, s1;
        for (int i = 1; i <= n; i++) {
            if (!used[i]) {
                if (i <= samples) s0.insert(i);
                else s1.insert(i);
            }
        }


        vector<pair<string, string> > ans;
        if (cnt[0][2] == 0 && cnt[1][2] == 0 && cnt[0][0] + cnt[1][1] != n) {
            assert(cnt[0][1] > 0);
            int id = *g[0][1].rbegin();
            g[0][1].pop_back();
            cnt[0][1]--;
            cnt[0][2]++;
            g[0][2].push_back(id);
            s1.insert(parse(a[id]));

            string tmp = "aga42s";
            while (1) {
                bool ff = 1;
                for (int i = 0; i < n; i++) ff &= a[i] != tmp;
                if (ff) break;
                tmp = "";
                for (int i = 0; i < 6; i++) tmp += (char)('a' + rand() % 26);
            }
            ans.push_back({a[id], tmp});
            a[id] = tmp;
        }

        while (1) {
            if (cnt[0][1] > 0 && !s0.empty()) {
                int id = *g[0][1].rbegin();
                g[0][1].pop_back();
                cnt[0][1]--;

                int nw = *s0.begin();
                s0.erase(nw);

                s1.insert(parse(a[id]));

                ans.push_back({a[id], to_string(nw)});
                continue;
            }
            if (cnt[1][0] > 0 && !s1.empty()) {
                int id = *g[1][0].rbegin();
                g[1][0].pop_back();
                cnt[1][0]--;

                int nw = *s1.begin();
                s1.erase(nw);

                s0.insert(parse(a[id]));

                ans.push_back({a[id], to_string(nw)});
                continue;
            }
            if (cnt[0][2] > 0 && !s0.empty()) {
                int id = *g[0][2].rbegin();
                g[0][2].pop_back();
                cnt[0][2]--;

                int nw = *s0.begin();
                s0.erase(nw);

                ans.push_back({a[id], to_string(nw)});
                continue;
            }
            if (cnt[1][2] > 0 && !s1.empty()) {
                int id = *g[1][2].rbegin();
                g[1][2].pop_back();
                cnt[1][2]--;

                int nw = *s1.begin();
                s1.erase(nw);

                ans.push_back({a[id], to_string(nw)});
                continue;
            }
            break;
        }

        assert((int)ans.size() == res);
        printf("%d\n", ans.size());
        for (auto o : ans) printf("move %s %s\n", o.first.c_str(), o.second.c_str());
    }

#ifdef HOME
    cerr << clock() / (double)CLOCKS_PER_SEC << endl;
#endif
    return 0;
}