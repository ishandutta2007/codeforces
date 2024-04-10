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
ll N;

int main(){
    cin >> T;
    while(T--){
        ll a,b;
        cin >> a >> b;
        ll ans = a +b;
        for(ll i = 1; i < 1000000007; i*=2){
            if((a&i) && (b&i))ans-=2*i;
        }
        cout << ans <<"\n";
    }
    return 0;
}