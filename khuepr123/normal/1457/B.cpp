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
int n; int a[maxN]; int ans, cur, mn;
int k;
void typre(){
    for(int i = 0; i <= n + 2; i++){
        a[i] = 0;
    }
}


signed main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        cin >> n >> k; mn = mod;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        for(int i = 1; i <= 100; i++){
            cur = 1; ans = 0;
            while(a[cur] == i) cur++;
            while(cur <= n){
                cur += k; ans++;
                while(a[cur] == i) cur++;
            }
            mn = min(mn, ans);
        }
        cout << mn << endl;
    }
}