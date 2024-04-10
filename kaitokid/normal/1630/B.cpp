#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int fr[400009],n,k;
int a[400009];
int ff[400009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=0;i<=n;i++)fr[i]=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            fr[a[i]]++;
        }
       for(int i=2;i<=n;i++)fr[i]+=fr[i-1];
       for(int i=0;i<=n;i++)ff[i]=n+10;
       for(int i=n;i>=0;i--)ff[fr[i]]=i;
       for(int i=n-1;i>=0;i--)ff[i]=min(ff[i],ff[i+1]);
       int w=(n-k+1)/2+k;
       int x=0,y=n+100;

       for(int i=1;fr[i-1]+w<=n;i++)
       {

           int u=i;
           int v=ff[fr[i-1]+w];

           if(v-u < y-x){x=u;y=v;}
       }
      cout<<x<<" "<<y<<endl;
      int l=1,z=0;
      for(int i=1;i<=n;i++)
       {
           if(k==1){cout<<l<<" "<<n<<endl;break;}
          if(a[i]>=x && a[i]<=y)z++;
          if(z>i-l+1-z){cout<<l<<" "<<i<<endl;k--;l=i+1;z=0;}

       }

    }

    return 0;
}