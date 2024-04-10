//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ull,ll> upp;

#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll DIM = 1E5+7;
ll A[DIM],B[DIM];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;

        for(ll i = 1;i<=n;++i){
            char ch;
            cin>>ch;
            B[i] = ch-'0';
        }
        ll last = -1;
        for(ll i = 1;i<=n;++i){

            for(ll j = 1;j>=0;--j){
                if (B[i]+j!=last){
                    last = B[i]+j;
                    A[i] = j;
                    break;
                }
            }
            cout<<A[i];
        }
        cout<<endl;

    }

    return 0;
}