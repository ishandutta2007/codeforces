#include <iostream>
#include <algorithm>
std::string s;
bool query(std::string t) {
    std::cout << "? " << t << std::endl;
    int k;
    std::cin >> k;
    for (int i = 0; i < k; ++i) {
        int x;
        std::cin >> x;
        --x;
        for (int j = 0; j < int(t.length()); ++j)
            s[x + j] = t[j];
    }
    return k > 0;
}
void solve() {
    int n;
    std::cin >> n;
    s = std::string(n, 0);
    query("HO");
    query("HC");
    query("CH");
    query("CO");
    if (n != 4) {
        query("OHH");
        query("OCC");
        for (int i = 1; i < n - 1; ++i)
            if (s[i] == 0)
                s[i] = s[i - 1];
        if (s[n - 1] == 0 && s[n - 2] != 'O')
            s[n - 1] = s[n - 2];
        for (int i = n - 2; i >= 0; --i)
            if (s[i] == 0 && s[i + 1] == 'O')
                s[i] = s[i + 1];
    }
    int l = 0, r = n - 1;
    while (l < n && s[l] == 0)
        ++l;
    while (r >= 0 && s[r] == 0)
        --r;
    if (l > r) {
        if (n == 4 && (query("OHH") || query("OCC"))) {
            s[0] = 'O';
            s[3] = s[2];
        } else {
            if (query("OOO")) {
                if (s[n - 1] == 0 && !query("OOOC"))
                    s[n - 1] = 'H';
            } else {
                if (!query("HHHH"))
                    s = std::string(n, 'C');
            }
        }
    } else {
        if (n == 4) {
            while (l > 0) {
                std::string q = s.substr(l, r - l + 1);
                --l;
                if (!query("O" + q) && !query("H" + q))
                    s[l] = 'C';
            }
            while (r < n - 1) {
                std::string q = s.substr(l, r - l + 1);
                ++r;
                if (!query(q + "O") && !query(q + "H"))
                    s[r] = 'C';
            }
        } else {
            while (r < n - 2) {
                ++r;
                s[r] = 'O';
            }
            if (l != 0) {
                std::string q = s.substr(0, r + 1);
                for (int i = 0; i < l; ++i)
                    q[i] = q[l];
                if (!query(q))
                    std::fill(s.begin(), s.begin() + l, 'O');
            }
            if (r == n - 2) {
                std::string q = s.substr(0, r + 1);
                if (!query(q + "O") && !query(q + "H"))
                    s[n - 1] = 'C';
            }
        }
    }
    std::cout << "! " << s << std::endl;
    std::cin >> s;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--)
        solve();
    return 0;
}