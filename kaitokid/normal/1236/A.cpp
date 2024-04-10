#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    int t,a,b,c;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c;
        int ans=min(c/2,b);
        b-=ans;
        ans+=min(a,b/2);
        cout<<3*ans<<endl;
    }
    return 0;
}