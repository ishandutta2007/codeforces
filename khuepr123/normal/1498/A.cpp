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
int n, a[maxN];


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        cin >> n;
        for(int i = n; i > 0; i++){
            int gg = 0;
            int cop = i;
            // cout << cop << " ";
            while(cop){
                gg += (cop % 10);
                cop = cop / 10;
            }
            if(__gcd(gg, i) > 1){
                cout << i << endl;
                break;
            }
        }
    }
}