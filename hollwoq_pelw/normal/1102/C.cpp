#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
#define F first
#define S second
#define pii pair<int, int>
#define pll pair<ll, ll>

int n, x, y, k, c;

void solve(){
    cin >> n >> x >> y;
    for (int i = 0; i < n; i++){
        cin >> k;
        if (k <= x) c++;
    }
    if (x > y) {cout << n; return;}
    cout << (c+1)/2;
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