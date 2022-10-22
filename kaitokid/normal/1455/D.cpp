#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int a[509],b[509];
int x,n;
int ch(int u)
{
    int i=0,j=0;
    int res=0,q=x;
    while(i<n)
    {
        if(j==u)j++;
     if(a[i]!=b[j])
     {
         if(b[j]!=q||a[i]<=q){res=1e7;break;}
        res++;
        q=a[i];
     }
    i++,j++;
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(0);
    int t;

    cin>>t;
    while(t--)
    {

        cin>>n>>x;
        bool bl=true;
        cin>>a[0];
        b[0]=a[0];
        for(int i=1;i<n;i++)
        {
            cin>>a[i];
            b[i]=a[i];
            if(a[i]<a[i-1])bl=false;
        }
        if(bl){cout<<0<<endl;continue;}
      b[n]=x;
      sort(b,b+n+1);
      int ans=1e7;
      for(int i=0;i<=n;i++)
            ans=min(ans,ch(i));
            //cout<<ch(i)<<endl;}
      if(ans>n+2)cout<<-1<<endl;
      else cout<<ans<<endl;
    }
    return 0;
}