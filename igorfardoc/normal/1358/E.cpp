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
    int n;
    cin >> n;
    vi a(n);
    for(int i = 0; i < (n - 1) / 2 + 1; i++) {
        cin >> a[i];
    }
    int x;
    cin >> x;
    for(int i = (n - 1) / 2 + 1; i < n; i++) {
        a[i] = x;
    }
    if(x > 0) {
        ll sum = 0;
        for(int i = 0; i < n; i++) {
            sum += a[i];
        }
        if(sum > 0) {
            cout << n;
        } else {
            cout << -1;
        }
        return 0;
    }
    vector<ll> pref(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + a[i - 1];
    }
    if(x == 0) {
        if(pref[n] > 0) {
            cout << n;
        } else {
            cout << -1;
        }
        return 0;
    }
    int r = n;
    for(int i = 0; i < (n - 1) / 2 + 1; i++) {
        ll sum = pref[(n - 1) / 2 + 1] - pref[i];
        ll am = 0;
        if(sum > 0) {
            am = (sum - 1) / (-x);
        }
        //cout << sum << ' ' << am << endl;
        r = min((ll)r, am + ((n - 1) / 2 + 1 - i));
        if(r == n - i) {
            cout << r;
            return 0;
        }
        r = min(r, n - i - 1);
    }
    cout << -1;
}