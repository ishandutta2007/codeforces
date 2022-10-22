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
        vector<bool> found(300);
        int x = s.size();
        for(int i = s.size() - 1; i >= 0; i--) {
            if(!found[s[i]]) {
                found[s[i]] = true;
                x = i;
            }
        }
        for(int i = x; i < s.size(); i++) {
            cout << s[i];
        }
        cout << '\n';
    }
}