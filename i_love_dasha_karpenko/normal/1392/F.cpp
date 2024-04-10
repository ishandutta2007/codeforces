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

const ll DIM = 1E6+7;
const ll MOD = 1e9+7;

const ll INF = 1E17;
const ld eps = 0.00000000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
    static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution <int> (a, b)(rng);
}
ll A[DIM];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    forn(i,n)cin>>A[i];
    vector<pp> V;
    V.pb({A[1]-1,1});
    for(ll i = 2;i<=n;++i){
        V.pb({A[i]-i,1});
        stack<pp> buf;
        if (i==n){
            ll fg = 0;
            ++fg;
        }
        while(1){
            ll flag = 0;
            if (V.size()>=2){
                pp a = V.back();
                V.pop_back();
                pp b = V.back();
                V.pop_back();

                if (a.fi>=b.fi){
                    ll h = (a.sc*a.fi+b.sc*b.fi)/(a.sc+b.sc);

                    ll left = (a.sc*a.fi+b.sc*b.fi)%(a.sc+b.sc);
                    if (left){
                        V.pb({h+1,left});
                        buf.push({h,a.sc+b.sc-left});
                    }
                    else V.pb({h,a.sc+b.sc});
                    flag = 1;
                }
                else{
                    V.pb(b);
                    V.pb(a);

                }
            }
            while(buf.size()>=2){
                pp b = buf.top();
                buf.pop();
                pp a = buf.top();
                buf.pop();
                if (a.fi<b.fi){
                    buf.push(a);
                    buf.push(b);
                    break;
                }
                ll h = (a.sc*a.fi+b.sc*b.fi)/(a.sc+b.sc);

                ll left = (a.sc*a.fi+b.sc*b.fi)%(a.sc+b.sc);
                if (left){
                    buf.push({h,a.sc+b.sc-left});
                    buf.push({h+1,left});
                }
                else buf.push({h,a.sc+b.sc});
                flag = 1;
            }
            if (!V.empty() && !buf.empty() && buf.top().fi>=V.back().fi){
                pp a = buf.top();
                buf.pop();
                pp b = V.back();
                V.pop_back();

                ll h = (a.sc*a.fi+b.sc*b.fi)/(a.sc+b.sc);

                ll left = (a.sc*a.fi+b.sc*b.fi)%(a.sc+b.sc);
                if (left){
                    V.pb({h+1,left});
                    buf.push({h,a.sc+b.sc-left});
                }
                else V.pb({h,a.sc+b.sc});
                flag = 1;
            }
            while(buf.size()>=2){
                pp b = buf.top();
                buf.pop();
                pp a = buf.top();
                buf.pop();
                if (a.fi<b.fi){
                    buf.push(a);
                    buf.push(b);
                    break;
                }
                ll h = (a.sc*a.fi+b.sc*b.fi)/(a.sc+b.sc);

                ll left = (a.sc*a.fi+b.sc*b.fi)%(a.sc+b.sc);
                if (left){
                    buf.push({h,a.sc+b.sc-left});
                    buf.push({h+1,left});
                }
                else buf.push({h,a.sc+b.sc});
                flag = 1;
            }
            if (flag==0)break;

        }

        while(!buf.empty()){
            V.pb(buf.top());
            buf.pop();
        }

    }
    ll pos = 1;
    for(pp to:V){
        forn(j,to.sc){
            cout<<pos+to.fi<<' ';
            ++pos;
        }
    }
    cout<<endl;
    return 0;
}