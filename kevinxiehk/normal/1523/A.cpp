#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, m; 
    cin >> n >> m;
    m = min(n, m);
    string s1, s2;
    cin >> s1;
    s2 = s1;
    while(m--) {
        for(int i = 0; i < n; i++) {
            s2[i] = s1[i];
            if(s2[i] == '0') {
                int cnt = 0;
                if(i > 0 && s1[i - 1] == '1') cnt++;
                if(i < n - 1 && s1[i + 1] == '1') cnt++;
                if(cnt == 1) s2[i] = '1';   
            }
        } 
        s1 = s2;
    }
    cout << s1 << '\n';
}
int main() {
    int t;
    cin >> t;
    while(t--) solve();
}