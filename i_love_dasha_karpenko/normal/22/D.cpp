#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pp;
const ll DIM = 200007;
const ll INF = 10000000007;
#define forn(i,n) for(ll i = 1;i<=n;i++)
#define pb push_back
#define fi first
#define sc second

ll n;
pp A[DIM];
bool mc(pp a,pp b){
    return a.sc<b.sc;
}
int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    forn(i,n){
    cin>>A[i].fi>>A[i].sc;
    if (A[i].fi>A[i].sc)swap(A[i].fi,A[i].sc);
    }
    sort(A+1,A+1+n,mc);
    ll last = -INF;
    vector<ll> ans;
    forn(i,n){
        if (A[i].fi>last){
            last = A[i].sc;
            ans.pb(last);
        }
    }

    cout<<ans.size()<<endl;
    for(ll to:ans)cout<<to<<' ';
    cout<<endl;
    return 0;
}