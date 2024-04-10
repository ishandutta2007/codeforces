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
ll N,s;
ll sus(ll a){
    ll ans = 0;
    while(a){
        ans+=a%10LL;
        a/=10LL;
    }
    return ans;
}
int main(){
    cin >> T;
    while(T--){
        cin >> N >> s;
        ll ans = 1000000000000000000LL;
        ll cur = 1000000000000000000LL;
        ll ses;
        if(sus(N)<=s)ans = 0;
        for(int i = 18; i >= 0; i--){
            ses = N-(N%cur)+cur;
            if(sus(ses)<=s)ans = min(ans,ses-N);
            cur/=10LL;
        }
        cout << ans <<"\n";
    }
    return 0;
}