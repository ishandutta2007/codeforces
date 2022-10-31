#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
#define exp fgfdgd
const ll DIM = 1E6+7;
const ll INF = 1E9;

int main()
{


    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll p,a,b,c;
        cin>>p>>a>>b>>c;
        ll r1 = (a-p%a)%a;
        ll r2 = (b-p%b)%b;
        ll r3 = (c-p%c)%c;
        cout<<min({r1,r2,r3})<<endl;
    }

    return 0;
}