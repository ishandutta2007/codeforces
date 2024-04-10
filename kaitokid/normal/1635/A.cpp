#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int ans=0,n,x;
        cin>>n;
        while(n--)
        {
            cin>>x;
            ans|=x;
        }
        cout<<ans<<endl;
    }
    return 0;
}