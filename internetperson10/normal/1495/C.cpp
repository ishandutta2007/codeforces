#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll MOD = (ll)1000000007;
vector<vector<bool>> flowers;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, m, n;
    ll k, ans = 0;
    string s1, s2;
    bool sad = false, brr = false;;
    cin >> t;
    while(t--) {
        vector<vector<bool>>().swap(flowers);
        cin >> m >> n;
        flowers.resize(m);
        for(int i = 0; i < m; i++) {
            cin >> s1;
            flowers[i].resize(n);
            for(int j = 0; j < n; j++) {
                if(s1.at(j) == 'X') flowers[i][j] = true;
            }
        }
        for(int i = 0; i < m; i++) {
            if(!(i%3)) {
                for(int j = 0; j < n; j++) flowers[i][j] = true;
            }
            else if((i%3) == 2 && i == m-1) {
                for(int j = 0; j < n; j++) {
                    if(flowers[i][j] || flowers[i-1][j]) flowers[i][j] = flowers[i-1][j] = true;
                }
            }
        }
        for(int i = 0; i+3 < m; i += 3) {
            sad = true;
            for(int j = 0; j < n && sad; j++) {
                if(flowers[i+1][j] || flowers[i+2][j]) {
                    flowers[i+1][j] = flowers[i+2][j] = true;
                    sad = false;
                }
            }
            if(sad) {
                flowers[i+1][0] = flowers[i+2][0] = true;
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(flowers[i][j]) cout << 'X';
                else cout << '.';
            }
            cout << '\n';
        }
    }
}