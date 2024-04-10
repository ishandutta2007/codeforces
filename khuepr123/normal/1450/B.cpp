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
int n; int x[maxN], y[maxN]; bool chk[maxN]; int k;
bool lck; bool lck2;

void typre(){
    for(int i = 0; i <= n + 2; i++){
        chk[i] = 0;
    }
}


signed main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        cin >> n >> k; lck = 1; lck2 = 1;
        for(int i = 1; i <= n; i++){
            cin >> x[i] >> y[i];
        }
        for(int i = 1; i <= n; i++){
            lck = 1;
            for(int j = 1; j <= n; j++){
                if(abs(x[i] - x[j]) + abs(y[i] - y[j]) > k) lck = 0;
            }
            if(lck){
                cout << "1\n"; lck2 = 0; break;
            }
        }
        if(lck2) cout << "-1\n";
    }
}