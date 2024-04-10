#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define pb push_back
#define fi first
#define se second
#define fir fi.fi
#define sec fi.se
#define endl "\n"
#define ii pair<int, int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
const ll mod = 1e9 + 7;
const int maxN = 100005;
const ll oo = 1e18 + 7;
const int KK = 20000005;
int c;
int d;
int x;
int k[KK + 1];
int dv[KK + 1];
int ans;
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    for(int i = 1; i <= KK; i++){
        k[i] = i; dv[i] = 1;
    }
    for(int i = 2; i <= KK; i++){
        if(k[i] == i){
            for(int j = i; j <= KK; j += i){
                k[j] = 1;
                dv[j] *= 2;
            }
        }
    }
    // for(int i = 2; i <= 100; i++){
    //     if(k[i] == i){
    //         cout << i << endl;
    //     }
    // }
    while(o--){
        cin >> c >> d >> x;
        ans = 0;
        int hh = sqrt(x);
        int gg;
        for(int i = 1; i <= hh; i++){
            if(x % i != 0) continue;
            if((x + i * d) % c == 0){
                gg = (x + i * d) / c;
                if(gg % i == 0){
                    gg /= i;
                    ans += dv[gg];
                    // if(o == 2) cout << "           " << gg << " " << i << "            ";
                }
            }
            i = x / i;
            if(i == hh) break;
            if((x + i * d) % c == 0){
                gg = (x + i * d) / c;
                if(gg % i == 0){
                    gg /= i;
                    ans += dv[gg];
                    // if(o == 2) cout << "           " << gg << " " << i << "            ";
                }
            }
            i = x / i;
        }
        cout << ans << endl;
    }
}