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
int n, u[6];
bool lck;
bool und;
int rail[4];
int rg(int i){
    return ((i + 1) % 4);
}

signed main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        lck = 1;
        und = 0;
        cin >> n;
        cin >> u[1];
        cin >> u[2];
        cin >> u[3];
        cin >> u[0];
        for(int i1 = 0; i1 < 2; i1++){
        rail[0] = 1 - rail[0];
        for(int i2 = 0; i2 < 2; i2++){
        rail[1] = 1 - rail[1];
        for(int i3 = 0; i3 < 2; i3++){
        rail[2] = 1 - rail[2];
        for(int i4 = 0; i4 < 2; i4++){
        rail[3] = 1 - rail[3];
        lck = 1;
        if(u[0] - rail[0] - rail[1] < 0) lck = 0;
        if(u[1] - rail[1] - rail[2] < 0) lck = 0;
        if(u[2] - rail[2] - rail[3] < 0) lck = 0;
        if(u[3] - rail[3] - rail[0] < 0) lck = 0;
        
        if(u[0] - rail[0] - rail[1] > n - 2) lck = 0;
        if(u[1] - rail[1] - rail[2] > n - 2) lck = 0;
        if(u[2] - rail[2] - rail[3] > n - 2) lck = 0;
        if(u[3] - rail[3] - rail[0] > n - 2) lck = 0;
        
        if(lck) und = 1;
        }
        }
        }
        }
        if(und) cout << "YES\n";
        else cout << "NO\n";
    }
}