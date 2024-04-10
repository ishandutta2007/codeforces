#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        s += (s.at(n-1) + 1);
        int k = 1;
        if(s.at(0) <= s.at(1)) {
            k = 1;
        }
        else {
            for(int i = 0; i < n; i++) {
                if(s.at(i) < s.at(i+1)) {
                    k = i+1;
                    break;
                }
            }
        }
        for(int i = 0; i < k; i++) cout << s[i];
        for(int i = k-1; i >= 0; i--) cout << s[i];
        cout << '\n';
    }
}