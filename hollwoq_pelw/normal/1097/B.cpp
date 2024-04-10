#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
#define F first
#define S second
#define pii pair<int, int>
#define pll pair<ll, ll>

int a[16], n;

bool dfs(int sum, int i){
    if (i == n) return sum%360 == 0;
    return dfs(sum+a[i], i+1) || dfs(sum-a[i], i+1);
}

void solve(){
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    if (dfs(0, 0)) cout << "YES";
    else cout << "NO";
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