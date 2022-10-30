#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> satan_set;
#define forn(i,n) for(ll i = 1;i<=n;i++)
#define pb push_back
#define fi first
#define sc second
#define x1 dsfdsf
#define y1 fgdfgdfg
#define endl '\n'
#define po(x) (1ll<<x)
const ll DIM = 2*10E4+7;
const ll INF = 10e16;
const ll MOD = 998244353 ;
const ll MAXN = 1000000000;

ll A[DIM];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    cin>>t;
    forn(query,t){
        ll n; cin>>n;
        ll x = 0,sum = 0;
        forn(i,n){
            cin>>A[i];
            sum+=A[i];
            x^=A[i];
        }

        cout<<3<<endl;
        if (sum%2!=0){
            cout<<1<<' ';
            x^=1;
            sum++;

        }

        else cout<<0<<' ';
        ll s1 = sum,x1 = x;
        sum/=2;
        ll t1 = 0,t2 = 0,step = 1;
        while(x>0 || sum>0){
            //if (step==30)break;
            ll r1 = x%2,r2 = sum%2;
            if (x==0 && sum==1){
                t1+=po(step);
                break;
            }
            if (r1!=r2){

                t1+=po(step-1);
                t2+=po(step-1);
                sum++;

            }

            step++;
            x/=2;
            sum/=2;
        }
        s1+=t1;
        s1+=t2;
        x1^=t1;
        x1^=t2;
        x1*=2;
        //if (x1!=s1)cout<<"-1\n";
        //cout<<x1<<' '<<s1<<endl;
        cout<<t1<<' '<<t2<<endl;

    }
    return 0;

}