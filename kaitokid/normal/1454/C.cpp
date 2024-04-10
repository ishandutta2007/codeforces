#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<int> a[200009];

int main()
{ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {a[i].clear();
        a[i].push_back(0);}
        int x;
        for(int i=1;i<=n;i++)
{
    cin>>x;
    a[x].push_back(i);
}
for(int i=1;i<=n;i++)a[i].push_back(n+1);
int ans=1e9;
for(int i=1;i<=n;i++)
{
    if(a[i].size()==2)continue;
    int res=0;
    for(int j=1;j<a[i].size();j++)
        if(a[i][j]!=a[i][j-1]+1)res++;
    ans=min(ans,res);
}
cout<<ans<<endl;
    }
    return 0;
}