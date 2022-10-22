#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
#define F first
#define S second
#define pii pair<int, int>
#define pll pair<ll, ll>

int n, k;
bool m[5005][5005];
int id[5005], a[5005];

void solve(){
    cin >> n >> k;
    int ok = 1;
    if (k > n){
        ok = 0;
    }
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= k; ++i)
         id[i] = i, m[i][a[i]] = 1;
    for (int i = k+1; i <= n; ++i){
         int flag = 0;
         for (int j = 1; j <= k; ++j){
              if (!m[j][a[i]]){
                  m[j][a[i]] = 1;
                  flag = 1;
                  id[i] = j;
                  break;
              }
         }

         ok &= flag;
    }

    if (!ok) {cout << "NO"; return;}
    cout << "YES\n";
    for (int i = 1; i <= n; ++i){
         cout << id[i] << " ";
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