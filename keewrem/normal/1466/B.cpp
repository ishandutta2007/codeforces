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
ll N;

void solve(){
    cin >> N;
    vi v(N);
    for(auto &x: v)cin >> x;
    vi p(2*N+2,0);
    reverse(v.begin(),v.end());
    for(auto x: v){
        if(p[x+1]==0){
            x++;
        }
        p[x]=1;
    }
    int ans = 0;
    for(auto x: p)ans+=x;
    cout << ans << "\n";
}

int main(){
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}