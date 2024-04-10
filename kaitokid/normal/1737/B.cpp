#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
      ll l,r;
      cin>>l>>r;
      ll u=sqrt(l),v=sqrt(r);
      while(u*u<l)u++;
      while(u*u>l)u--;
      while(v*v<r)v++;
      while(v*v>r)v--;
      
      
      ll ans=(v-u+1)*3;
      ll g=u*u;
      while(g<l)
      {
          ans--;
          g+=u;
      }
      g=v*(v+2);
      while(g>r)
      {
          ans--;
          g-=v;
      }
      cout<<ans<<endl;





    }
    return 0;
}