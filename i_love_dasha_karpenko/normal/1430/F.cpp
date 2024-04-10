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
#define endl '\n'
#define po(x) (1ll<<x)
#define log sdfdsfdsf

const ll DIM = 2E3+7;

const ll MOD = 1e9+7;

const ll INF = 1E18+70;
const ld eps = 0.00000000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
    static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution <int> (a, b)(rng);
}
struct node{
    ll l,r,a;
} A[DIM];
ll n,k;
ll dp[DIM][DIM],dp1[DIM][DIM],dp2[DIM][DIM],dp3[DIM][DIM],pref[DIM],D[DIM],D1[DIM];
void calc(ll l){
    ll cur = k;
    ll cnt = 0;
    for(ll i = l;i<=n;++i){
        if (A[i].r<A[i].l){
            for(ll j = i;j<=n;++j)
                dp[l][j] = INF;
            return;
        }
        ll can = cur+(A[i].r-A[i].l)*k;
        cnt+=A[i].a;
        if (can<A[i].a){
            for(ll j = i;j<=n;++j)
                dp[l][j] = INF;
            return;
        }
        cur = ((k-(A[i].a-cur))%k+k)%k;
        dp[l][i] = cur+cnt;
    }

}
void calc1(ll l){
    ll cur = k;
    ll cnt = 0;
    for(ll i = l;i<=n;++i){
        ll bc = cur,bct = cnt;
        {
            A[i].r--;
            ll can = cur+(A[i].r-A[i].l)*k;
            cnt+=A[i].a;
            if (A[i].r<A[i].l){

                dp1[l][i] = INF;
            }

            else if (can<A[i].a){
                dp1[l][i] = INF;
            }
            else{
                cur = ((k-(A[i].a-cur))%k+k)%k;
                dp1[l][i] = cur+cnt;

            }
            A[i].r++;
        }
        cur = bc;
        cnt = bct;
        if (A[i].r<A[i].l){
            for(ll j = i;j<=n;++j)
                dp1[l][j] = INF;
            return;
        }
        ll can = cur+(A[i].r-A[i].l)*k;
        cnt+=A[i].a;
        if (can<A[i].a){
            for(ll j = i;j<=n;++j)
                dp1[l][j] = INF;
            return;
        }
        cur = ((k-(A[i].a-cur))%k+k)%k;
    }
}
void calc2(ll l){
    ll cur = k;
    ll cnt = 0;
    for(ll i = l;i<=n;++i){

        if (A[i].r<A[i].l){

            for(ll j = i;j<=n;++j)
                dp2[l][j] = INF;
            return;
        }
        ll can = cur+(A[i].r-A[i].l)*k;
        cnt+=A[i].a;
        if (can<A[i].a){

            for(ll j = i;j<=n;++j)
                dp2[l][j] = INF;
            return;
        }

        cur = ((k-(A[i].a-cur))%k+k)%k;
        dp2[l][i] = cur+cnt;
    }
}
void calc3(ll l){
    ll cur = k;
    ll cnt = 0;
    for(ll i = l;i<=n;++i){
        ll bc = cur,bct = cnt;
        {
            A[i].r--;
            ll can = cur+(A[i].r-A[i].l)*k;
            cnt+=A[i].a;
            if (A[i].r<A[i].l){

                dp3[l][i] = INF;
            }

            else if (can<A[i].a){
                dp3[l][i] = INF;
            }
            else{
                cur = ((k-(A[i].a-cur))%k+k)%k;
                dp3[l][i] = cur+cnt;

            }
            A[i].r++;
        }
        cur = bc;
        cnt = bct;
        if (A[i].r<A[i].l){
            for(ll j = i;j<=n;++j)
                dp3[l][j] = INF;
            return;
        }
        ll can = cur+(A[i].r-A[i].l)*k;
        cnt+=A[i].a;
        if (can<A[i].a){
            for(ll j = i;j<=n;++j)
                dp3[l][j] = INF;
            return;
        }
        cur = ((k-(A[i].a-cur))%k+k)%k;
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n>>k;
    forn(i,n){
        cin>>A[i].l>>A[i].r>>A[i].a;
    }
    forn(i,n){

        A[i].l++;


        calc(i);


        A[i].l--;

    }
    forn(i,n){


        calc1(i);


    }
    forn(i,n){

        calc2(i);

    }

    forn(i,n){
        A[i].l++;
        calc3(i);
        A[i].l--;
    }
    forn(i,n){
        pref[i] = pref[i-1]+A[i].a;
        D[i] = INF;
        D1[i] = INF;
        for(ll j = i;j>=1;--j){

            ll r = min(D1[j-1]+dp2[j][i],D[j-1]+dp[j][i]);
            if (A[j].l!=A[j-1].r){
                r = min(r,D[j-1]+dp2[j][i]);
            }
            r = min(r,INF);
            D[i] = min(D[i],r);
            ll r1 = min(dp1[j][i]+D1[j-1],dp3[j][i]+D[j-1]);
            if (A[j].l!=A[j-1].r){
                r1 = min(r1,D[j-1]+dp1[j][i]);
            }
            r1 = min(r1,INF);
            D1[i] = min(D1[i],r1);
        }
    }

    ll res = INF;
    forn(j,n){
        if (dp[j][n]<INF){

            res = min(res,pref[n]-pref[j-1]+D[j-1]);
        }
        if (dp2[j][n]<INF){
            res = min(res,pref[n]-pref[j-1]+D1[j-1]);
            if (A[j].l!=A[j-1].r)
                res = min(res,pref[n]-pref[j-1]+D[j-1]);
        }

    }
    if (res==INF)cout<<-1<<endl;
    else
    cout<<res<<endl;
    return 0;


}