#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
#define F first
#define S second
#define pii pair<int, int>
#define pll pair<ll, ll>

int n,k;

void solve(){
    cin >> n >> k;
    for (int mod = k-1; mod >= 0; mod --){
        if (n%mod==0){
            cout << n/mod*k+mod;
            return ;
        }
    }
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