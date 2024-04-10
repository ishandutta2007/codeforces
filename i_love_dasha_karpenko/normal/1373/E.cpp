#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;

#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
#define log sdfdsfdsf

const ll DIM = 2E5+7;
const ll INF = 2E18;
const ld eps = 0.0000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}

ll n,k;
ll F(ll x){
    ll ret = 0;
    while(x>0){
        ret+=x%10;
        x/=10;
    }
    return ret;
}
ll Check(ll num){
    ll mult = 9;
    ll sum = 0;
    forn(i,num){
        sum+=mult;
        mult*=10;
    }
    ll res = 0;
    forn(i,k+1){
        res+=F(sum);
        --sum;
    }
    return res;
}
ll Ch(ll num){
    ll res = 0;
    forn(i,k+1){
        res+=F(num);
        --num;
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    cin>>t;
    while(t--){

        cin>>n>>k;
        if (k*(k+1)/2>n){
            cout<<"-1\n";
            continue;
        }
        ll num = -1;

        for(ll st = 0;st<=9;++st){
            ll mult = 10;
            for(ll div = 0;div<10;++div){

                if (div==1)mult = 10;
                ll fnums = max(0ll,st+k-10+1);
                if (fnums>0 && div==0){
                    mult*=10;
                    continue;
                }
                ll stt = st;
                ll res = (k+1-fnums)*9*max(0ll,div-1)+fnums;
                forn(j,k+1){
                    res+=stt%10;
                    ++stt;
                }

                ll left = n-res;
                if (left<0){
                    mult*=10;
                    continue;
                }
                if (left%(k+1)!=0){
                    mult*=10;
                    continue;
                }
                ll dd = left/(k+1);
                ll ss = st;
                ll mu = mult;
                if (mult>=10)ss+=mult-10;
                ll xnum = 8;
                if (div==0)xnum++;


                while(dd>0){
                    ll g = min(xnum,dd);
                    dd-=g;
                    ss+=g*mu;
                    mu*=10;
                    xnum = max(9ll,xnum);
                }

                num = min(num,ss);
                if (num==-1)num = ss;

                mult*=10;
            }
        }

        cout<<num<<endl;


    }


    return 0;
}
// 001011
// 001110
// 011010
// 110010
// 1110
// 11 - 8 11-8+1-3 = 1
// 11 10 8
// 1001100
// 4,3,2,6,