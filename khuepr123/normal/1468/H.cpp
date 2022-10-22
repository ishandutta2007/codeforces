#include<bits/stdc++.h>
using namespace std;

#define sadasdads long long
#define pb push_back
#define fi first
#define se second
#define fir fi.fi
#define sec fi.se
#define endl "\n"
#define PI 3.141592653589793238462643383279502884
#define ll long long
const ll mod = 1e9 + 7;
const int maxN = 200005;
const ll oo = 1e18 + 7;

int n, k, m;
int a[maxN];

signed main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        cin >> n >> k >> m;
        for(int i = 1; i <= m; i++) cin >> a[i];
        a[0] = 0;
        a[m + 1] = n + 1;
        if((n - m) % (k - 1) != 0){
            cout << "NO\n"; continue;
        }
        k = k / 2;
        int cnt = 0;
        int ff = 0;
        for(int i = 0; i <= m; i++){
            cnt += (a[i + 1] - a[i] - 1);
            if(cnt >= k){
                cnt = 0; ff++;
            }
        }
        if(ff >= 2) cout << "YES\n";
        else cout << "NO\n";
    }
}