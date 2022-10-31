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
#define endl '\n'
#define po(x) (1ll<<x)
const ll DIM = 10E4+7;
const ll INF = 10E17;

ll A[3*DIM],cnt[3*DIM];
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    forn(qe,t){
        ll n,m;
        cin>>n>>m;
        ll sum = 0;
        forn(i,m){
            cin>>A[i];
            sum+=A[i];
            cnt[i] = 0;
        }
        forn(i,64)cnt[i] = 0;
        if (sum<n){
            cout<<"-1\n";
            continue;
        }
        forn(i,m){
            ll x= A[i];
            ll ct = 0;
            while(x>0){
                ct++;
                x/=2;
            }
            cnt[ct]++;
        }
        ll bit = 1,res = 0;
        while(n>0){
            if (n&1){
                ll i = bit;
                while(cnt[i]==0 && i<DIM-5)i++;
                if (cnt[i]==0)break;
                cnt[i]--;

                i--;
                while(i>=bit){
                    cnt[i]++;
                    res++;
                    i--;
                }

            }

            cnt[bit+1]+=cnt[bit]/2;
            cnt[bit]%=2;

            n/=2;
            bit++;
        }
        if (n!=0)cout<<-1<<endl;
        else
        cout<<res<<endl;

    }
    return 0;
}