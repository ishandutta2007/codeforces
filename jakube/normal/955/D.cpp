#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
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

struct S {
    string s;
    vector<int> pi;
    vector<vector<int>> aut;

    void compute_automaton() {
        s += '#';
        int n = s.size();
        pi = prefix_function(s);
        aut.assign(n, vector<int>(26));
        for (int i = 0; i < n; i++) {
            for (int c = 0; c < 26; c++) {
                if (i > 0 && 'a' + c != s[i])
                    aut[i][c] = aut[pi[i-1]][c];
                else
                    aut[i][c] = i + ('a' + c == s[i]);
            }
        }
    }
};

const int BIG = 500'001;

vector<int> get_earliest_encounter(int k, string s, S& aut) {
    vector<int> earliest_encounter(BIG, -1);
    int state = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        state = aut.aut[state][s[i] - 'a'];
        if (i >= k - 1) {
            int st = state;
            while (st > 0 && earliest_encounter[st] == -1) {
                earliest_encounter[st] = i;
                st = aut.pi[st - 1];
            }
        }
    }
    earliest_encounter[0] = k - 1;
    return earliest_encounter;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;
    
    string s, t;
    cin >> s >> t;
    string s2 = s;
    reverse(s2.begin(), s2.end());
    string t2 = t;
    reverse(t2.begin(), t2.end());
    
    S aut, aut2;
    aut.s = t;
    aut.compute_automaton();
    aut2.s = t2;
    aut2.compute_automaton();

    auto ee = get_earliest_encounter(k, s, aut);
    auto ee2 = get_earliest_encounter(k, s2, aut2);
    for (int& e : ee2) {
        if (e >= 0)
            e = n - 1 - e;
    }
    
    for (int i = 0; i <= min(m, k); i++) {
        int left = i;
        int right = m - i;
        if (max(left, right) > k)
            continue;

        int end_left = ee[left];
        int end_right = ee2[right];
        if (end_left < 0 || end_right < 0)
            continue;

        if (end_left < end_right) {
            cout << "Yes" << '\n';
            cout << end_left - k + 2 << " " << end_right + 1 << endl;
            return 0;
        }
    }

    // all
    if (m <= k) {
        int st = 0;
        for (int i = 0; i < n; i++) {
            st = aut.aut[st][s[i] - 'a'];
            if (st == m) {
                // free after
                int f = n - 1 - i;
                if (f >= k) {
                    cout << "Yes" << '\n';
                    cout << max(0, i - k - 1) + 1 << " " << n - k + 1 << endl;
                    return 0;
                }
                // before
                int start = i - m + 1;
                int before = start;
                if (before >= k) {
                    cout << "Yes" << '\n';
                    cout << 1 << " " << min(n - k, start) + 1 << endl;
                    return 0;
                }
            }
        } 
    }

    cout << "No" << endl;
}