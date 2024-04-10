#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[400009];
int spt[400009][20];
int lg[400009];
int cal(int x,int y)
{
    int z=lg[y-x+1];
//    cout<<x<<" "<<y<<" "<<z<<" "<<spt[x][z]<<" "<<spt[y-(1<<z)+1][z]<<endl;
    return __gcd(spt[x][z],spt[y-(1<<z)+1][z]);

}
int go(int x)
{
    //if(cal(0,x)>x+1)return -1;
    int l=0,r=x;
    while(l<r)
    {
        int mid=(l+r)/2;
        int z=cal(mid,x);
      //  cout<<endl<<mid<<" "<<x<<" "<<z<<endl;
        if(z==x-mid+1)return mid;
        if(z>x-mid+1)r=mid-1;
        else l=mid+1;
    }

    if(cal(l,x)==x-l+1)return l;
    return -1;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i=2;i<=200009;i++)
        lg[i]=lg[i-1]+ ((i&(i-1))==0);
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        spt[i][0]=a[i];
    }
    for(int j=1;(1<<j)<=n;j++)
        for(int i=0;i<n;i++)
        spt[i][j]=__gcd(spt[i][j-1],spt[i+(1<<(j-1))][j-1]);
    int mx=-1,ans=0;
    for(int i=0;i<n;i++)
    {
        int r=go(i);
        if(r==-1||r<=mx){cout<<ans<<" ";continue;}
        ans++;
        cout<<ans<<" ";
        mx=i;

    }
    return 0;
}