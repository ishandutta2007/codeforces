#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const long long INF=1e18+10;
const int inf=1e9+10,dx[]= {0,0,1,-1,1,-1,1,-1},dy[]= {1,-1,0,0,1,1,-1,-1};
ll MOD=1e9+7;
double eps=1e-11;
//ld eps=1e-7,pi=acos(-1);

#define fi first
#define se second
#define be(x) x.begin(),x.end()
#define Last(x) (*(--x.end()))

ll t,n,m,a,b,x;
int main()
{
ios::sync_with_stdio(0);

cin>>t;
while(t--)
{
    cin>>n>>m>>a>>b;
    multiset<ll> v;
    for(int i=0;i<m;i++)
    {
        cin>>x;
        v.insert(x);
    }
    ll boom = abs(a-b)-1;
    ll stay = boom ;
    if(a < b)stay += a - 1;
    else     stay += n - a;

    //cout<<"stay = "<<stay<<"\n";
    ll ans = 0;
    ll t = 0;
    for(int i = 0 ;i<m && i< boom && stay >= t;i++)
    {
        x = stay - t;
        //cout<<"x = "<<x<<"\n";
        auto it = v.upper_bound(x);
        if(it != v.begin()) --it;
        //cout<<"*it = "<<*it<<"\n";
        if(*it <= x)
        {
            ++ans;
            v.erase(it);
        }

        ++t;
    }

    cout<<ans<<"\n";
}



    return 0;
}