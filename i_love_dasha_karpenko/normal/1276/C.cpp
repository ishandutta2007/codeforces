#include <bits/stdc++.h>

using namespace std;
#define fi first
#define sc second
#define forn(i,n) for(ll i = 1;i<=n;i++)
#define pb push_back
typedef long long ll;
typedef pair<ll,ll> pp;
const ll DIM = 4*10E4+7;
const ll INF = 10E18+173;
const ll DIM2 = sqrt(DIM);
pp C[DIM];
ll A[DIM];
vector<vector<ll> > result;
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin>>n;
    forn(i,n)cin>>A[i];
    sort(A+1,A+1+n);
    ll p = 1;
    A[0] = -INF;
    ll cnt = 1;
    for(ll i = 2;i<=n;i++){
        if (A[i]==A[i-1]){
            cnt++;
        }
        else{
            C[p].fi = cnt;
            C[p].sc = A[i-1];
            p++;
            cnt = 1;
        }
    }
    C[p].fi = cnt;
    C[p].sc = A[n];
    sort(C+1,C+1+p);
    ll res = 0;
    ll l = 1,sq = sqrt(n),pe = 1,tt = 0;
    forn(i,sq){
        while(pe<=n && C[pe].fi==i){
            tt++;
            pe++;
        }
        tt+=p-pe+1;
        if (res<tt/i*i && tt/i>=i){
            res=tt/i*i;
            l = i;
        }
    }
    reverse(C+1,C+1+p);
    ll take = 0;
    forn(i,p){
        take+=min(l,C[i].fi);
    }
    take/=l;
    cout<<take*l<<endl;
    cout<<l<<' '<<take<<endl;
    result.resize(l+1);
    forn(i,l)result[i].resize(take+1);
    pp pos = {1,1},stpos = {1,1};
    forn(i,p){
        ll f = min(l,C[i].fi);
        forn(k,f){
            result[pos.fi][pos.sc] = C[i].sc;
            pos.fi++;
            pos.sc++;
            if (pos.fi>l){
                pos.fi = 1;
                pos.sc = stpos.sc+1;
                stpos = pos;
            }
            if (pos.sc>take)pos.sc-=take;
        }
    }
    forn(i,l){
        forn(j,take)cout<<result[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}
// 5 4 1 2 3 4 5 2 1 3