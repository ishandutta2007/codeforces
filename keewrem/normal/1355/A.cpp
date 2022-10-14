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

int T;
ll N,kk;
ll mmd(ll a){
    ll r = 0;
    while(a){
        r = max(r,a%10);
        a /= 10;
    }
    return r;
}

ll mxd(ll a){
    ll r = 9;
    while(a){
        r = min(r,a%10);
        a /= 10;
    }
    return r;
}

int main(){
    cin >> T;
    while(T--){
        cin >> N >> kk;
        for(int i = 1; i < kk && mxd(N)!=0; i++){
            N += mmd(N)*mxd(N);
        }
        cout << N << "\n";
    }
    return 0;
}