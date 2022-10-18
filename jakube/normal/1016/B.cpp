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

    int n, m, q;
    cin >> n >> m >> q;
    string s, t;
    cin >> s >> t;
    PrefixAutomaton aut(t);
    int state = 0;
    vector<bool> ends_here(n, false);
    for (int i = 0; i < n; i++) {
        state = aut.transition(state, s[i]);
        if (state == m)
            ends_here[i] = true;
    }

    vector<int> psum(ends_here.size() + 1, 0);
    for (auto psum_idx = 0u; psum_idx < ends_here.size(); psum_idx++) {
        psum[psum_idx+1] = psum[psum_idx] + ends_here[psum_idx];
    }
    auto sum = [&psum](int x, int y) {
        if (x > y) return 0;
        return psum[y+1] - psum[x];
    };


    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        cout << sum(l - 1 + m - 1, r - 1) << '\n';
    }
}