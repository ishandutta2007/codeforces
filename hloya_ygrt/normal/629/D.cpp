#include <bits/stdc++.h>

#define f first
#define s second
#define ll long long
#define ld long double
#define pb push_back
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(0);
#define forn() for(int i=0;i<n;i++)


using namespace std;

const int inf=2e9;
const double eps=1e-9;
const int maxn = 1e5+5, base = 1e9+7;
const ll maxV = 1e12+500;
map<ll,ll> t;
ll sum(ll r)
{
    ll ans = 0;
    while (r > 0){
        if (t.find(r)!=t.end())
            ans = max(ans,t[r]);
        r -= r&(-r);
    }
    return ans;
}

void update(ll i,ll x)
{

    while (i<maxV){
         if (t.find(i)==t.end())
            t[i] = x;
            else
        t[i] = max(t[i],x);
        i += (i&(-i));
    }
}
int main()
{
    //files1;
    //files2;
    //freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
    int n;
   vector<ll> ob;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        ll r,h;
        scanf("%I64d %I64d",&r,&h);
        ll v = r*r*h;
        ob.pb(v);
      //  cout<<v<<endl;
        ll tans = sum(v-1);
        ll old = sum(v);
       /// cout<<tans+old<<endl;
       // cout<<old<<endl;
      // cout<<v+tans-old<<endl;
      if (v+tans > old)
        {
           update(v,v+tans);
        }
           
   }
    ll ans = 0;
   for (int i=0;i<ob.size();i++){
      ll v= ob[i];
      ans = max(ans,sum(v));
   }
 //  cout<<ans<<endl;
   long double p = 3.14159265358979;
   long double good = (long double)ans * p;
   cout<<fixed<<setprecision(20)<<good;
    return 0;
}