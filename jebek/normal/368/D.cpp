#include <iostream>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;

long long n,k,p,a[300000],b[300000];
map<int,int>m;
vector<int>ans;

void dp(int x,int f)
{
    if((x-f)/p==k)
    {
        ans.push_back(f);
        m[a[f]]++;
        f+=p;
    }
    if(x>=n)
    {
        while(f<n)
        {
            m[a[f]]++;
            f+=p;
        }
        return;
    }
    while(f<x && m[a[x]]<=0)
    {
        m[a[f]]++;
        f+=p;
    }
   // cout<<x<<" "<<f<<endl;
    if(m[a[x]]<=0)
        dp(x+p,x+p);
    else
    {
        m[a[x]]--;
        dp(x+p,f);
    }
}

int main()
{
    cin>>n>>k>>p;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<k;i++)
    {
            cin>>b[i];
            m[b[i]]++;
    }
    for(int j=0;j<p;j++)
        dp(j,j);
    cout<<ans.size()<<endl;
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]+1<<" ";
    cout<<endl;
}