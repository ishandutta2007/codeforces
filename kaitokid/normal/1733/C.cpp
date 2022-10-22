#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[100009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
       cin>>n;
       for(int i=1;i<=n;i++)cin>>a[i];
       cout<<n-1<<endl;
       if(a[1]%2)
       {
           int u=1;
           for(int i=1;i<=n;i++)if(a[i]%2)u=i;
           for(int i=1;i<u;i++)
            if((a[i]%2))cout<<i<<" "<<u<<endl;
           for(int i=2;i<=n;i++)if((a[i]%2)==0)cout<<1<<" "<<i<<endl;
           continue;
       }
          int u=1;
           for(int i=1;i<=n;i++)if((a[i]%2)==0)u=i;
           for(int i=1;i<u;i++)
            if((a[i]%2)==0)cout<<i<<" "<<u<<endl;
           for(int i=2;i<=n;i++)if((a[i]%2))cout<<1<<" "<<i<<endl;

    }
    return 0;
}