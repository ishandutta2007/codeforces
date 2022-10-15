#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        long long ans=1;
        for(int i=3;i<=n+n;i++)
            ans=ans*i%1000000007ll;
        cout<<ans<<endl;
    }
    return 0;
}