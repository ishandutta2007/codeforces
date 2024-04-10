#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;

#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
#define log sdfdsfdsf

const ll DIM = 2E5+7;

const ll INF = 2E18;
const ld eps = 0.0000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}

ll A[DIM],B[DIM],vis[DIM],cp[DIM],cmp = 0,clk[DIM],sz[DIM],rev[DIM];
vector<ll> co[DIM];
ll n;
void clearall(){
    cmp = 0;
    forn(i,n){
        A[i] = B[i] = 0;
        vis[i] = 0;
        co[i].clear();
        clk[i] = sz[i] = rev[i] = 0;
        cp[i] = 0;
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll ttt;
    cin>>ttt;
    while(ttt--){

        cin>>n;
        forn(i,n){
            cin>>A[i];
            co[A[i]].pb(i);
        }
        forn(i,n){
            cin>>B[i];
            co[B[i]].pb(i);
        }
        ll flag = 0;
        forn(i,n){
            if (co[i].size()!=2){
                flag = 1;
                break;
            }
        }
        if (flag){
            cout<<"-1\n";
            clearall();
            continue;
        }

        forn(i,n){
            if (vis[i]==1 || A[i]==B[i])continue;
            queue<ll> Q;
            Q.push(i);
            vis[i] = 1;
            ++cmp;
            while(!Q.empty()){
                ll t = Q.front();
                cp[t] = cmp;
                sz[cmp]++;
                Q.pop();
                ll an = co[A[t]][0]^co[A[t]][1]^t;
                if (A[an]==A[t]){
                    if (vis[an]==1){
                        flag = 1;
                        break;
                    }
                    swap(A[an],B[an]);
                    vis[an] = 1;
                    rev[an] = 1;
                    clk[cmp]++;
                    Q.push(an);
                }
                else if (vis[an]==0){
                    Q.push(an);
                    vis[an] = 1;
                    rev[an] = 0;
                }
                ll bn = co[B[t]][0]^co[B[t]][1]^t;
                if (B[t]==B[bn]){
                    if (vis[bn]==1){
                        flag = 1;
                        break;
                    }
                    vis[bn] = 1;
                    swap(A[bn],B[bn]);
                    rev[bn] = 1;
                    clk[cmp]++;
                    Q.push(bn);
                }
                else if (vis[bn]==0){
                    Q.push(bn);
                    vis[bn] = 1;
                    rev[bn] = 0;
                }
            }
            if (flag)break;
        }
        if (flag)cout<<"-1\n";
        else{
            ll sum = 0;
            forn(i,n){
                ll x = rev[i]^(clk[cp[i]]>sz[cp[i]]-clk[cp[i]]);
                sum+=x;
            }
            ll rs = 0;
            forn(i,n){
                rs+=min(clk[i],sz[i]-clk[i]);
            }
            if (rs!=sum)n/=0;
            cout<<sum<<endl;
            forn(i,n){
                ll x = rev[i]^(clk[cp[i]]>sz[cp[i]]-clk[cp[i]]);;
                if (x)cout<<i<<' ';
            }
            cout<<endl;
        }
        clearall();
    }
    return 0;
}
// (i-1)%p
// l = A[i],r = A[i+1]
// 001011
// 001110
// 011010
// 110010
// 1110
// 11 - 8 11-8+1-3 = 1
// 11 10 8
// 1001100
// 4,3,2,6,