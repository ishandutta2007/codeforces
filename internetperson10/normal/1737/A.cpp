#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    int c[26];
    for(int i = 0; i < 26; i++) {
        c[i] = 0;
    }
    string s;
    cin >> s;
    for(int i = 0; i < n; i++) {
        c[s[i] - 'a']++;
    }
    string s2;
    for(int i = 0; i < k; i++) {
        s2.push_back('a' + (n/k));
    }
    for(int i = 0; i < n; i++) {
        for(int j = n/k; j >= 0; j--) {
            for(int x = c[j]; x < s2.size(); x++) {
                s2[x] = ('a' + j);
            }
        }
    }
    cout << s2 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc_count;
    cin >> tc_count;
    while(tc_count--) {
        solve();
    }
}