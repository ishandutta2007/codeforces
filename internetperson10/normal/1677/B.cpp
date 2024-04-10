#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<int> ansa(n * m), ansb(n * m);
        string s;
        cin >> s;
        vector<int> b(m);
        int g = 0;
        for(int i = 0; i < n * m; i++) {
            if(s[i] == '1') {
                if(b[i%m] == 0) {
                    b[i%m] = 1;
                    g++;
                }
            }
            ansb[i] = g;
        }
        vector<int> pref(n * m);
        for(int i = 0; i < n * m; i++) {
            pref[i] = (s[i] == '1');
            if(i) pref[i] += pref[i-1];
            if(i < m) {
                if(pref[i]) ansa[i] = 1;
            }
            else {
                ansa[i] = ansa[i-m];
                if(pref[i] > pref[i-m]) ansa[i]++;
            }
            cout << ansa[i] + ansb[i] << ' ';
        }
        cout << '\n';
    }
}