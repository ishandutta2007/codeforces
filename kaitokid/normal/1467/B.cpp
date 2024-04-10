#include <bits/stdc++.h>

using namespace std;

int mod=1e9+7;
int a[300009],d[300009],n;
bool ch(int i)
{
    if(i<=0||i>=n-1)return false;
    if((a[i]>a[i-1]&&a[i]>a[i+1])||(a[i]<a[i-1]&&a[i]<a[i+1]))
return true;

return false;
}
int main()

{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int ans=0;
        for(int i=0;i<n;i++)cin>>a[i];
        int s=0;
        for(int i=0;i<n;i++)
        {
            int u=0,r=a[i],v=0,q=0;
             if(ch(i)){u++; ans++;}
            if(ch(i-1))u++;
            if(ch(i+1))u++;
            a[i]=a[i-1];
             if(ch(i))v++;
            if(ch(i-1))v++;
            if(ch(i+1))v++;
             a[i]=a[i+1];
             if(ch(i))q++;
            if(ch(i-1))q++;
            if(ch(i+1))q++;
            a[i]=r;
            s=max(s,u-min(v,q));

        }
       cout<<ans-s<<endl;

    }
      return 0;
}