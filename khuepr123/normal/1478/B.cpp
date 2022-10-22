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
int q, a[maxN];
int d;
int lck;

signed main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        cin >> q >> d;
        for(int i = 1; i <= q; i++){
            cin >> a[i]; lck = 0;
            if(!a[i] || a[i] >= 10 * d || a[i] % d == 0){
                cout << "YES\n"; continue;
            }
            a[i] -= d;
            lck = 1;
            while(a[i] >= 0){
                if((a[i] % d) == 0){
                    cout << "YES\n"; lck = 0; break;
                }
                a[i] -= 10;
            }
            if(lck) cout << "NO\n";
        }
        
    }
}