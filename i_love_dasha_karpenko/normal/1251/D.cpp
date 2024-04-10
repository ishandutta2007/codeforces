#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pp;
#define forn(i,n) for(ll i = 1;i<=n;i++)
#define fi first
#define sc second
#define pb push_back
#define endl '\n'
#define x1 dsfdsfdsfewewer
#define y1 fdgretdfdsfgddsf
const ll DIM = 2*(10e4)+7;
const ll INF = 10e16;
const ll MOD = (10e9)+7;
const ll _MAX = (10e8)+7;
/*                       */

ll t;
pp A[DIM];
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //cout<<_MAX<<endl;
    cin>>t;
    forn(query,t){
        ll n,money;
        cin>>n>>money;
        forn(i,n){
            cin>>A[i].fi>>A[i].sc;
            money-=A[i].fi;
        }
        //sort(A+1,A+1+n);
        ll l = 0;
        ll r= _MAX;

        while(r!=l){
            ll tm = (l+r)/2+1;
            //cout<<tm<<endl;
            vector<ll> V;
            forn(i,n){
                if (A[i].sc>=tm){
                    V.pb(A[i].fi);
                }
            }
            sort(V.begin(),V.end());
            ll start = n/2-(n-V.size());
            ll need = 0;
            if (start>=0){
                need = 0;
                ll cnt = 0,sum = 0;
                for(ll i = start;i<V.size();i++){
                    if (V[i]>tm)break;
                    sum+=V[i];
                    cnt++;

                }
                need += cnt*tm-sum;
            }
            else{
                need = INF;
            }
            //cout<<tm<<' '<<need<<' '<<start<<' '<<V.size()<<endl;
            if (need>money)r = tm-1;
            else l = tm;
        }
        cout<<l<<endl;
    }
    return 0;
}