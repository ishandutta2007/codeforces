#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int l = 0, r = 0, q = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '(') l++;
        if(s[i] == ')') r++;
        if(s[i] == '?') q++;
    }
    int l2 = n/2 - l, r2 = n/2 - r;
    if(l2 == 0 || r2 == 0) {
        cout << "YES\n";
        return;
    }
    bool ok = true;
    int sum = 0;
    int minSum = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '?') {
            if(l2 == 1 && ok) {
                s[i] = ')';
                ok = false;
            }
            else if(l2) {
                l2--;
                s[i] = '(';
            }
            else {
                s[i] = ')';
            }
        }
        if(s[i] == '(') sum++;
        else sum--;
        minSum = min(minSum, sum);
    }
    if(minSum < 0) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}