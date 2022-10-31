#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll DIM = 107;
ll A[DIM];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;

        for(ll i = 1;i<=n;++i){
            cin>>A[i];

        }
        ll last = 0,flag = 0;
        while(k--){
            for(ll i = 1;i<=n;++i){
                if (i==n){
                    flag = 1;
                    break;
                }
                if (A[i]<A[i+1]){
                    ++A[i];
                    last = i;
                    break;
                }

            }
            if (flag)break;
        }
        if (flag==1)cout<<"-1\n";
        else cout<<last<<endl;
    }
    return 0;
}