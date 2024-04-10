#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[400],b[400];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
int t;
cin>>t;
while(t--)
{
    int n,m,k;
    cin>>k>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<m;i++)cin>>b[i];
    int i=0,j=0;
    vector<int>ans;
    while(i<n || j<m)
    {
        if((i<n) && (a[i]<=k)){ans.push_back(a[i]);if(a[i]==0)k++;i++;continue;}
        if((j<m)&&(b[j]<=k)){ans.push_back(b[j]);if(b[j]==0)k++;j++;continue;}
        break;
    }
    if(ans.size() !=(n+m)){cout<<-1<<endl;continue;}
    for(int d=0;d<n+m;d++)cout<<ans[d]<<" ";
    cout<<endl;
}
    return 0;
}