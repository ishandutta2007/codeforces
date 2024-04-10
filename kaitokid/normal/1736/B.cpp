#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100009],ans[100009];
int gcd(int x,int y)
{
    return __gcd(x,y);

}
int lcm(int x,int y)
{
    if(x==0)return y;
    if(y==0)return x;
    int r=x*y;
    return r/__gcd(x,y);

}
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
        a[n]=0;
        ans[0]=a[0];
        for(int i=1;i<=n;i++)
            ans[i]=lcm(a[i-1],a[i]);
        bool res=true;
        for(int i=0;i<n;i++)
            if(gcd(ans[i],ans[i+1])!=a[i])res=false;
        if(res)cout<<"YES"<<endl;
          else cout<<"NO"<<endl;
    }

    return 0;

}