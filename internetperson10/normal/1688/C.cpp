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
        vector<int> ct(26, 0);
        for(int i = -1; i < 2 * n; i++) {
            string s;
            cin >> s;
            for(int g : s) ct[g - 'a']++;
        }
        for(int i = 0; i < 26; i++) {
            if(ct[i]%2) cout << (char)('a' + i) << '\n';
        }
    }
}