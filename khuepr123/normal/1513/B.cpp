#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define ii pair<int, int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
const ll mod = 1e9 + 7;
const int maxN = 200005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;
int fac[maxN];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    fac[0] = 1;
    for(int i = 1; i < maxN; i++){
        fac[i] = fac[i - 1] * i;
        fac[i] %= mod;
    }
    while(o--){
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        for(int j = 0; j < 42; j++){
            int num = (1 << j);
            bool bk = 1;
            for(int i = 1; i <= n; i++){
                if((num & a[i]) == 0) bk = 0;
            }
            if(bk){
                for(int i = 1; i <= n; i++){
                    a[i] -= num;
                }
            }
        }
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            if(a[i] == 0) cnt++;
            // cout << a[i] << " ";
        }
        cout << (((cnt * (cnt - 1)) % mod) * fac[n - 2]) % mod << endl;
    }
}