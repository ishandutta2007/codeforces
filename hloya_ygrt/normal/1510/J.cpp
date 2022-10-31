#include <bits/stdc++.h>

using namespace std;

string genstring(int n, int mvs, vector<int> res) {
    string f(n, '.');

    int fr = 0;
    for (int i = 0; i < res.size(); i++) {
        int to = fr + mvs;
        int l = to;
        int r = fr + res[i] - 1;

        if (l <= r) {
            for (int j = l; j <= r; j++) {
                f[j] = '#';
            }
        }
        fr += res[i] + 1;
    }

    return f;
}

#define bad() return {};


pair<vector<int>, string> genres() {
    int m = rand() % 3 + 1;
    vector<int> res;
    int sum = 0;
    for (int i = 0; i < m; i++) {
        int x = rand() % 10 + 1;
        res.push_back(x);
        sum += x;
    }
    int mvs = rand() % 4;
    int n = sum + m - 1 + mvs;
    string s = genstring(n, mvs, res);
    return {res, s};
}

int main() {
    ios_base::sync_with_stdio(false);
   // freopen("input.txt", "r", stdin);


    for (int i = 0; i < 1; i++) {
        string s;
        cin >> s;
//        auto[v, s] = genres();
//
//        cout << endl;
//        for (auto x : v) {
//            cout << x << ' ';
//        }
//        cout << endl;
//        cout << s << endl;


        /* gyper solve */
        bool fnd = 0;
        for (auto x : s) {
            if (x == '#') {
                fnd = 1;
            }
        }
        if (!fnd) {
            cout << "0\n";
            continue;
        }

        vector<pair<int, int>> rng;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '#') {
                int j = i;
                while (j < s.size() && s[j] == '#') {
                    j++;
                }
                rng.push_back({i, j - 1});
                i = j;
            }
        }

        int rm = rng[0].first;
        set<int> mid_set;
        for (int i = 0; i + 1 < rng.size(); i++) {
            int dyra = rng[i + 1].first - rng[i].second - 1;
            mid_set.insert(dyra);
            rm = min(rm, dyra);
        }
        int n = s.size();
        rm = min(rm, n - rng.back().second - 1);

        auto try_solve_0 = [&]() -> vector<int> {
            vector<int> ans;
            if (rng[0].first != 0) {
                bad();
            }
            if (rng.back().second != n - 1) {
                bad();
            }
            for (int i = 0; i + 1 < rng.size(); i++) {
                if (rng[i].second + 2 != rng[i + 1].first) {
                    bad();
                }
            }
            for (auto[l, r] : rng) {
//            cout << r - l + 1 << " ";
                ans.push_back(r - l + 1);
            }
            return ans;
        };
        auto try_solve_1 = [&]() -> vector<int> {
            vector<int> ans;

            int firstdyra = rng[0].first;
            if (firstdyra % 2 == 0) {
                bad();
            }
            for (int i = 0; i < firstdyra / 2; i++) {
                ans.push_back(1);
            }

            for (int i = 0; i + 1 < rng.size(); i++) {
                int dyra = rng[i + 1].first - (rng[i].second + 1) - 1;
                if (dyra % 2 == 0) {
                    bad();
                }
            }
            int lastdyra = n - (rng.back().second + 1) - 1;
            if (lastdyra % 2 == 1) {
                bad();
            }

            for (int i = 0; i + 1 < rng.size(); i++) {
                ans.push_back(rng[i].second + 1 - rng[i].first + 1);
                int dyra = rng[i + 1].first - (rng[i].second + 1) - 1;
                for (int x = 0; x < dyra / 2; x++)
                    ans.push_back(1);
            }
            ans.push_back(rng.back().second + 1 - rng.back().first + 1);

            for (int i = 0; i < lastdyra / 2; i++) {
                ans.push_back(1);
            }

            return ans;
        };

auto print = [](auto v) {
            cout << v.size() << "\n";
            for (auto x : v) {
                cout << x << ' ';
            }
            cout << "\n";
        };
        if (rm >= 0) {
            auto p = try_solve_0();
            if (p.size()) {
                print(p);
                continue;
            }
        }
        if (rm >= 1) {
            auto p = try_solve_1();
            if (p.size()) {
                print(p);
                continue;
            }
        }

        vector<int> ans;

        bool found_m = 0;
        int m;
        int firstdyra = rng[0].first;

        for (int kekm = 2; kekm <= rm; kekm++) {
            int lastdyra = n - (rng.back().second) - 1;
            if (mid_set.count(kekm + 2)) {
//                cout << "OTS " << kekm << endl;
                continue;
            }
            if (lastdyra - kekm == 1) {
//                cout << "OTL " << kekm << endl;
                continue;
            }
            if (firstdyra - kekm == 1) {
//                cout << "OTF " << kekm << endl;
                continue;
            }
            m = kekm;
            found_m = 1;
            break;
        }

        if (!found_m) {
            cout << "-1\n";
//            exit(228);
            continue;
        }

//        // fill
        for (int i = 0; i < rng.size(); i++) {
            rng[i].second += m;
        }

        int lastdyra = n - rng.back().second - 1;

        firstdyra -= m + 1;
        // firstdyra  =1
        // cout << firstdyra << endl;
        if (firstdyra % 2 == 1) {
            for (int i = 0; i < firstdyra / 2 + 1; i++) {
                ans.push_back(1);
            }
        } else if (firstdyra > 0) {
            for (int i = 0; i < firstdyra / 2 - 1; i++) {
                ans.push_back(1);
            }
            ans.push_back(2);
        }


        for (int i = 0; i + 1 < rng.size(); i++) {
            ans.push_back(rng[i].second - rng[i].first + 1);
            int dyra = rng[i + 1].first - rng[i].second - 1;
            assert(dyra != 2);
            if (dyra % 2 == 0) {
                for (int x = 0; x < dyra / 2 - 2; x++)
                    ans.push_back(1);
                ans.push_back(2);
            } else {
                for (int x = 0; x < dyra / 2; x++)
                    ans.push_back(1);
            }
        }

        ans.push_back(rng.back().second - rng.back().first + 1);

        if (lastdyra % 2 == 0) {
            for (int i = 0; i < lastdyra / 2; i++) {
                ans.push_back(1);
            }
        } else {
            for (int i = 0; i < lastdyra / 2 - 1; i++) {
                ans.push_back(1);
            }
            ans.push_back(2);
        }

        // cout << m << endl;
        // cout << genstring(s.size(), m, ans) << endl;
        print(ans);
    }
    return 0;
}