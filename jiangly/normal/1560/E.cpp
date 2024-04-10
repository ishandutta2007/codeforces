#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    std::string t;
    std::cin >> t;
    
    int n = t.length();
    
    int lst[26], cnt[26] = {};
    std::memset(lst, -1, sizeof(lst));
    
    for (int i = 0; i < n; i++) {
        lst[t[i] - 'a'] = i;
        cnt[t[i] - 'a']++;
    }
    
    std::string del;
    for (int i = 0; i < 26; i++) {
        if (lst[i] != -1) {
            del += 'a' + i;
        }
    }
    
    std::sort(del.begin(), del.end(), [&](auto a, auto b) { return lst[a - 'a'] < lst[b - 'a']; });
    int d = del.length();
    
    int m = 0;
    
    int pos[26] = {};
    for (int i = 0; i < d; i++) {
        pos[del[i] - 'a'] = i + 1;
    }
    
    for (int i = 0; i < 26; i++) {
        if (pos[i] == 0) {
            continue;
        }
        if (cnt[i] % pos[i] != 0) {
            std::cout << "-1\n";
            return;
        }
        m += cnt[i] / pos[i];
    }
    
    std::string s = t.substr(0, m);
    
    std::string realt;
    for (int x = 1; x <= d; x++) {
        for (int i = 0; i < m; i++) {
            if (pos[s[i] - 'a'] >= x) {
                realt += s[i];
            }
        }
    }
    
    if (realt != t) {
        std::cout << "-1\n";
        return;
    }
    
    std::cout << s << " " << del << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}