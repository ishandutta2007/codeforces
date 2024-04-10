#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll DIM = 100+7;
const ll INF = 1E18+7;

int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll sq = sqrt(2*n-1);
        ll res = (sq-1)/2;
        cout<<res<<endl;
    }

    return 0;
}