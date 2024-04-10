#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pp;
typedef unsigned long long ull;
typedef pair<ull,ll> upp;
const ll DIM = 200000+7;
const ll INF = 10e16;
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define po(x) (1<<x)

ll st[DIM],suf[DIM];
pp A[DIM];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t; cin>>t;
    forn(query,t){
        ll n;
        cin>>n;
        //forn(i,n){fir[i] = -1;}
        ll res = INF;
        forn(i,n){
            cin>>st[i];
        }
        ll m;cin>>m;
        forn(i,m){
            cin>>A[i].fi>>A[i].sc;
        }
        sort(A+1,A+1+m);
        suf[m+1] = 0;
        for(ll i = m;i>=1;i--)suf[i] = max(suf[i+1],A[i].sc);
        ll mx= 0,cnt = 0,streak = 0,flag = 0;
        forn(i,n){
            mx = max(mx,st[i]);
            ll pos = (lower_bound(A+1,A+1+m,pp{mx,-INF})-A);
            if (pos>m){
                //cout<<"-1\n";
                flag =1 ;
                break;
            }

            if (suf[pos]<=streak){
                cnt++;
                mx = st[i];
                streak = 1;
                continue;
            }
            streak++;
        }
        cnt++;
        if (flag)cout<<"-1\n";
        else
        cout<<cnt<<endl;
    }
    return 0;
}