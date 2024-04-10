#include<bits/stdc++.h>
using namespace std;

#define sadasdads long long
#define pb push_back
#define fi first
#define se second
#define fir fi.fi
#define sec fi.se
#define PI 3.141592653589793238462643383279502884
#define ll long long
const ll mod = 1e9 + 7;
const int maxN = 1000005;
const ll oo = 1e18 + 7;
int n; int a[maxN]; bool chk[maxN];

void typre(){
    for(int i = 0; i <= n + 2; i++){
        chk[i] = 0;
    }
}

pair<int, int> xr[maxN];
int temp;
int fin[maxN];
int plc[maxN];

signed main(){
    ios_base::sync_with_stdio(0);
    int n; cin >> n;
    for(int i = 2; i <= n; i++){
        cout << "XOR " << "1 " << i << endl;
        cin >> xr[i].fi; xr[i].se = i;
        if(xr[i].fi == -1) return 0;
        plc[i] = xr[i].fi;
        
    }
    sort(xr + 2, xr + n + 1);
    for(int i = 2; i < n; i++){
        if(xr[i].fi == xr[i + 1].fi){
            cout << "AND " << xr[i].se << " " << xr[i + 1].se << endl;
            cin >> temp;
            fin[1] = (temp ^ xr[i].fi);
            for(int i = 2; i <= n; i++){
                fin[i] = (fin[1] ^ plc[i]);
            }
            cout << "! ";
            for(int i = 1; i <= n; i++){
                cout << fin[i] << " ";
            }
            cout << endl;
            return 0;
        }
    }
    for(int i = 2; i < n; i++){
        if(xr[i].fi == 0){
            cout << "AND " << "1 " << xr[i].se << endl;
            cin >> temp;
            fin[1] = temp;
            for(int i = 2; i <= n; i++){
                fin[i] = (fin[1] ^ plc[i]);
            }
            cout << "! ";
            for(int i = 1; i <= n; i++){
                cout << fin[i] << " ";
            }
            cout << endl;
            return 0;
        }
    }
    for(int i = 2; i <= n; i++){
        if(xr[i].fi == n - 1){
            cout << "AND " << "1 " << xr[2].se << endl;
            cin >> temp;
            fin[1] = temp;
            fin[1] = fin[1] / 2; fin[1] = fin[1] * 2;
            cout << "AND " << "1 " << xr[n - 1].se << endl;
            cin >> temp; temp = temp % 2;
            fin[1] += temp;
            
            for(int i = 2; i <= n; i++){
                fin[i] = (fin[1] ^ plc[i]);
            }
            cout << "! ";
            for(int i = 1; i <= n; i++){
                cout << fin[i] << " ";
            }
            cout << endl;
            return 0;
        }
    }
    
    
}