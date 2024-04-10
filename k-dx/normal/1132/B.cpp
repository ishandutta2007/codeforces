#include <bits/stdc++.h>
using namespace std;

const int MAXN = (10e5)*3+5;

int n, m;
long long int bars[MAXN];
int coupons[MAXN];
long long int pref[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> bars[i];

    cin >> m;
    for(int i = 1; i <= m; i++)
        cin >> coupons[i];

    sort(bars+1, bars+n+1);
    for(int i = 1; i <= n; i++)
        pref[i] = pref[i-1] + bars[i];

    for(int i = 1; i <= m; i++)
        cout << pref[n - coupons[i]] + pref[n] - pref[n - coupons[i]+1] << "\n";

    return 0;
}