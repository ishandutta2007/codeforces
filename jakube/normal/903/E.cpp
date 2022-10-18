#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // n^3 * k
    // = n^2 * 5000
    int k, n;
    cin >> k >> n;
    vector<string> s(k);
    for (int i = 0; i < k; i++) {
        cin >> s[i];
    }

    auto f = [](string s) {
        vector<int> cnt(26, 0);
        for (char c : s)
            cnt[c - 'a']++;
        return cnt;
    };
    auto opt = f(s[0]);
    for (auto S : s) {
        if (opt != f(S)) {
            cout << -1 << '\n';
            return 0;
        }
    }
    bool mult = false;
    for (auto i : opt) 
        mult |= i > 1;

    if (k == 1) {
        swap(s[0][0], s[0][1]);
        cout << s[0] << endl;
        return 0;
    }

    auto check = [&s, mult](vector<int> v, int start) {
        int N = s[0].size();
        int n = v.size();
        int k = s.size();
        string S = s[start];
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(S[v[i]], S[v[j]]);

                bool b = true;
                for (int a = 0; a < k; a++) {
                    if (a == k)
                        continue;

                    int c = 0;
                    for (int d = 0; d < N; d++) {
                        c += S[d] != s[a][d];
                    }
                    if (c > 2 || (c == 0 && !mult)) {
                        b = false;
                        break;
                    }
                }

                if (b) {
                    cout << S << endl;
                    return true;
                }

                swap(S[v[i]], S[v[j]]);
            }
        }
        return false;
    };

    auto check2 = [&s, mult](vector<int> v, vector<int> w, int start) {
        int n = s[0].size();
        int k = s.size();
        string S = s[start];
        for (int i : v) {
            for (int j : w) {
                swap(S[i], S[j]);

                bool b = true;
                for (int a = 0; a < k; a++) {
                    if (a == k)
                        continue;

                    int c = 0;
                    for (int d = 0; d < n; d++) {
                        c += S[d] != s[a][d];
                    }
                    if (c > 2 || (c == 0 && !mult)) {
                        b = false;
                        break;
                    }
                }

                if (b) {
                    cout << S << endl;
                    return true;
                }

                swap(S[i], S[j]);
            }
        }
        return false;
    };

    bool b = true;
    for (int i = 1; i < k; i++) {
        if (s[i] != s[0])
            b = false;
    }
    if (b) {
        swap(s[0][0], s[0][1]);
        cout << s[0] << endl;
        return 0;
    }

    // if (n < 100) {
    //     vector<int> v(k);
    //     iota(v.begin(), v.end(), 0);
    //     if (check(v, 0))
    //         return 0;
    // } else {
    {
    
        // n >= 100
        // k <= 50
        
        // compare s[0] with s[1]
        // difference at 4 pos -> 12 possibilities
        // => 12 * k * n = 12 * 5000 
        // easy
        //
        // differences at > 5: impossible
        // differences at > 5: impossible
        // differences at 3: 3*2 = 6 poss
        // differences at 2: (multi)2*k*n or (n - 2) * 2 * k * n ~= 2 * n * 5000
        // differences at 1: impossible
        // differences at 0: ignore
        
        vector<int> diffs;
        for (int i = 0; i < k; i++) {
            for (int j = i + 1; j < k; j++) {
                diffs.clear();
                for (int a = 0; a < n; a++) {
                    if (s[i][a] != s[j][a])
                        diffs.push_back(a);
                }
                if (diffs.size() > 4) {
                    cout << -1 << endl;
                    return 0;
                }
                if (diffs.size() == 4) {
                    if (check(diffs, i))
                        return 0;
                }
                if (diffs.size() == 3) {
                    if (check(diffs, i))
                        return 0;
                }
                if (diffs.size() == 2) {
                    vector<int> w(n);
                    iota(w.begin(), w.end(), 0);
                    if (check2(diffs, w, i))
                        return 0;
                    if (mult && (check(diffs, i) || check(diffs, j))) {
                        return 0;
                    }
                }
                if (diffs.size() == 1) {
                    cout << -1 << endl;
                    return 0;
                }
            }
        }
    }
    cout << -1 << '\n';
}