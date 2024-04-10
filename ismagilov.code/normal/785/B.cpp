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

    int mini = INF;
    int maxi = 0;
    int mini1 = INF;
    int maxi1 = 0;
    pr<int, int> a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i].fs >> a[i].sc;
        mini = min(a[i].sc, mini);
        maxi = max(a[i].fs, maxi);
    }
    int m;
    cin >> m;
    pr<int, int> b[m];
    for (int i = 0; i < m; i++){
        cin >> b[i].fs >> b[i].sc;
        mini1 = min(b[i].sc, mini1);
        maxi1 = max(b[i].fs, maxi1);
    }
    cout << max(0ll, max(maxi - mini1, maxi1 - mini));
}