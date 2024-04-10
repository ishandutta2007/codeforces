#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
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
    int x;
    vector<int>u;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        if((x==1)||(x==n))u.push_back(i);
    }
    int ans=u[1];
    ans=min(ans,n-u[0]+1);
    ans=min(ans,n-u[1]+1+u[0]);
    cout<<ans<<endl;}
    return 0;
}