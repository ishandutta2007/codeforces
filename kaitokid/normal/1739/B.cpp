#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[109];
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
       for(int i=0;i<n;i++)cin>>a[i];
       bool bl=true;
       for(int i=1;i<n;i++)
       {
           if(a[i]==0){a[i]=a[i-1];continue;}
           if(a[i-1]-a[i]>=0){bl=false;break;}
           a[i]+=a[i-1];
       }
       if(!bl){cout<<-1<<endl;continue;}
       for(int i=0;i<n;i++)cout<<a[i]<<" ";
       cout<<endl;
    }
    return 0;
}