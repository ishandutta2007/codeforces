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

const ll DIM = 500+7;
const ll INF = 2E18;
const ld eps = 0.0000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}

ll A[DIM];
vector<ll> ans;
void F(ll pos){
    ans.pb(pos);
    ll buf = A[pos+2];
    A[pos+2] = A[pos+1];
    A[pos+1] = A[pos];
    A[pos] = buf;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ans.clear();
        ll n;
        cin>>n;
        map<ll,ll> M;
        pp elem = {-1,-1};
        forn(i,n){
            cin>>A[i];
            if (M.count(A[i])==1)elem = {M[A[i]],i};
            M[A[i]] = i;
        }
        if (elem==pp{-1,-1}){
            ll flag = 0;
            forn(i,n){
                ll mi = i;
                for(ll j = i;j<=n;++j){
                    if (A[j]<A[mi])mi = j;
                }
                while(mi-i>1){
                    F(mi-2);
                    mi-=2;
                }
                if (mi%2!=i%2){
                    if (mi+1<=n){
                        F(mi-1);
                        ++mi;
                        F(mi-2);
                        mi-=2;
                    }
                    else{
                        flag = 1;
                        break;
                    }
                }

            }
            if (flag)cout<<"-1\n";
            else{
                cout<<ans.size()<<endl;
                for(ll to:ans)cout<<to<<' ';
                cout<<endl;
            }

            continue;
        }
        ll x = elem.fi;
        while(x>1){
            if (x>2){
                F(x-2);
                x-=2;
            }
            else{
                F(x-1);
                x++;
                F(x-2);
                x-=2;
            }
        }
        x = elem.sc;
        while(x>1){
            if (x>2){
                F(x-2);
                x-=2;
            }
            else{
                F(x-1);
                x++;
                F(x-2);
                x-=2;
            }
        }
        while(A[1]!=A[2])F(1);
        forn(i,n-2){
            ll mi = i+2;
            for(ll j = i+2;j<=n;++j){
                if (A[mi]>A[j])mi = j;
            }
            while(mi-2>=i+2){
                F(mi-2);
                mi-=2;
            }
            if (mi==i+2){
                F(mi-2);
                mi-=2;
            }
            else{
                F(mi-2);
                mi-=2;
                F(mi-1);
                mi++;
                F(mi-2);
                mi-=2;
            }
        }
        for(ll i = n;i>=3;--i){
            ll mi = i-2;
            if (A[i]>=A[mi])break;
            F(mi);
            F(mi);
        }
        cout<<ans.size()<<endl;
        for(ll to:ans)cout<<to<<' ';
        cout<<endl;



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