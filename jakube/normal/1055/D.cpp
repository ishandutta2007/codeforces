#include <bits/stdc++.h>
using namespace std;

class PrefixAutomaton {
public:
    PrefixAutomaton(std::string str) : s(str) {
        s += '#';
        int n = s.size();
        pi = prefix_function(s);
        aut.assign(n, std::vector<int>(26));
        for (int i = 0; i < n; i++) {
            for (int c = 0; c < 26; c++) {
                if (i > 0 && 'a' + c != s[i])
                    aut[i][c] = aut[pi[i-1]][c];
                else
                    aut[i][c] = i + ('a' + c == s[i]);
            }
        }
    }

    int transition(int state, char c) {
        return aut[state][c - 'a'];
    }

    static std::vector<int> prefix_function(std::string s) {
        int n = (int)s.length();
        std::vector<int> pi(n);
        for (int i = 1; i < n; i++) {
            int j = pi[i-1];
            while (j > 0 && s[i] != s[j])
                j = pi[j-1];
            if (s[i] == s[j])
                j++;
            pi[i] = j;
        }
        return pi;
    }

private:
    std::string s;
    std::vector<int> pi;
    std::vector<std::vector<int>> aut;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<string> s(n);
    for (auto& x : s)
        cin >> x;
    vector<string> t(n);
    for (auto& x : t)
        cin >> x;
    
    string pattern = "";
    string replacement = "";
    vector<int> starts(n);
    vector<int> ends(n);
    for (int i = 0; i < n; i++) {
        int m = (int)s[i].size();
        int start = 0;
        while (start < m && s[i][start] == t[i][start]) {
            start++;
        }
        int end = m - 1;
        while (end >= 0 && s[i][end] == t[i][end]) {
            end--;
        }
        if (start <= end) {
            if (pattern == "") {
                pattern = s[i].substr(start, end - start + 1);
                replacement = t[i].substr(start, end - start + 1);
                starts[i] = start;
                ends[i] = end;
            } else {
                if (pattern != s[i].substr(start, end - start + 1) || 
                    replacement != t[i].substr(start, end - start + 1)) {
                    cout << "NO" << '\n';
                    return 0;
                } else {
                    starts[i] = start;
                    ends[i] = end;
                }
            }
        } else {
            starts[i] = -1;
            ends[i] = -1;
        }
    }

    int len_pattern = pattern.size();
    while (true) {
        char c = '_';
        char d = '_';
        bool yes = true;
        for (int i = 0; i < n; i++) {
            if (starts[i] == -1)
                continue;
            if (starts[i] > 0) {
                if (c == '_') {
                    c = s[i][starts[i]-1];
                    d = t[i][starts[i]-1];
                } else if (c != s[i][starts[i]-1] || d != t[i][starts[i]-1]) {
                    yes = false;
                }
            } else {
                yes = false;
            }
        }
        if (!yes)
            break;

        len_pattern++;
        for (int i = 0; i < n; i++) {
            if (starts[i] > 0) {
                starts[i]--;
            }
        }
    }
    while (true) {
        char c = '_';
        char d = '_';
        bool yes = true;
        for (int i = 0; i < n; i++) {
            if (ends[i] == -1)
                continue;
            if (ends[i] + 1 < (int)s[i].size()) {
                if (c == '_') {
                    c = s[i][ends[i]+1];
                    d = t[i][ends[i]+1];
                } else if (c != s[i][ends[i]+1] || d != t[i][ends[i]+1]) {
                    yes = false;
                }
            } else {
                yes = false;
            }
        }
        if (!yes)
            break;

        len_pattern++;
        for (int i = 0; i < n; i++) {
            if (ends[i] != -1) {
                ends[i]++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (starts[i] != -1) {
            pattern = s[i].substr(starts[i], len_pattern);
            replacement = t[i].substr(starts[i], len_pattern);
        }
    }

    PrefixAutomaton pattern_aut(pattern);
    PrefixAutomaton replace_aut(replacement);

    for (int i = 0; i < n; i++) {
        int st = 0;
        int m = (int)s[i].size();
        for (int j = 0; j < m; j++) {
            st = pattern_aut.transition(st, s[i][j]);
            if (st == len_pattern) {
                if (ends[i] == j) {
                    break;
                } else {
                    cout << "NO" << '\n';
                    return 0;
                }
            }
        }
    }
    // for (int i = 0; i < n; i++) {
    //     auto S = s[i];
    //     auto T = t[i];
    //     if (S == "")
    //         continue;

    //     bool possible = false;
    //     int st1 = 0, st2 = 0;
    //     int m = (int)S.size();
    //     for (int j = 0; j < m; j++) {
    //         st1 = pattern_aut.transition(st1, S[j]);
    //         st2 = replace_aut.transition(st2, T[j]);
    //         if (st1 == m && st2 == m) {
    //             possible = true;
    //             break;
    //         }
    //     }
    //     if (!possible) {
    //         cout << "NO" << '\n';
    //         return 0;
    //     }
    // }
    cout << "YES" << '\n';
    cout << pattern << '\n';
    cout << replacement << '\n';
}