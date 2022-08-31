#include <bits/stdc++.h>

using i64 = long long;

std::vector<int> sg(200 + 1);

int getSG(int n) {
    while (n > 200) {
        n -= 34;
    }
    return sg[n];
}

void solve() {
    int n;
    std::cin >> n;
    
    std::string s;
    std::cin >> s;
    
    int cntr = std::count(s.begin(), s.end(), 'R');
    int cntb = n - cntr;
    
    if (cntr > cntb) {
        std::cout << "Alice\n";
        return;
    }
    if (cntr < cntb) {
        std::cout << "Bob\n";
        return;
    }
    
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] != s[i + 1]) {
            int j = i;
            while (j < n - 1 && s[j] != s[j + 1]) {
                j++;
            }
            ans ^= getSG(j - i);
            i = j;
        }
    }
    
    if (ans) {
        std::cout << "Alice\n";
    } else {
        std::cout << "Bob\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    sg[0] = 0;
    for (int i = 1; i <= 200; i++) {
        std::set<int> s;
        for (int j = 0; j < i; j++) {
            s.insert(sg[std::max(0, j - 1)] ^ sg[std::max(0, i - j - 2)]);
        }
        while (s.count(sg[i])) {
            sg[i]++;
        }
    }
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}