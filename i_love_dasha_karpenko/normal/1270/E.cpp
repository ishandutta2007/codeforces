#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fi first
#define sc second
#define forn(i,n) for(ll i = 1;i<=n;i++)
#define pb push_back
#define endl '\n'
#define x1 dsfdsfes
#define y1 sfsdfdse
#define po(x) (1ll<<x)
typedef long long ll;
typedef pair<ll,ll> pp;
typedef tree<pp,null_type,less<pp>,rb_tree_tag,tree_order_statistics_node_update> super_set;
const ll DIM = 3*10E4+107;
const ll INF = 10E17;
const ll MAXN = 10E5+1;
struct node{
    ll fi,sc,pos;
};
vector<node> group[2][2];
ll c;
void solve(){

    while(group[0][1].size()==c || group[1][1].size()==c || group[1][0].size()==c || group[0][0].size()==c ){
        if (group[1][1].size()==c){
            for(ll i = 0;i<group[1][1].size();i++){
                group[1][1][i].fi++;
                group[1][1][i].sc++;
            }
            swap(group[1][1],group[0][0]);
        }
        else if (group[1][0].size()==c){
            for(ll i = 0;i<group[1][0].size();i++){
                group[1][0][i].fi++;
            }
            swap(group[1][0],group[0][0]);
        }
        else if (group[0][1].size()==c){
            for(ll i = 0;i<group[0][1].size();i++){
                group[0][1][i].sc++;
            }
            swap(group[0][1],group[0][0]);
        }
        vector<node> V;
        for(node to:group[0][0]){
            to.fi/=2;
            to.sc/=2;
            if (to.fi%2+to.sc%2==0)V.pb(to);
            else group[to.fi%2][to.sc%2].pb(to);
        }
        group[0][0] = V;

    }
}
int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    c = n;
    forn(i,n){
        ll x,y; cin>>x>>y;
        x+=MAXN;
        y+=MAXN;
        group[x%2][y%2].pb({x,y,i});
    }

    solve();

    if (group[1][0].size()+group[0][1].size()!=0 && group[1][1].size()+group[0][0].size()!=0){
        cout<<group[1][0].size()+group[0][1].size()<<endl;
        for(node to:group[1][0])cout<<to.pos<<' ';
        for(node to:group[0][1])cout<<to.pos<<' ';
        return 0;
    }
    if (group[1][1].size()!=0 && group[0][0].size()!=0){
        cout<<group[1][1].size()<<endl;
        for(node to:group[1][1])cout<<to.pos<<' ';
        return 0;
    }
    if (group[1][0].size()!=0){
        cout<<group[1][0].size()<<endl;
        for(node to:group[1][0])cout<<to.pos<<' ';
        return 0;
    }
    return 0;
}