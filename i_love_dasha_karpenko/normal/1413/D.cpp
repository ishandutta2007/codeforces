#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x1 dfds
#define y1 dsfdsfe
#define endl '\n'
#define sc second
#define pb push_back
#define fi first
const ll DIM = 1E5+7;
typedef pair<ll,ll> pp;
ll ans[DIM*2];
void NO(){
    cout<<"NO\n";
    exit(0);
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    set<ll> S;
    set<ll> S1;
    vector<pp> V;
    for(ll i = 1;i<=n*2;++i){
        char type;
        cin>>type;
        if (type=='-'){
            ll x;
            cin>>x;
            V.pb({x,i});
            S1.insert(i);
            ans[i] = -x;
        }
        else{
            S.insert(i);

        }
    }
    sort(V.begin(),V.end());
    for(pp to:V){
        S1.erase(to.sc);
        auto it = S.lower_bound(to.sc);
        if (it==S.begin()){
            NO();
        }
        it = prev(it);
        ans[*it] = to.fi;
        S.erase(it);

    }

    S.clear();
    ll flag = 0;
    for(ll i = 1;i<=n*2;++i){
        if (ans[i]>0){
            S.insert(ans[i]);
        }
        else if (ans[i]<0){
            if (*S.begin()!=-ans[i])NO();
            S.erase(S.begin());
        }
    }

    cout<<"YES\n";
    for(ll i = 1;i<=n*2;++i){
        if (ans[i]>0)cout<<ans[i]<<' ';
    }
    cout<<endl;
    return 0;

}