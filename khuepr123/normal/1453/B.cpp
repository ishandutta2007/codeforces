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
#define int long long
const ll mod = 1e9 + 7;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n; int a[maxN]; bool chk[maxN];
int sum; int mx;


void typre(){
    for(int i = 0; i <= n + 2; i++){
        chk[i] = 0;
    }
}


signed main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        cin >> n; mx = 0; sum = 0;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        for(int i = 2; i <= n; i++){
            sum = sum + abs(a[i] - a[i - 1]);
        }
        for(int i = 2; i < n; i++){
            if((a[i - 1] - a[i])*(a[i] - a[i + 1]) < 0)
            mx = max(mx, 2 * min(abs(a[i] - a[i - 1]), abs(a[i] - a[i + 1])));
        }
        mx = max(mx, abs(a[n] - a[n - 1]));
        mx = max(mx, abs(a[1] - a[2]));
        cout << sum - mx << endl;
    }
}