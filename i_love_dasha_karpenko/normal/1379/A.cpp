#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long ll;
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
const long long MOD = 1000000007;
struct matrix{

    vector<vector<ll> > a;
    ll n,m,pr;
    void init(ll nn,ll nm){
        n = nn;
        m = nm;
        a.resize(n+1);
        forn(i,n){
            a[i].resize(m+1);
            forn(j,m)a[i][j] = 0;
        }
    }
};

matrix mul(matrix &a,matrix &b){

    matrix c;
    c.init(a.n,b.m);


    forn(i,a.n){
        forn(k,a.m){
            forn(j,b.m){
                long long g = c.a[i][j];
                g = (g+(long long)(a.a[i][k])*b.a[k][j])%MOD;
                c.a[i][j]=g;
            }
        }
    }
    return c;
}
matrix binpow(matrix &a,ll power){
    matrix mult = a;
    matrix ret = a;
    --power;
    while(power){
        if (power&1)
            ret = mul(mult,ret);
        mult = mul(mult,mult);
        power/=2;
    }
    return ret;
}
struct node{
    ll fi,sc,th;
};
vector<node> qe;
vector<matrix> ret;
const ll LOG = 30;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        string s;
        cin>>s;
        string need = "abacaba";
        ll cn = 0;
        string res;
        for(ll st = 0;st<s.length()-need.length()+1;++st){
            ll flag = 0;
            for(ll i = 0;i<need.length();++i){
                if (s[st+i]!='?' && s[st+i]!=need[i]){
                    flag = 1;
                    break;
                }
            }
            if (flag)continue;
            string b = s;
            for(ll i = 0;i<need.length();++i){
                b[st+i] = need[i];
            }
            ll cnt = 0;
            for(ll i = 0;i<n;++i){
                if (b[i]=='?')b[i] = 'x';
            }
            for(ll i = 0;i<n-need.length()+1;++i){
                ll fl = 1;
                for(ll j = 0;j<need.length();++j){
                    if (b[i+j]!=need[j]){
                        fl = 0;
                        break;
                    }
                }
                cnt+=fl;
            }
            if (cnt==1){
                cn = 1;
                res = b;
                break;
            }
        }
        if (cn)
        cout<<"YES\n"<<res<<endl;
        else cout<<"NO\n";
    }
    return 0;
}
// (i-1)%p
// l = A[i],r = A[i+1]
// 001011
// 001110
// 011010
// 110010
// 1110
// 11 - 8 11-8+1-3 = 1
// 11 10 8
// 1001100
// 4,3,2,6,