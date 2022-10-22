#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int ans = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s.at(i) == '0') {
                if(i == 0) ans++;
                else if(s.at(i-1) != '0') ans++;
            }
        }
        cout << min(ans, 2) << '\n';
    }
}