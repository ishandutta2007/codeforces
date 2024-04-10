#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, d, m;
    cin >> n >> d >> m;
    ll ans = 0;
    vi a, b;
    for(int i = 0; i < n; i++) {
        int c;
        cin >> c;
        if(c > m) {
            a.push_back(c);
        } else {
            b.push_back(c);
        }
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<ll> pref(b.size() + 1);
    pref[0] = 0;
    for(int i = 1; i <= b.size(); i++) {
        pref[i] = pref[i - 1] + b[b.size() - i];
    }
    ans = pref[b.size()];
    ll sum = 0;
    for(int i = (int)a.size() - 1; i >= 0; i--) {
        sum += a[i];
        int take = (a.size() - i - 1) * (d + 1) + 1;
        if(take > n) {
            break;
        }
        ans = max(ans, sum + pref[min((int)b.size(), n - take)]);
    }
    cout << ans;
}