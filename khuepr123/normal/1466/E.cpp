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
#define int long long
const ll mod = 1e9 + 7;
const int maxN = 500005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int pw[maxN];
int total;
int temp;
int numbit[maxN];
bool ray[maxN];
int x, y;

signed main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    pw[0] = 1;
    for(int i = 1; i <= 61; i++){
        pw[i] = pw[i - 1] * 2;
        pw[i] %= mod;
    }
    // set sumdig: number of 1 in all place
    // set 2 sum and calculate all using power
    
    while(o--){
        total = 0;
        cin >> n;
        for(int j = 0; j < 60; j++){
                numbit[j] = 0;
                ray[j] = 0;
            }
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            temp = a[i];
            for(int j = 0; j < 60; j++){
                if(temp % 2) numbit[j]++;
                temp /= 2;
            }
        }
        for(int i = 1; i <= n; i++){
            x = 0; y = 0;
            temp = a[i];
            for(int j = 0; j < 60; j++){
                if(temp % 2) ray[j] = 1;
                else ray[j] = 0;
                temp /= 2;
            }
            for(int j = 0; j < 60; j++){
                if(ray[j] == 1) x += pw[j] * numbit[j];
            }
            for(int j = 0; j < 60; j++){
                if(ray[j] == 1) y += pw[j] * n;
                else y += numbit[j] * pw[j];
            }
            total += (x % mod) * (y % mod);
            total %= mod;
        }
        cout << total <<endl;
    }
}