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
ll block[4];
struct node{
    ll p,ceil,pos;
};
const bool operator<(const node &a,const node &b){
    return a.pos<b.pos;
}
vector<node> evs;
struct matrix{
    ll w,h;
    vector<vector<ll> > A;
    matrix(ll h1,ll w1){
        h = h1;
        w = w1;
        A.resize(h+1);
        forn(i,h)A[i].resize(w+1);
    }
    matrix mult(matrix &a){
        matrix c(h,a.w);
        forn(i,h){
            forn(j,a.w){
                c.A[i][j] =0;
                forn(k,w){
                    c.A[i][j] = (c.A[i][j]+A[i][k]*a.A[k][j])%MOD;
                }
            }
        }
        return c;
    }
};
matrix pow(matrix &a,ll power){
    matrix base = a,mu = a;
    power--;
    while(power>0){
        if (power&1)base = base.mult(mu);
        mu = mu.mult(mu);
        power/=2;
    }
    return base;
}
void form(matrix &path){
    forn(i,3){
        forn(j,3){
            if (block[i]==0 && block[j]==0 && abs(i-j)<=1)path.A[i][j] = 1;
            else path.A[i][j] = 0;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,m;
    cin>>n>>m;
    forn(i,n){
        ll a,l,r;
        cin>>a>>l>>r;
        evs.pb({0,a,l});
        evs.pb({1,a,r});
    }

    sort(evs.begin(),evs.end());
    matrix path(3,3);
    form(path);
    ll pos = 1;
    matrix meth(3,1);
    meth.A[3][1] = 0;
    meth.A[1][1] = 0;
    meth.A[2][1] = 1;
    for(ll i = 0;i<evs.size();i++){
        ll np = evs[i].pos;
        while(i+1<evs.size() && evs[i+1].pos==np){
            if (evs[i].p==0)block[evs[i].ceil]++;
            else block[evs[i].ceil]--;
            i++;
        }
        if (evs[i].p==0)block[evs[i].ceil]++;
        else block[evs[i].ceil]--;
        ll delta = np-pos;
        if (delta!=0){
            path = pow(path,delta);
            meth = path.mult(meth);
            //cout<<path.A[1][1]<<endl;
        }
        pos = np;
        form(path);
    }
    if (m!=pos){
        path = pow(path,(m-pos));
        meth = path.mult(meth);
    }
    cout<<meth.A[2][1]<<endl;
    //cout<<meth.A[3][1]<<endl;
    return 0;
}
// 9 7+2