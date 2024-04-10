#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int BIG = 999999;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s[2];
        cin >> s[0] >> s[1];
        int mi = BIG, ma = 0;
        vector<int> v;
        for(int i = 0; i < n; i++) {
            bool b0 = (s[0][i] == '*');
            bool b1 = (s[1][i] == '*');
            if(b0 && b1) v.push_back(3);
            else if(b0) v.push_back(1);
            else if(b1) v.push_back(2);
            if(b0 || b1) {
                mi = min(mi, i);
                ma = i;
            }
        }
        ll tot = ma - mi;
        n = v.size();
        int a1, a2;
        a1 = a2 = 0;
        for(int i = 0; i < n; i++) {
            int b1, b2;
            if(v[i] & 1) {
                b1 = min(a1 + 1, a2 + 1);
            }
            else {
                b1 = min(a1, a2 + 1);
            }
            if(v[i] & 2) {
                b2 = min(a2 + 1, a1 + 1);
            }
            else {
                b2 = min(a2, a1 + 1);
            }
            a1 = b1;
            a2 = b2;
        }
        cout << tot + min(a1, a2) << '\n';
        v.clear();
    }
}