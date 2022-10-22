#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fi first
#define se second
#define fir fi.fi
#define sec fi.se
#define endl "\n"
#define PI 3.141592653589793238462643383279502884
const ll mod = 1e9 + 7;
const int maxN = 100005;
const ll oo = 1e18 + 7;
int n, m, k, temp, temp1, temp2; ll a[maxN]; int b[maxN]; bool chk[maxN]; ll sum;

void typre(){ // typical reset
    for(int i = 0; i <= n + 15; i++){
        chk[i] = 0;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        sum = 0;
        cin >> n; for(int i = 1; i <= n; i++){
            cin >> a[i]; sum = sum + a[i];
        }
        sort(a + 1, a + n + 1);
        if(sum == 0) cout << "NO\n";
        else{
            cout << "YES\n";
            if(sum > 0){
                
                for(int i = n; i > 0; i--){
                    cout << a[i] << " ";
                }
            }
            else{
                for(int i = 1; i <= n; i++){
                    cout << a[i] << " ";
                }
            }
            cout << "\n";
        }
    }
}