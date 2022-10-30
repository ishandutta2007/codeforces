#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds; //    
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pp;
const ll DIM = 57;
const ll INF = 10000000007;
const ll MOD = ll(1000000007) ;
#define forn(i,n) for(ll i = 1;i<=n;i++)
#define pb push_back
#define fi first
#define sc second
const ll LOG = 21;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> my_super_set;
my_super_set S;
struct Matrix{
    ll n,m,A[DIM][DIM];
    Matrix (ll nm,ll mm){
        n = nm; m = mm;
    }
    void print(){
        //cout<<n<<' '<<m<<endl;
        forn(i,n){
            forn(j,m)cout<<A[i][j]<<' ';
            cout<<endl;
        }
    }
    Matrix mult(Matrix &B){
        Matrix C(n,B.m);

        for(ll i = 1;i<=n;i++){
            for(ll j = 1;j<=C.m;j++){
                C.A[i][j] = 0;
                for(ll k = 1;k<=m;k++){
                    C.A[i][j] =(C.A[i][j]+ (A[i][k]*B.A[k][j])%MOD)%MOD;
                }
            }
        }
        return C;
    }
    void init(){
        forn(i,n){
            forn(j,n){
                if (i==j)A[i][j] = 0;
                else A[i][j] = 1;
            }
        }
    }

};
void binpow(Matrix &A,ll  power){
    power--;
    Matrix mult = A;

    while(power>0){
        if (power&1)A=A.mult(mult);
        mult = mult.mult(mult);
        power/=2;
    }

}

int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Matrix fib(4,4);  fib.init();
    ll n; cin>>n;
    binpow(fib,n);
    Matrix M(4,1); M.A[4][1]=M.A[2][1]=M.A[3][1]=1;
    M.A[1][1] = 1;
   // fib = fib.mult(M);
    cout<<fib.A[1][1]<<endl;
    return 0;
}