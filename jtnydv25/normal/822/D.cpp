#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
const int N = 5e6 + 10;
int factor[N];
long long f[N];
void pre(){
    for(int i = 2;i*i<N;i++) 
        if(!factor[i]) 
            for(int j = i*i;j<N;j+=i){
                if(!factor[j]) factor[j] = i;
            }
    for(int i = 2; i < N; i++) if(!factor[i]) factor[i] = i;       
    f[1] = 0;
    for(int i = 2; i < N; i++){
        int d = factor[i];
        f[i] = f[i / d] + ((i * 1ll * (d - 1)) >> 1);
    }
}
int main(){
    pre();
    int l, r, t;
    cin >> t >> l >> r;
    ll ans = 0, x = t;
    for(int i = r; i >= l; i--) ans = (ans * x + f[i]) % mod;
    cout << ans;
}