#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int a[100009];
int main()
{
ios::sync_with_stdio(0);
int t,n;
cin>>t;
while(t--)
{
    cin>>n;
    int x,mx=0,d=0;
    for(int i=1;i<=n;i++)a[i]=0;
    for(int i=0;i<n;i++){cin>>x;a[x]++;
    if(a[x]==mx)d++;
    if(a[x]>mx){mx=a[x];d=1;}
    }
    int u=n-mx*d;
    int ans=u/(mx-1);
    ans+=d-1;
    cout<<ans<<endl;
}
    return 0;
}