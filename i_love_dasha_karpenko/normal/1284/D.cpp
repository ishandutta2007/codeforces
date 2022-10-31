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
typedef long long ll;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> satan_set;
const ll DIM = 100000  +7;
const ll INF = 10E10;
struct node{
    ll fi,sc,a,b,pos;
};
const bool operator<(const node &a,const node &b){
    if (a.fi==b.fi)return a.sc<b.sc;
    return a.fi<b.fi;
}
const bool operator>(const node &a,const node &b){
    if (a.fi==b.fi)return a.sc>b.sc;
    return a.fi>b.fi;
}
node A[DIM];
ll sufA[DIM],prefB[DIM],prefA[DIM],sufB[DIM];
vector<pp> SA,SB,PA,PB;
int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin>>n;
    forn(i,n){
        cin>>A[i].fi>>A[i].sc>>A[i].a>>A[i].b;
        SA.pb({A[i].fi,i});
        PA.pb({A[i].sc,i});
        SB.pb({A[i].a,i});
        PB.pb({A[i].b,i});
    }
    sort(SA.begin(),SA.end());
    sort(SB.begin(),SB.end());
    sort(PA.begin(),PA.end());
    sort(PB.begin(),PB.end());
    forn(i,n){
        prefA[i] = prefA[i-1]+PA[i-1].sc;
        prefB[i]= prefB[i-1]+ PB[i-1].sc;
       // cout<<prefA[i]<<' ';
    }
   // cout<<endl;
    for(ll i = n;i>=1;i--){
        sufA[i] = sufA[i+1]+SA[i-1].sc;
        sufB[i] = sufB[i+1]+SB[i-1].sc;
        //cout<<sufA[i]<<' '<<sufB[i]<<endl;
    }
    forn(i,n){
        ll ha = 0;
        ll pos = lower_bound(PA.begin(),PA.end(),pp{A[i].fi,-INF})-PA.begin();
        ha+=prefA[pos];
        pos = upper_bound(SA.begin(),SA.end(),pp{A[i].sc,INF})-SA.begin();
        pos++;
        ha+=sufA[pos];
        ll hb = 0;
        // BBBBBBBBBBBBBBB
        pos = lower_bound(PB.begin(),PB.end(),pp{A[i].a ,-INF})-PB.begin();
        hb+=prefB[pos];
        pos = upper_bound(SB.begin(),SB.end(),pp{A[i].b,INF})-SB.begin();
        pos++;
        hb+=sufB[pos];
        if (ha!=hb){
            cout<<"NO\n";
            return 0;
        }
       // cout<<ha<<endl;
    }
    cout<<"YES\n";
    return 0;
}