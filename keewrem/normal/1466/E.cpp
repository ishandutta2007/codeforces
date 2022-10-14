#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD = 1000000007;
int T = 1;
ll N;
ll pw[300];
void solve(){
    cin >> N;
    vll v(N);
    for(auto &x: v)cin >> x;
    vll cnt(60,0);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 60; j++){
            if(1LL<< j & v[i])cnt[j]++;
        }
    }
    ll sor, sand;
    ll ans = 0;
    for(int i = 0; i < N; i++){
        sor = 0; sand = 0;
        for(int j = 0; j < 60; j++){
            if(v[i] & (1LL<<j)){
                sor+=N*pw[j];
                sand+=cnt[j]*pw[j];
            }else{
                sor+=pw[j]*cnt[j];
            }
            sor%=MOD;
            sand%=MOD;
        }
        ans = (ans+sor*sand)%MOD;
    }
    cout << ans << "\n";
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(NULL);
    pw[0] = 1;
    for(int i = 1; i < 300; i++){
        pw[i] = 2*pw[i-1];
        pw[i]%=MOD;
    }
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}