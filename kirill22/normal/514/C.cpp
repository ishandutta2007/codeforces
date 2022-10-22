#include<bits/stdc++.h>

using namespace std;

#define int long long

int mod  = 1000000000000000005, p = 3;
vector<int> ST;

int f(char c) {
    return c - 'a';
}

int Hash(string s) {
    int res = 0;
    for (auto c : s) {
        res = (res * p + f(c)) % mod;
    }
    return res;
}

signed main() {
    ST.push_back(1);
    for (int i = 0; i < 1e6 + 10; i++) {
        ST.push_back((ST[i] * p) % mod);
    }
    int n, m;
    cin >> n >> m;
    set<int> a;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int c = Hash(s);
        a.insert(c);
    }
    while (m--) {
        string s;
        cin >> s;
        bool fi = false;
        int c = Hash(s);
        for (int i = 0; i < s.size(); i++) {
            for (char j = 'a'; j <= 'c'; j++) {
                if (j == s[i]) continue;
                int new_Hash = (c + (f(j) - f(s[i])) * ST[s.size() - i - 1])% mod;
                if (new_Hash < 0) new_Hash += mod;
                if (a.find(new_Hash)!= a.end()) {
                    fi = true;
                }
            }
        }
        if (fi) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}