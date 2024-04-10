#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int ans[5001][5001];
int isPal[5001][5001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    for(int i = 0; i < 2*n - 1; i++) {
        int l = i/2, r = (i+1)/2;
        bool ok = true;
        while(0 <= l && r < n) {
            ok &= (s[l] == s[r]);
            isPal[l][r] = (int)ok;
            l--; r++;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i; j++) {
            if(i == 0) ans[j][j] = isPal[j][j];
            else if(i == 1) ans[j][j+1] = ans[j][j] + ans[j+1][j+1] + isPal[j][j+1];
            else ans[j][j+i] = ans[j][j+i-1] + ans[j+1][j+i] - ans[j+1][j+i-1] + isPal[j][j+i];
        }
    }
    int q;
    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        cout << ans[l-1][r-1] << '\n';
    }
}