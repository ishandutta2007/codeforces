#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
#define F first
#define S second
#define pii pair<int, int>
#define pll pair<ll, ll>

int l, r;

void solve(){
    cin >> l >> r;
    cout << l << ' ' << 2*l << endl;
}

int main(){
    IOS;
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}