#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    int ans = 0;
    auto sad = [&](int i) {
        if(i < 2 || i >= n) return false;
        if(s[i-2] == 'a' && s[i-1] == 'b' && s[i] == 'c') return true;
        return false;
    };
    for(int i = 2; i < n; i++) ans += sad(i);
    while(q--) {
        int c;
        char ch;
        cin >> c >> ch;
        c--;
        for(int i = c; i <= c+2; i++) ans -= sad(i);
        s.at(c) = ch;
        for(int i = c; i <= c+2; i++) ans += sad(i);
        cout << ans << '\n';
    }
}