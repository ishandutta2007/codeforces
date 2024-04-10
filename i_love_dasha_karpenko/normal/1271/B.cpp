#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> satan_set;
#define forn(i,n) for(ll i = 1;i<=n;i++)
#define pb push_back
#define fi first
#define sc second
#define x1 dsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll DIM = 1000+7;
const ll INF = 10e16;
const ll MOD = 998244353 ;
ll A[DIM];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin>>n;

    forn(i,n){
        char ch ; cin>>ch;
        if (ch=='B')A[i] = 1;
        else A[i] = 0;
    }
    vector<ll> ans1,ans2;
    ll f = 0;
    forn(i,n){
        ll r = A[i]^f;
        if (r==1){
            ans1.pb(i);
            f = 1;
        }
        else f = 0;
    }
    ll flag1 = 0, flag2 = 0;
    if (f==1)flag1 = 1;
    f = 0;
    forn(i,n){
        ll r = A[i]^f;
        if (r==0){
            ans2.pb(i);
            f = 1;
        }
        else f = 0;
    }
    if (f==1)flag2 = 1;
    if (flag1==flag2 && flag1==1){
        cout<<"-1\n";
    }
    else if (flag1==1){
        cout<<ans2.size()<<endl;
        for(ll to:ans2)cout<<to<<' ';
        cout<<endl;
    }
    else if (flag2==1){
        cout<<ans1.size()<<endl;
        for(ll to:ans1)cout<<to<<' ';
        cout<<endl;
    }
    else if (ans1.size()<ans2.size()){
        cout<<ans1.size()<<endl;
        for(ll to:ans1)cout<<to<<' ';
        cout<<endl;
    }
    else{
        cout<<ans2.size()<<endl;
        for(ll to:ans2)cout<<to<<' ';
        cout<<endl;
    }
    return 0;

}