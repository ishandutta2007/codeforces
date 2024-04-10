#include <bits/stdc++.h>

#define int long long
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define mp make_pair
#define len(v) ((int)v.size())
#define vc vector
#define pr pair
#define endl "\n"
#define endd endl; exit(0)

using namespace std;

const int MAXN = 1e5;
const int INF = 1e9;
const int MOD = 1e9 + 7;

main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    string a[n];
    int ans = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (a[i][0] == 'T'){
            ans += 4;
        }
        if (a[i][0] == 'C'){
            ans += 6;
        }
        if (a[i][0] == 'O'){
            ans += 8;
        }
        if (a[i][0] == 'D'){
            ans += 12;
        }
        if (a[i][0] == 'I'){
            ans += 20;
        }
    }
    cout << ans;
}