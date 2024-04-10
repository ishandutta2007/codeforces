#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        int ans=0,u=0;

        cin>>n;
        int r=n;
        while(n>=10)
        {u++;
        n/=10;
        }
        ans=u*9+n-1;
        int d=0;
        for(int i=0;i<=u;i++)d=d*10+n;
        if(d<=r)ans++;
        cout<<ans<<endl;

    }
    return 0;
}