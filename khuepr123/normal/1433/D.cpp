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
int n, m, k, temp, temp1, temp2; int a[maxN]; int b[maxN]; bool chk[maxN];
 
void typre(){ // typical reset
    for(int i = 0; i <= n + 15; i++){
        chk[i] = 0;
    }
}
 
signed main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
         bool x = 1;
        cin >> n; for(int i = 1; i <= n; i++){
            cin >> a[i];
            
        }for(int i = 2; i <= n; i++){
            if(a[i] != a[i - 1]) x = 0;
        }
        if(x){cout << "NO\n"; continue;}
        cout << "YES\n";
        int pos1, pos2, val1, val2;
        pos1 = 1; val1 = a[1];
        for(int i = 1; i <= n; i++){
            if(a[i] != val1){
                 pos2 = i; val2 = a[i];
            }
        }
        for(int i = 2; i <= n; i++){
            if(a[i] == val1){
                 cout << i << " " << pos2 << endl;
            }
            else{
                 cout << i << " " << pos1 << endl;
            }
        }
    }
}