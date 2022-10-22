#include<bits/stdc++.h>
using namespace std;

#define int long long
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
int n; pair<int, int> a[maxN]; bool chk[maxN];
int pre[maxN];

void typre(){
    for(int i = 0; i <= n + 2; i++){
        chk[i] = 0;
    }
}
// a[i].fi: first element sorted ; increasing
// pre : sum of element from right ; decreasing

// 3 4 5 7 a[i].fi
// 2 2 4 1
// 9 7 5 1 pre[i]

// 1  2 3 4
// 3  3 3 3
// 12 9 6 3

// 10 10
// 1  2
// 3  2


signed main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o; int ans;
    while(o--){
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a[i].fi;
        }
        for(int i = 1; i <= n; i++){
            cin >> a[i].se;
        }
        sort(a + 1, a + n + 1); int mark1 = 1; int mark2 = 1;
        a[0].fi = a[1].fi - 1;
        for(int i = 1; i <= n; i++){
            if(a[i].fi != a[i - 1].fi){
                mark1 = i; mark2 = i;
            }
            else if(a[i].fi == a[i + 1].fi){
                mark2 = i + 1;
            }
            else{
                reverse(a + mark1, a + mark2 + 1);
            }
        }
        
        pre[n + 1] = 0;
        for(int i = n; i > 0; i--){
            pre[i] = pre[i + 1] + a[i].se;
        }
        ans = oo;
        for(int i = 1; i <= n; i++){
            if(pre[i + 1] <= a[i].fi){
                ans = a[i].fi;
                break;
            }
        }
        for(int i = n; i > 0; i--){
            if(pre[i + 1] > a[i].fi){
                ans = min(ans, pre[i + 1]);
                break;
            }
        }
        
        ans = min(ans , min(a[n].fi, pre[1]));
        cout << ans << endl;
    }
}