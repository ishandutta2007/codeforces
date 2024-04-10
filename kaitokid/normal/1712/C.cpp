#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100009];
int lst[100009],fr[100009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
       int n;
       cin>>n;
       for(int i=0;i<=n;i++)lst[i]=fr[i]=0;
       for(int i=1;i<=n;i++){cin>>a[i];if(fr[a[i]]==0)fr[a[i]]=i;lst[a[i]]=i;}
       int d=-1;
       for(int i=1;i<n;i++)if(a[i]>a[i+1])d=i;
       if(d==-1){cout<<0<<endl;continue;}
       int u=0;
       for(int i=1;i<=d;i++)
       {
           u=max(u,lst[a[i]]);
       }
       int ans=0;
       for(int i=1;i<=n;i++)
       {
           if((fr[i]!=0)&&(fr[i]<=u))ans++;
       }
       cout<<ans<<endl;

    }
    return 0;
}