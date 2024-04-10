#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n; //
        cin >> n;
        string s1, s2;
        cin >> s1 >> s2;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(s1.at(i) == '0') {
                if(s2.at(i) == '1') {
                    s2.at(i) = '0';
                    ans++;
                }
                continue;
            }
            if(i == 0) {
                if(s2.at(i+1) == '1') {
                    s2.at(i+1) = '0';
                    ans++;
                }
            }
            else if(i == n-1) {
                if(s2.at(i-1) == '1') {
                    s2.at(i-1) = '0';
                    ans++;
                }
            }//
            else {//
                if(s2.at(i-1) == '1') {
                    s2.at(i-1) = '0';
                    ans++;
                }
                else if(s2.at(i+1) == '1') {
                    s2.at(i+1) = '0';
                    ans++;
                }
            }
        }
        cout << ans << '\n'; // yay
    }
}