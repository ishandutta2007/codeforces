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

int T = 1;
ll N,M;

void solve(){
    cin >> N >> M;
    vi v(N),b(M);
    ll ans = 0;
    for(auto &x: v){cin >> x; x--;}
    for(auto &x: b)cin >> x;
    sort(v.rbegin(),v.rend());
    int ind = 0;
    for(auto x: v){
        if(x > ind){
            ans += b[ind++];
        }else{
            ans += b[x];
        }
    }
    cout << ans << "\n";
    return;
}

int main(){
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}