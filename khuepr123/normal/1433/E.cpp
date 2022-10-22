#include<bits/stdc++.h>
using namespace std;
 
 
#define int long long
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
 
int fac[100];
signed main(){
    ios_base::sync_with_stdio(0);

    fac[0] = 1;
    for(int i = 1; i <= 98; i++){
         fac[i] = fac[i - 1] * i;
    }
        cin >> n;
        int ans = 1;
        ans = fac[n] / fac[n / 2] / fac[n / 2];
        ans = ans * fac[n / 2 - 1] * fac[n / 2 - 1];
        ans /= 2; cout << ans;
}