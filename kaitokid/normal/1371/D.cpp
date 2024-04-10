#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int a[309][309];
int main()
{ios::sync_with_stdio(0);
int t;
cin>>t;
while(t--)
{
    int n,k;
    cin>>n>>k;
    ll ans=0;
    if((k%n)>0)ans=2;
for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)a[i][j]=0;

    for(int i=0;i<n;i++)
    {
        if(k==0)break;
    int u=0,q=i;
    while(u<n&&k>0)
    {
        a[q][u]=1;
        k--;
        u++;
        q++;
        //u%=n;
        q%=n;
    }
    }
    cout<<ans<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)cout<<a[i][j];
        cout<<endl;
    }
}
return 0;
}