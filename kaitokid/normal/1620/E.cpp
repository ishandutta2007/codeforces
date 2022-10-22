#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int p[500009];
int t[500009],x[500009],y[500009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i=1;i<=500003;i++)p[i]=i;
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        cin>>t[i]>>x[i];
        if(t[i]==2)cin>>y[i];
    }
    vector<int>ans;
    for(int i=q-1;i>=0;i--)
    {
        if(t[i]==1){ans.push_back(p[x[i]]);continue;}
        p[x[i]]=p[y[i]];
    }
    reverse(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
    return 0;
}