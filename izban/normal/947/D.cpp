#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dbl;

const int N = 1 << 17;

string fast(string s, string t, vector<pair<pair<int, int>, pair<int, int>>> b) {
    vector<string> a(2);
    a[0] = s;
    a[1] = t;

    vector<int> n(2);
    n[0] = a[0].length();
    n[1] = a[1].length();

    vector<vector<vector<int>>> cnt(2, vector<vector<int>>(3));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cnt[i][j].resize(n[i] + 1);
            for (int k = 0; k < n[i]; k++) {
                cnt[i][j][k + 1] = cnt[i][j][k] + (a[i][k] == "ABC"[j]);
            }
        }
    }

    auto getSuf = [&](int id, int r) {
        int L = -1, R = r + 1;
        while (R - L > 1) {
            int M = (L + R) >> 1;
            if (cnt[id][0][r + 1] - cnt[id][0][M] == (r + 1 - M)) {
                R = M;
            } else {
                L = M;
            }
        }
        return r + 1 - R;
    };

    string ans;
    for (auto o : b) {
        int l1 = o.first.first, r1 = o.first.second;
        int l2 = o.second.first, r2 = o.second.second;

        int y1 = getSuf(0, r1);
        y1 = min(y1, r1 - l1 + 1);
        int m1 = r1 - y1;
        int x1 = (m1 - l1 + 1) - (cnt[0][0][m1 + 1] - cnt[0][0][l1]);

        int y2 = getSuf(1, r2);
        y2 = min(y2, r2 - l2 + 1);
        int m2 = r2 - y2;
        int x2 = (m2 - l2 + 1) - (cnt[1][0][m2 + 1] - cnt[1][0][l2]);

        bool ok = 1;
        if (y1 < y2) ok = 0;
        else {
            bool ff = 0;
            while (y1 % 3 != y2 % 3) {
                y1--;
                ff = 1;
            }
            if (ff) x1 += 2;
            if (x1 > x2) ok = 0;
            else if (x1 == x2) ok = 1;
            else {
                if ((x2 - x1) % 2 != 0) ok = 0;
                else {
                    if (x1 > 0) ok = 1;
                    else {
                        ok = y2 <= y1 - 3 && x2 >= x1 + 2;
                    }
                }
            }
        }

        ans += ok ? '1' : '0';
    }
    return ans;
}

bool can(string a, string b) {
    set<string> was;
    queue<string> q;

    auto go = [&](string s) {
        if (s.length() > 10) return;
        if (was.find(s) == was.end()) {
            was.insert(s);
            q.push(s);
        }
    };
    go(a);
    while (!q.empty()){
        string s = q.front();
        q.pop();

        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (i + 2 < n && s[i] == 'A' && s[i + 1] == 'A' && s[i + 2] == 'A') {
                string ns = s;
                ns.erase(ns.begin() + i, ns.begin() + (i + 3));
                go(ns);
            }
            string ns = s;
            ns.erase(ns.begin() + i);
            string nw = "ABC";
            //nw.erase(nw.find(s[i]));
            nw.erase(find(nw.begin(), nw.end(), s[i]));
            ns.insert(ns.begin() + i, nw.begin(), nw.end());
            go(ns);
        }
    }
    return was.find(b) != was.end();
}

string slow(string s, string t, vector<pair<pair<int, int>, pair<int, int>>> b) {
    string ans;
    for (auto o : b) {
        int l1 = o.first.first, r1 = o.first.second;
        int l2 = o.second.first, r2 = o.second.second;

        string a = s.substr(l1, r1 - l1 + 1);
        string b = t.substr(l2, r2 - l2 + 1);
        ans += can(a, b) ? '1' : '0';
    }
    return ans;
}

void stress() {
    const int C = 7;
    for (int it = 100161;; it++) {
        cout << it << endl;
        srand(it);

        int n = rand() % C + 1;
        int m = rand() % C + 1;
        string s = "", t = "";
        for (int i = 0; i < n; i++) s += "ABC"[rand() % 3];
        for (int i = 0; i < m; i++) t += "ABC"[rand() % 3];
        int q = rand() % C + 1;
        //int q = 1;
        vector<pair<pair<int, int>, pair<int, int>>> b(q);
        for (int i = 0; i < q; i++) {
            b[i].first.first = rand() % n;
            b[i].first.second = rand() % n;
            b[i].second.first = rand() % m;
            b[i].second.second = rand() % m;
            if (b[i].first.first > b[i].first.second) swap(b[i].first.first, b[i].first.second);
            if (b[i].second.first > b[i].second.second) swap(b[i].second.first, b[i].second.second);
        }

        auto ans1 = fast(s, t, b);
        auto ans2 = slow(s, t, b);
        if (ans1 != ans2) {
            cout << ans1 << " instead of " << ans2 << endl;
            cout << s << " " << t << endl;
            for (auto o : b) {
                cout << o.first.first << " " << o.first.second << " " << o.second.first << " " << o.second.second << endl;
            }
            exit(0);
        }
    }
}

char buf[N];
int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif
    //stress();

    string s, t;
    while (scanf("%s", buf) == 1) {
        s = buf;
        scanf("%s", buf);
        t = buf;


        int q;
        scanf("%d", &q);
        vector<pair<pair<int, int>, pair<int, int>>> b;
        for (int ii = 0; ii < q; ii++) {
            int l1, r1;
            int l2, r2;
            scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
            l1--;
            r1--;
            l2--;
            r2--;
            b.push_back({{l1, r1},
                         {l2, r2}});
        }

        cout << fast(s, t, b) << endl;
    }

    return 0;
}