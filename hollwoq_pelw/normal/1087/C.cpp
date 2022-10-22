#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
#define F first
#define S second
#define pii pair<int, int>
#define pll pair<ll, ll>

int main(){
    IOS;
    pii a[3];
    for (int i = 0; i < 3; i++) cin >> a[i].F >> a[i].S;
    
    sort(a, a+3);
    
    int mid = a[1].F, mx = -1, mn = INT_MAX;
    for (int i = 0; i < 3; i++){
        mx = max(mx, a[i].S);
        mn = min(mn, a[i].S);
    }
    //cout << mid << ' ' << mn << ' ' << mx << endl;
    set<pii> ans;
    
    for (int i = a[0].F; i <= mid; i++) ans.insert({i, a[0].S});
    for (int i = mid; i <= a[2].F; i++) ans.insert({i, a[2].S});
    for (int i = mn; i <= mx; i++) ans.insert({mid, i});
    
    cout << ans.size() << endl;
    for (auto [x,y]:ans) cout << x << ' ' << y << endl;
    
    return 0;
}