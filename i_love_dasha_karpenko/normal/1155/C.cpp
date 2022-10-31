#include <bits/stdc++.h>

using namespace std;
#define DIM 10007
#define INF 10000000000000007
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pairll;
typedef ll arr[DIM];

ll n,m,cof;
int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    ll a,b;
    cin>>a>>b;
    cof = b-a;
    ll prevx = b;
    for (int i = 3;i<=n;i++){
        ll x; cin>>x;
        ll x1 = x-prevx;
        cof = __gcd(cof,x1);
        prevx = x;
    }
    ll posbase = a-1;
    ll pos = a,num=-1;
    for (int i = 1;i<=m;i++){
        ll x; cin>>x;
        if (cof%x!=0)continue;
        ll ca = posbase/x*x;
        ll p = a-ca;
        if (p<=pos){
            pos = p;
            num = i;
        }
    }
    if(num==-1){
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    cout<<pos<<' '<<num<<endl;
}