#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pp;
typedef unsigned long long ull;
typedef pair<ull,ll> upp;
const ll DIM = 1007;
const ll INF = 10e16;
const ll MOD1 = (10e9)+7;
const ll MOD2 = 2147483647;
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define po(x) (1<<x)
ll A[DIM];
int main()
{
    //cout<<'A'-33<<endl;
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t; cin>>t;
    forn(query,t){
        ll n,m; cin>>n>>m;
        ll sum = 0,mi1 = INF,mi2 = INF,n1,n2;
        forn(i,n){
            cin>>A[i];
            if (A[i]<mi1){
                mi2 = mi1;
                mi1 = A[i];
                n1 = i;
            }
            else if (A[i]<mi2){
                mi2 = A[i];
                n2 = i;
            }
            sum+=A[i];
        }
        if (n>m || n<=2){
            cout<<"-1\n";
            continue;
        }
        cout<<sum*2+(mi1+mi2)*(m-n)<<endl;
        forn(i,n){
            if (i==n)cout<<i<<' '<<1<<endl;
            else
            cout<<i<<' '<<i+1<<endl;
        }
        while(m>n){
            m--;
            cout<<n1<<' '<<n2<<endl;
        }

    }
    return 0;
}

// 5
// 0 1 0 1 0 1010
// 1 3 9  27
// 1 7 16 70
// 1 2 1 0