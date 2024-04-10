#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;

typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<pp,null_type,less<pp>,rb_tree_tag,tree_order_statistics_node_update> super_set;

#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
#define log sdfdsfdsf

const ll DIM = 250+7;
const ll MOD = 1e9+7;

const ll INF = 1E13;
const ld eps = 0.00000000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
    static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution <int> (a, b)(rng);
}
ll A[DIM][DIM],row[DIM],col[DIM],nr[DIM],nc[DIM];
pp rng[DIM];
pp cng[DIM];
ll match[DIM*DIM][2];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,m;
    cin>>n>>m;
    vector<pp> V1,V2;

    forn(i,n){
        ll mx = 0;
        forn(j,m){
            cin>>A[i][j];
            mx = max(mx,A[i][j]);
        }
        row[i] = mx;

    }
    forn(j,m){
        ll mx = 0;
        forn(i,n){
            mx = max(mx,A[i][j]);
        }
        col[j] = mx;

    }
    sort(row+1,row+1+n,greater<ll>());
    sort(col+1,col+1+m,greater<ll>());
    forn(i,n){
        match[row[i]][0] = i;
    }
    forn(i,m){
        match[col[i]][1] = i;
    }

    for(ll el = n*m;el>=1;--el){
        if (match[el][0]+match[el][1]){
            if (match[el][0] && match[el][1]){
                A[match[el][0]][match[el][1]] = el;
                rng[match[el][0]] = {match[el][1],match[el][1]};
                cng[match[el][1]] = {match[el][0],match[el][0]};
                continue;
            }
            if (match[el][0]){
                ll i = match[el][0];
                forn(j,m){
                    if (row[i]>=el && col[j]>=el && (cng[j]==pp{0,0} || cng[j].fi-1==i || cng[j].sc+1==i) &&
                    (rng[i]==pp{0,0} || rng[i].fi-1==j || rng[i].sc+1==j) ){
                        if (pp{0,0}==rng[i]){
                            rng[i] = {j,j};
                        }
                        else if (rng[i].fi-1==j){
                            rng[i].fi--;
                        }
                        else{
                            rng[i].sc++;
                        }
                        if (cng[j] == pp{0,0}){
                            cng[j] = {i,i};
                        }
                        else if (cng[j].fi-1==i)cng[j].fi--;
                        else cng[j].sc++;
                        A[i][j] = el;
                        break;
                    }
                }
                continue;
            }
            else{
                ll j = match[el][1];
                forn(i,n){
                if (row[i]>=el && col[j]>=el && (cng[j]==pp{0,0} || cng[j].fi-1==i || cng[j].sc+1==i) &&
                    (rng[i]==pp{0,0} || rng[i].fi-1==j || rng[i].sc+1==j) ){
                        if (pp{0,0}==rng[i]){
                            rng[i] = {j,j};
                        }
                        else if (rng[i].fi-1==j){
                            rng[i].fi--;
                        }
                        else{
                            rng[i].sc++;
                        }
                        if (cng[j] == pp{0,0}){
                            cng[j] = {i,i};
                        }
                        else if (cng[j].fi-1==i)cng[j].fi--;
                        else cng[j].sc++;
                        A[i][j] = el;
                        break;
                    }
                }
                continue;
            }
        }
        forn(i,n){
            ll nxt = rng[i].fi-1;
            ll len = nxt;
            if (nxt<=0){
                nxt = rng[i].sc+1;
                len = m-nxt+1;
            }
            ll l1 = 0;
            if (cng[nxt]!=pp{0,0}){
                if (cng[nxt].fi-1==i){
                    l1 = i;
                }
                else{
                    l1 = n-i+1;
                }
            }
            len = max(len,l1);
            if (row[i]>=el && col[nxt]>=el && (cng[nxt]==pp{0,0} || cng[nxt].fi-1==i || cng[nxt].sc+1==i)){
                A[i][nxt] = el;
                if (cng[nxt] == pp{0,0}){
                    cng[nxt] = {i,i};
                }
                else if (cng[nxt].fi-1==i)cng[nxt].fi--;
                else cng[nxt].sc++;
                ll j = nxt;
                if (pp{0,0}==rng[i]){
                    rng[i] = {j,j};
                }
                else if (rng[i].fi-1==j){
                    rng[i].fi--;
                }
                else{
                    rng[i].sc++;
                }
                break;
            }
        }
    }
    forn(i,n){
        forn(j,m)cout<<A[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}