#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll tim[100009],x[100009],h[100009],to[100009],dr[100009];
int main()
{
    ios::sync_with_stdio(0);
ll t,n;
cin>>t;
while(t--)
{
    cin>>n;
    dr[0]=1;
    for(int i=0;i<n;i++)
        cin>>tim[i]>>x[i];
        tim[n]=3000000000;
    ll ans=0;
   for(int i=0;i<n;i++)
   {
    //   cout<<h[i]<<" "<<to[i]<<" "<<dr[i]<<endl;
       if(h[i]==to[i])
       {
           if(i==n-1){ans++;break;}
           to[i+1]=x[i];
           if(x[i]<h[i])dr[i+1]=-1;
           else dr[i+1]=1;
           h[i+1]=min(tim[i+1]-tim[i],abs(to[i+1]-h[i]))*dr[i+1]+h[i];

       }
       else
       {
           to[i+1]=to[i];
           dr[i+1]=dr[i];
           h[i+1]=min(tim[i+1]-tim[i],abs(to[i+1]-h[i]))*dr[i+1]+h[i];
       }
     if(x[i]>=h[i]&&x[i]<=h[i+1])ans++;
     else if(x[i]<=h[i]&&x[i]>=h[i+1])ans++;
  // cout<<44<<" "<<x[i]<<" "<<i<<" "<<ans<<endl;
   }
   cout<<ans<<endl;
}

    return 0;
}