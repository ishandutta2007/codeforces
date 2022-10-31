#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll DIM = 2E6+7;
const ll INF = 1E18+7;

int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>k>>n;
        --n;
        if (k==1){
            cout<<1<<endl;
            continue;
        }
        if (k==3){
            cout<<(n*2)%k+1<<endl;
            continue;
        }
        if (k%2==0){
            cout<<(n%k)+1<<endl;
            continue;
        }
        ll res = n+n/(k/2);
        //res+=n;
        res%=k;
        cout<<res+1<<endl;
    }

    return 0;
}