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
const ll INF = 1E18;
typedef pair<ll,ll> pp;
ll ans[DIM*2];
void NO(){
    cout<<"NO\n";
    exit(0);
}
ll a,b,c,d;
ll F(ll health){
    ll mid = (b*d+a*2)/(d*b*2);
    ll r = 0;
    for(ll i = mid-1;i<=mid+1;++i){
        r = min(r,-i*a+i*(i-1)/2*d*b);
    }
    if (health+r<=0)return 1;
    return 0;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){

        cin>>a>>b>>c>>d;
        if (a>b*c){
            cout<<-1<<endl;
            continue;
        }
        ll l = 1,r = INF;
        while(l!=r){
            ll tm = (l+r+1)/2;
            if (F(tm)) l = tm;
            else r = tm-1;
        }
        cout<<l<<endl;
    }
    return 0;

}