//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
#define x1 dfgfg
#define y1 dfgdfg
const ll DIM = 7007;
const ll INF = 1E9+7;
ll A[507][507],sal[DIM],RP[DIM],P[DIM],vis[DIM],RA[DIM];
ll F(ll x){
    if (x==P[x])
        return x;
    return P[x] = F(P[x]);
}
void unite(ll a,ll b){
    a = F(a);
    b = F(b);
    if (a==b)
        return;
    if (rand()%2)swap(a,b);
    P[a] = b;
}
ll get(ll x){
    if (x==RP[x])return x;
    return RP[x] = get(RP[x]);

}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    set<ll> S;
    for(ll i = 1;i<=n;++i) {
        RP[i] = RA[i] = i;
        for (ll j = 1; j <= n; ++j) {
            cin>>A[i][j];
            if (i==j)
                sal[i] = A[i][j];
            else
                S.insert(A[i][j]);
        }
    }
    ll ptr = n;
    for(auto it = S.begin();it!=S.end();it++) {
        ll val = *it;
        for (ll i = 1; i <= ptr; ++i) {
            P[i] = i;
            vis[i] = 0;
        }
        for (ll i = 1; i <= n; ++i) {
            for (ll j = 1; j <= n; ++j) {
                if (i == j)continue;
                if (A[i][j] == val) {
                    vis[i] = vis[j] = 1;
                    unite(i,j);
                }
            }
        }
        for (ll i = 1; i <= n; ++i) {
            for (ll j = 1; j <= n; ++j) {
                if (i == j)continue;
                if (A[i][j] == val) {
                    vis[i] = vis[j] = 1;
                    unite(i,j);
                }
            }
        }

        map<ll, ll> M;

        for (ll i = 1; i <= n; ++i) {
            if (vis[i] == 0)
                continue;
            if (M.count(F(i))==0) {
                M[F(i)] = ++ptr;
                RA[ptr] = RP[ptr] = ptr;
                P[ptr] = ptr;
                sal[ptr] = val;
            }
            RA[get(i)] = M[F(i)];
            RP[get(i)] = M[F(i)];
        }


    }


    ll cnt = 0,mx = *S.rbegin();
    for(ll i = 1;i<=ptr;++i){
        if (sal[i]==mx){
            ++cnt;
        }

    }
    ll root = ptr;
    if (cnt>1){
        ++ptr;
        sal[ptr] = mx+1;
        root = ptr;
    }
    for(ll i = 1;i<=ptr;++i){
        if (get(i)==i){
            RA[i] = root;
        }
    }
    cout<<ptr<<endl;
    for(ll i = 1;i<=ptr;++i)
        cout<<sal[i]<<' ';
    cout<<endl;
    cout<<root<<endl;
    for(ll i = 1;i<=ptr;++i){
        if (i!=root)
            cout<<i<<' '<<RA[i]<<endl;
    }







    return 0;
}