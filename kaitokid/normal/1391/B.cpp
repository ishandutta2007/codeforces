#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
ios::sync_with_stdio(0);
int t,n,m;
string s;
cin>>t;
while(t--)
{
    int ans=0;
    cin>>n>>m;
    for(int i=0;i<n-1;i++)
    {
        cin>>s;
        if(s[m-1]!='D')ans++;
    }
    cin>>s;
    for(int i=0;i<m-1;i++)if(s[i]!='R')ans++;
    cout<<ans<<endl;
}
    return 0;
}