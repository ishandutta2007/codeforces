#include<bits/stdc++.h>
#define int long long
using namespace std;
int log(int a,int b)
{
    int x=1;
    int ans=0;
    while(x<=b)
    {
        x*=a;
        ans++;
    }
    return ans;
}
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        int addadd=0;
        if(b==1)
        {
            b++;
            addadd++;
        }
        int xx=log(b,a);
        int xxx=xx;
        for(int i=b;i<=b+xxx;i++)
        {
            xx=min(xx,i-b+log(i,a));
        }
        cout<<xx+addadd<<endl;
    }
    return 0;
}