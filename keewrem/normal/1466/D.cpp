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
    vector<pll> v(N);
    ll ans = 0;
    ll k;
    for(int i = 0; i < N; i++){
        cin >> k;
        v[i]={k,i}; ans+=k;
    }
    vi deg(N,-1);
    ll a,b;
    for(int i = 1; i < N; i++){
        cin >> a >> b; deg[a-1]++; deg[b-1]++;
    }
    sort(v.rbegin(),v.rend());
    int ind = 0;
    for(int i = 1; i < N; i++){
        cout << ans << " ";
        if(i == N-1)break;
        while(deg[v[ind].se] <= 0 && ind<N-1){
            ind++;
        }
        ans+=v[ind].fi; deg[v[ind].se]--;
    }
    cout << "\n";
}
int main(){
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}