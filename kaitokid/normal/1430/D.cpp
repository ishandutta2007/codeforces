#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n,t;
string s;

int main()
{
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--)
    {
        vector<int>v;
    cin>>n>>s;
    int u=1;
    for(int i=1;i<n;i++)
        if(s[i]!=s[i-1]){v.push_back(u);u=1;}
    else u++;
    v.push_back(u);
    u=0;
    int ans=0;
    for(int i=0;i<v.size();i++)
    {
        u++;
        int d=min(v[i]-1,u);
        ans+=d;
        u-=d;
}
    ans+=(u+1)/2;
    cout<<ans<<endl;
    }
    return 0;
}