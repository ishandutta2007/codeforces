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
const int maxN = 100005;
const ll oo = 1e18 + 7;
int n, o, k;
int a[maxN];
int x, y;

signed main(){
    ios_base::sync_with_stdio(0);
    cin >> n >> o >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    while(o--){
        cin >> x >> y;
        int ans = 0 - 2 * y + 2 * x - 2;
        ans = ans + 2 * (a[y] - a[x] + 1);
        ans = ans + (a[x] - 1);
        ans = ans + (k - a[y]);
        cout << ans << endl;
    }
}