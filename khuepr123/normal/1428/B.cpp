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
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, m, k, temp, temp1, temp2; char c[maxN]; int b[maxN]; bool chk[maxN]; bool x; int sum;
int state[maxN]; // 0 free, 1 returnable, 2 locked

void typre(){ // typical reset
    for(int i = 0; i <= n + 15; i++){
        chk[i] = 0;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        cin >> n; x = 1; for(int i = 1; i <= n; i++){
            cin >> c[i];
        }
        sum = 0;
        x = 1;
        for(int i = 1; i <= n; i++){
            if(c[i] == 45 || c[i] == 60){
                x = 1;
            }
            else{
                x = 0; break;
            }
        }
        if(x){cout << n << "\n"; continue;}
        x = 1;
        for(int i = 1; i <= n; i++){
            if(c[i] == 45 || c[i] == 62){
                x = 1;
            }
            else{
                x = 0; break;
            }
        }
        if(x){cout << n << "\n"; continue;}
        
        
        for(int i = 1; i < n; i++){
            if(c[i] != 45 && c[i + 1] != 45){
                sum = sum;
            }
            else{
                sum++;
            }
        }
        if(c[1] != 45 && c[n] != 45){
            m++;
        }
        else{
            sum++;
        }
        cout << sum << "\n";
    }
}