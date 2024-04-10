#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll DIM = 100+7;
const ll INF = 1E18+7;
ll A[DIM][DIM],indeg[DIM],outdeg[DIM];
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;

        if (n%2==0){

            for(ll i = 0;i<n;++i){
                for(ll j = i+1;j<i+n/2;++j){
                    if ((i+n-1+n)%n==j%n)continue;
                    A[i][j%n] = 1;
                    A[j%n][i] = -1;
                }
            }
        }
        else{
            for(ll i = 0;i<n;++i){

                for(ll j = i+1;j<=i+n/2;++j){


                    A[i][j%n] = 1;
                    A[j%n][i] = -1;

                }
            }
        }
        for(ll i = 0;i<n;++i){
            for(ll j = 0;j<n;++j){
                if (i<j) cout<<A[i][j]<<' ';
                A[i][j] = 0;
            }
            cout<<endl;
        }
    }

    return 0;
}