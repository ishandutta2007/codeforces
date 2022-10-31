#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll DIM = 2E5+7;
const ll MAXN = 1E10;
ll A[DIM];

int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        for(ll i = 1;i<=n;++i){
            cin>>A[i];
        }
        ll res = 0;
        for(ll i = 2;i<=n;++i){
            if (max(A[i],A[i-1])>2*min(A[i],A[i-1])){
                if (A[i]>A[i-1]){
                    while(A[i-1]*2<A[i]){
                        ++res;
                        A[i-1]*=2;
                    }
                }
                else{
                    ll last = A[i];
                    while(A[i]*2<A[i-1]){
                        ++res;
                        A[i]*=2;
                    }
                    A[i] = last;
                }
            }
        }
        cout<<res<<endl;
    }
    return 0;
}