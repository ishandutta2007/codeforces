#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
#define F first
#define S second
#define pii pair<int, int>
#define pll pair<ll, ll>

int n;
vector<pii> a, b;

void solve(){
    cin >> n;
    a.resize(n);
    b.resize(n);
    for (auto &[x,y]:a) cin >> x >> y;
    for (auto &[x,y]:b) cin >> x >> y;
    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());
    cout << a[0].F+b[0].F << ' ' << a[0].S+b[0].S;
}

int main(){
    IOS;
    int t=1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}