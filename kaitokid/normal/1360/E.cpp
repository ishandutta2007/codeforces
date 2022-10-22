#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
int t,n;
string v[50];
cin>>t;
while(t--)
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>v[i];
    bool ans=true;
    for(int i=n-2;i>=0;i--)
        for(int j=n-2;j>=0;j--)
    {
        if(v[i][j]=='0')continue;
        if(v[i+1][j]=='1'||v[i][j+1]=='1')continue;
        ans=false;
        break;

    }
    if(ans)cout<<"YES\n";
    else cout<<"NO\n";
}

    return 0;
}