#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll t,x,y,c[8];
int main()
{ios::sync_with_stdio(0);
   cin>>t;
   while(t--)
   {
       cin>>x>>y;
       for(int i=0;i<6;i++)cin>>c[i];
       for(int q=0;q<100;q++)
       {
           for(int i=0;i<6;i++)
            c[i]=min(c[(i+1)%6]+c[(i+5)%6],c[i]);
       }
ll d=min(x,y);
d=max(d,0LL);
ll ans=0;
ans+=d*c[0];
x-=d,y-=d;
d=max(x,y);
d=min(d,0LL);
ans+=-1*d*c[3];
x-=d,y-=d;
ans+=c[1]*max(y,0LL);
ans+=c[4]*max(-y,0LL);
ans+=c[5]*max(x,0LL);
ans+=c[2]*max(-x,0LL);
cout<<ans<<endl;

   }
   return 0;
}