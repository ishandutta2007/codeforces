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
int n; int a[maxN]; bool chk[maxN]; queue <int> pack; int par1; int height;

void typre(){
    for(int i = 0; i <= n + 2; i++){
        chk[i] = 0;
    }
}

int pad(int par){
    int chi = 0;
    while(!pack.empty() && par > 0){
        par--; chi += pack.front(); pack.pop();
    }
    if(pack.empty()) return 0;
    return chi;
}

signed main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        a[n + 1] = 0;
        for(int i = 2; i <= n; i++){
            int clump = 1;
            while(a[i] < a[i + 1]){
                i++; clump++; // basically counting i + 1 more
            }
            pack.push(clump);
        }
        par1 = 1; height = 1;
        while(!pack.empty()){
            par1 = pad(par1);
            if(par1 == 0) cout << height << endl;;
            height++; // guarantee win
        }
        
    }
}