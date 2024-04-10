//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
//#define endl '\n'
const ll DIM = 2000+7;
ll A[DIM][DIM];
ll vis[DIM],n;
vector<ll> V ;
void ask(ll v){
    cout<<"? "<<v<<endl;
    for(ll i = 1;i<=n;++i){
        ll d;
        cin>>d;
        if (d==1)
            A[v][i] = A[i][v] = 1;
        if (d==2 && vis[i]==0){
            vis[i] = 1;
            //V.push_back(i);
        }
    }
}
ll D[DIM];
void solve(){
    cin>>n;

    vis[1] = 1;
    cout<<"? 1"<<endl;
    ll cnt[] = {0,0};
    for(ll i = 1;i<=n;++i) {
        cin >> D[i];
        if (i>1)
            ++cnt[D[i]%2];
        if (D[i]==1)
            A[i][1] = A[1][i] = 1;
    }
    ll need;
    if (cnt[0]<cnt[1])
        need = 0;
    else need = 1;
    for(ll i = 2;i<=n;++i){
        if (D[i]%2==need)V.push_back(i);
    }

    while(!V.empty()){
        ll a = V.back();
        V.pop_back();
        ask(a);

    }
    cout<<"!\n";
    for(ll i = 1;i<=n;++i){
        for(ll j = i+1;j<=n;++j){
            if (A[i][j])cout<<i<<' '<<j<<'\n';
        }
    }
    cout<<endl;
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);
    ll t = 1;
    while(t--)
        solve();
    return 0;
}