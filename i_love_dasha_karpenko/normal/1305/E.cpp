#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;

#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
//#define endl '\n'
#define po(x) (1ll<<x)
const ll DIM = 5000+7;
const ll INF = 10E16;
const ll MAXN = 10E8;
ll n,m,A[DIM];

ll can(ll x,ll pos){
    ll cnt = 0;
    stack<ll> S;
    forn(i,pos-1){
        while(!S.empty() && S.top()>x-A[i])S.pop();
        if (!S.empty() && S.top()==x-A[i]){
            cnt++;
            S.pop();
        }
        else{
            S.push(A[i]);
        }
    }

    return cnt;
}
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

    cin>>n>>m;
    A[1] = 1;
    A[2] = 2;
    ll cnt = 0,i = 3;
    while(i<=n && (i-1)/2+cnt<=m){
        cnt+=(i-1)/2;
        A[i] = A[i-1]+1;
        i++;
    }

    ll last = 1,en = i;
    while(i<=n){
        while((en-last)/2+cnt>m)last++;
        if (cnt==m){
            break;
        }
        else
        A[i] = A[last]+A[en-1];
        cnt+=(en-last)/2;
        i++;
    }
    ll j = n;
    A[j+1] = MAXN-A[i-1]-1;
    while(j>=i){
        A[j] = A[j+1]-A[i-1]-1;;
        j--;
    }
    if (cnt!=m){
        cout<<"-1\n";
        return 0;
    }
    forn(i,n)cout<<A[i]<<' ';
    cout<<endl;
    return 0;
}