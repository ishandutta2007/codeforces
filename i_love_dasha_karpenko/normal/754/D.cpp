#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds; //    
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pp;
const ll DIM = 300007;
const ll INF = 10000000007;
#define forn(i,n) for(ll i = 1;i<=n;i++)
#define pb push_back
#define fi first
#define sc second
struct node{
    ll fi,sc,pos;
};
const bool operator<(const node &a,const node &b){
    return a.fi<b.fi;
}
ll n,k;
node A[DIM];
set<pp> S;
int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    ll all =0 ;
    forn(i,n){
        cin>>A[i].fi>>A[i].sc;

        A[i].pos= i;
    }
    sort(A+1,A+1+n);

    ll mx = 0;
    forn(i,n){
        S.insert({A[i].sc,A[i].pos});
        while(S.size()>k){
            S.erase(S.begin());
        }
        if (S.size()==k){
            ll cur = (*S.begin()).fi-A[i].fi+1;
            mx = max(mx,cur);
        }
    }
    if (mx==0){
        cout<<"0\n";
        forn(i,k)cout<<i<<' ';
        cout<<endl;
        return 0;
    }
    S.clear();
     forn(i,n){
        S.insert({A[i].sc,A[i].pos});
        while(S.size()>k){
            S.erase(S.begin());
        }
        if (S.size()==k){
            ll cur =(* S.begin()).fi-A[i].fi+1;
            if (cur==mx){
                cout<<mx<<endl;
                for(pp to:S)cout<<to.sc<<' ';
                cout<<endl;
                return 0;
            }
        }
    }
    cout<<"0\n";
    forn(i,k)cout<<i<<' ';
    cout<<endl;
    return 0;
}