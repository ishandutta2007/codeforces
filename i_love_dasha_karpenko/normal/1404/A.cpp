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

const ll DIM = 3E5+7;
const ll INF = 1E19;
const ll MAXN = 50;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}
ll A[DIM],P[DIM],flag = 0;
ll F(ll x){
    if (x==P[x])return x;
    return P[x] = F(P[x]);
}
void unite(ll a,ll b){
    a = F(a);
    b = F(b);
    if (a==b)return;
    if (A[a]<2 && A[b]<2 && A[a]!=A[b])flag = 1;
    ll c = min(A[a],A[b]);
    if (rand()%2)swap(a,b);
    P[b] = a;
    A[a] = c;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){

        ll n,k;
        cin>>n>>k;
        ll cnt1 = 0,cnt2 = 0;
        A[0] = 2;
        flag = 0;

        forn(i,n)P[i] = i;
        P[0] = 0;
        forn(i,n){
            char ch;
            cin>>ch;
            if (ch=='0')A[i] = 0;
            if (ch=='1')A[i] = 1;
            if (ch=='?'){
                A[i] = 2;

            }

            if (i>=k){

                unite(i-k,i);

            }
        }
        forn(i,n){
            A[i] = A[F(i)];
            if (A[i]==1)++cnt1;
            if (A[i]==0) ++cnt2;
            if (i>=k){
                    if (i-k>0){
                    if (A[i-k]==1)--cnt1;
                    if (A[i-k]==0)--cnt2;
                }
                if (cnt1>k/2 || cnt2>k/2)flag = 1;

            }
        }
        if (flag)cout<<"NO\n";
        else cout<<"YES\n";

    }


    return 0;
}