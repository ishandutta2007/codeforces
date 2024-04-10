#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        n++;
        string s;
        cin >> s;
        s += "W";
        int state = 0;
        bool ok = true;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'W') {
                if(state == 1 || state == 2) ok = false;
                state = 0;
            }
            if(s[i] == 'B') {
                if(state == 0) state = 1;
                if(state == 2) state = 3;
            }
            if(s[i] == 'R') {
                if(state == 0) state = 2;
                if(state == 1) state = 3;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}