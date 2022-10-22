#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MAXN = 100000;

int pre[MAXN+5][26];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    for(int i=1; i<=n; i++){
        for(int j=0; j<26; j++) pre[i][j] = pre[i-1][j];
        pre[i][s[i-1] - 'a']++;
    }
    while(q--){
        int l, r;
        cin >> l >> r;
        ll res = 0;
        for(int j=0; j<26; j++){
            res += 1LL*(j+1)*(pre[r][j] - pre[l-1][j]);
        }
        cout << res << "\n";
    }
    return 0;
}