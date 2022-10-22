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

signed main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        int a, b;
        int mx = mod;
        cin >> a >> b;
        b--;
        for(int j = 0; j < 10; j++){
            b++;
            int ans = j;
            int dup = a;
            while(dup){
                if(b == 1){
                    ans = mod; break;
                }
                dup = dup / b;
                ans++;
            }
            mx = min(mx, ans);
        }
        cout << mx << endl;
    }
}