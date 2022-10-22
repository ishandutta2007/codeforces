#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[200009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
int t;
cin>>t;
while(t--)
{int n;
    cin>>n;
    int l=1,r=n;
    while(r>l)
    {
        int mid=(l+r)/2;
        cout<<"? 2 "<<1<<" "<<2<<" "<<mid<<endl;
        fflush(stdout);
        int u;
        cin>>u;
        if(u==mid)r=mid;
        else l=mid+1;
    }
    int z;
 if(l>(n/2))z=1;
 else z=2;
 a[1]=l;
 for(int i=2;i<=n;i++)
 {
     if(z==1)
     {
         cout<<"? 2 "<<i<<" "<<1<<" "<<1<<endl;
         fflush(stdout);
         int u;
         cin>>u;
         if(u<a[1]){a[i]=u;continue;}
         cout<<"? 1 "<<1<<" "<<i<<" "<<n-1<<endl;
         fflush(stdout);
         cin>>a[i];
         continue;
     }
         cout<<"? 1 "<<1<<" "<<i<<" "<<n-1<<endl;
         fflush(stdout);
         int u;
         cin>>u;
         if(u>a[1]){a[i]=u;continue;}
         cout<<"? 2 "<<i<<" "<<1<<" "<<1<<endl;
         fflush(stdout);
         cin>>a[i];



 }
 cout<<"! ";
 for(int i=1;i<=n;i++)cout<<a[i]<<" ";
 cout<<endl;
 fflush(stdout);
}

    return 0;
}