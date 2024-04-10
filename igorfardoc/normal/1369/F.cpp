#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
bool win_bigger(ll s, ll e);
bool loose_bigger(ll s, ll e) {
    if(e % 2 == 1) {
        return (s % 2 == 0);
    }
    ll e1 = e / 2;
    if(e1 < s) {
        return (s % 2 == 1);
    }
    return win_bigger(s, e1);
}

bool win_bigger(ll s, ll e) {
    ll e1 = e / 2;
    if(e1 < s) {
        return true;
    }
    return loose_bigger(s, e1);
}



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
    vector<pair<ll, ll>> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    int ans1 = 1;
    int ans2 = 1;
    bool needwin = true;
    for(int i = n - 1; i >= 0; i--) {
        if(needwin) {
            if(loose_bigger(a[i].first, a[i].second)) {
                needwin = false;
            }
        } else {
            if(!win_bigger(a[i].first, a[i].second)) {
                needwin = true;
            }
        }
    }
    if(needwin) {
        ans1 = 0;
    }
    needwin = false;
    for(int i = n - 1; i >= 0; i--) {
        if(needwin) {
            if(loose_bigger(a[i].first, a[i].second)) {
                needwin = false;
            }
        } else {
            if(!win_bigger(a[i].first, a[i].second)) {
                needwin = true;
            }
        }
    }
    if(needwin) {
        ans2 = 0;
    }
    cout << ans1 << ' ' << ans2;
}