#include<bits/stdc++.h>
using namespace std;
#pragma gcc optimize("03")
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int T = 1;
ll N;
ll mobi[75];
vi p = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67};
bool check(ll mx, ll b, ll exp){
//    cout <<"check "<< mx << " "<<b << " " << exp<<"\n";
    if(b < 2)return 1;
    while(exp){
        if(exp&1)mx/=b;
        exp/=2;
        if(mx == 0)break;
        if(b > INT_MAX)b = LLONG_MAX;
        else b *= b;
    }
//    cout <<"mx "<< mx << "\n";
    return mx > 0;
}
void solve(){

    cin >> N;
    ll ans = 0;
    for(ll i = 1; i < 61; i++){
        ll bs = 0;
        for(ll j = 1LL<<(60/i+2); j > 0; j/=2){
            //cout << "j "<<j << "\n";
            if(check(N,bs+j,i))bs += j;
        }
        //cout << "i bs "<<i << " "<<bs << "\n";
        ans+=mobi[i] * (bs-1);
    }
    cout << ans <<"\n";
    //sesso
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    for(ll i = 1; i < 70; i++){
        mobi[i] = 1;
        for(int j = 2; j < 9; j++){
            if(i % (j*j) == 0)mobi[i] = 0;
        }
        for(int x: p)if(i % x == 0)mobi[i]*=-1;
    }
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}