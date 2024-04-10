#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using namespace std;
typedef long long  ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> multi_set;
#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
const ll DIM = 507;
const ll INF = 1E9;
ll n,A[DIM][DIM],vis[DIM][DIM];
set<ll> S;
pp start;
ll cnt = 0;
void dfs(pp a){
    while(1){
        ++cnt;
        ll flag = 0;
        pp mx = {0,0};
        vis[a.fi][a.sc] = 1;
        forn(i,n){
            forn(j,n){
                if (vis[i][j]==1 || A[i][j]>A[mx.fi][mx.sc])continue;
                if (i-j==a.fi-a.sc || i+j==a.fi+a.sc || i==a.fi || j==a.sc){
                    mx = {i,j};
                }
            }
        }
        if (mx==pp{0,0})break;

        a = mx;
    }
}
void ldfs(pp a){
    while(1){
        ++cnt;
        ll flag = 0;
        pp mx = {0,0};
        vis[a.fi][a.sc] = 1;
        cout<<a.fi<<' '<<a.sc<<endl;
        forn(i,n){
            forn(j,n){
                if (vis[i][j]==1 || A[i][j]>A[mx.fi][mx.sc])continue;
                if (i-j==a.fi-a.sc || i+j==a.fi+a.sc || i==a.fi || j==a.sc){
                    mx = {i,j};
                }
            }
        }
        if (mx==pp{0,0})break;

        a = mx;
    }
}
void dfs1(pp a){
    while(1){
        ++cnt;
        ll flag = 0;
        pp mx = {0,0};
        vis[a.fi][a.sc] = 1;
        forn(i,n){
            forn(j,n){
                if (vis[i][j]==1 || A[i][j]>A[mx.fi][mx.sc])continue;
                if (i==a.fi || j==a.sc){
                    mx = {i,j};
                }
            }
        }
        if (mx==pp{0,0})break;

        a = mx;
    }
}
void rec(ll i,ll j){
    if (i>n){
        memset(vis,0,sizeof(vis));
        cnt = 0;
        dfs(start);

        ll f1 = cnt;
        cnt = 0;
        memset(vis,0,sizeof(vis));
        dfs1(start);
        ll f2 = cnt;
        if (f1!=n*n && f2==n*n){
            memset(vis,0,sizeof(vis));
            //ldfs(start);
            //cout<<endl;
            forn(ii,n){
                forn(jj,n)cout<<A[ii][jj]<<' ';
                cout<<endl;
            }
            exit(0);
        }
    }
    forn(num,n*n){
        if (S.count(num)==1)continue;
        S.insert(num);
        A[i][j] = num;
        ll ni = i;
        ll nj = j;
        if (num==1)start = {i,j};
        if (j==n){
            ni++;
            nj = 1;
        }
        else nj++;
        A[i][j] = num;
        rec(ni,nj);
        S.erase(num);
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    A[0][0] = INF;
    cin>>n;
    if (n<3){
        cout<<"-1\n";
        return 0;
    }
    if (n<=5){
        rec(1,1);
    }
    ll cur = 1;

    forn(i,n-1){
        forn(j,n){
            if (j==n && i==n-1)break;
            cout<<cur++<<' ';
        }
        if (i!=n-1)
        cout<<endl;
    }
    cout<<cur+2<<endl;
    ll st = cur;
    cout<<cur<<' ';
    cout<<cur+3<<' ';

    cur+=4;
    forn(i,n-5)cout<<cur++<<' ';
    cout<<cur+1<<' ';
    cout<<st+1<<' ';
    cout<<cur<<endl;
    return 0;
}