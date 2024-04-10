#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;
#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
const ll DIM = 3*10E4+7;
const ll INF = 10E17;
const ld eps = 0.00000001;
const ll MOD = 10E8+7;
struct matrix{
    ll n,m;
    vector<vector<ll> >A;
    void resize(ll n1,ll m1){
        n = n1;
        m = m1;
        A.resize(n+1);
        forn(i,n)A[i].resize(m+1);
    }
};
matrix mult(matrix &a,matrix &b){
    matrix c;
    c.resize(a.n,b.m);
    forn(i,c.n){
        forn(j,c.m){
            c.A[i][j] = 0;
            forn(k,a.m){
                c.A[i][j] = (c.A[i][j]+a.A[i][k]*b.A[k][j])%MOD;
            }
        }
    }
    return c;
}
matrix pow(matrix &a,ll power){
    power--;
    matrix base = a,mu = a;
    while(power>0){
        if (power&1)base = mult(base,mu);
        mu = mult(mu,mu);
        power/=2;
    }
    return base;
}
struct node{
    ll p,pos,h;
};
const bool operator<(const node &a,const node &b){
    return a.pos<b.pos;
}
vector<node> evs;
void form(matrix &path,ll h){
    forn(i,16){
        forn(j,16){
            if (i<=h && j<=h && abs(i-j)<=1)path.A[i][j] = 1;
            else path.A[i][j] = 0;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,k;
    cin>>n>>k;
    k++;
    forn(i,n){
        ll a,b,c; cin>>a>>b>>c;
        c++;
        a++;
        b++;
        evs.pb({i,a,c});
        evs.pb({i+n,b,c});

    }
    sort(evs.begin(),evs.end());
    matrix path;
    matrix state;
    state.resize(16,1);
    path.resize(16,16);
    forn(i,16)state.A[i][1] = 0;
    state.A[1][1] = 1;
    set<pp> S;
    ll pos = 1;
    for(ll i = 0;i<evs.size();i++){
        ll np = evs[i].pos;
        while(i+1<evs.size() && evs[i+1].pos==np){
            if (evs[i].p<=n)S.insert(pp{evs[i].h,evs[i].p});
            else S.erase({evs[i].h,evs[i].p-n});
            i++;
        }
        if (evs[i].p<=n)S.insert({evs[i].h,evs[i].p});
        else S.erase({evs[i].h,evs[i].p-n});
        np = min(np,k);
        ll delta = np-pos;
        if (delta!=0){

            path = pow(path,delta);
            state = mult(path,state);
            //cout<<state.A[1][1]<<endl;
        }
        form(path,S.begin()->fi);
        pos = np;
        //cout<<path.A[1][1]<<endl;
        if (np==k)break;
    }
    cout<<state.A[1][1]<<endl;
    //cout<<meth.A[3][1]<<endl;
    return 0;
}
// 9 7+2