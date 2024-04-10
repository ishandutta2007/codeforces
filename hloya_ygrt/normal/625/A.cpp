#include <bits/stdc++.h>
const int maxn=2e5;
const long long inf=2000000000000000000;
const double eps=1e-9;
const int base=1e9+7;

#define mp make_pair
#define f first
#define sec second
#define pb push_back
#define ll long long
#define ld long double
#define fast_io ios_base::sync_with_stdio(0);
#define forn() for(int i=0;i<n;i++)

using namespace std;
//int a[maxn];
int main()
{
    ll n;

  //  freopen("input.txt","r",stdin);
  //          freopen("output.txt","w",stdout);
    ll a,b,c;
    cin>>n>>a>>b>>c;
    ll a2 = b-c;
    //cout<<n-a2<<endl;
    ll ans = 0;
    if (a<a2){
      // cout<<1<<endl;
        ans += n/a;
        n = n%a;
        if (n>=b)
            ans++;
    }
    else
    {

     //  cout<<2<<endl;
        ll r = inf/a2;
     // cout<<inf<<endl<<a2<<endl;
       //cout<<r<<endl;
        ll l = 0;
        while (r-l>1){
            ll m = l + (r-l)/2;
            ll t = (n-a2*m);
            bool cn = b==t;
            //cout<<cn<<endl;
            if (t>=b)
                l=m;
            else
                r=m;
        }
         ll t= (n-a2*r);
        if (t>=b)
            l=r;
   //   cout<<l<<' '<<r<<endl;
        ans += l;
        n = n-a2*l;
        ll ans1=0,ans2=0;
        if (n>=b)
            ans1++;
        ll n1 =n;
        n1-=b;
        n1+=c;
        ans1+=n1/a;
        ans2=n/a;
        ans+=max(ans1,ans2);
    }
    cout<<ans;
    return 0;
}