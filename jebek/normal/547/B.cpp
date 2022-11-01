#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN=300000;
long long n,a[MAXN],dp[MAXN],b[MAXN],ans[MAXN],MAX;
vector<int>v;

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        while(v.size() && a[v.back()]>=a[i])
            v.pop_back();
        if(v.size()==0)
            dp[i]=i+1;
        else
            dp[i]=i-v.back();
        v.push_back(i);
    }
    v.clear();
    for(int i=n-1;i>-1;i--)
    {
        while(v.size() && a[v.back()]>=a[i])
            v.pop_back();
        if(v.size()==0)
            dp[i]+=n-i-1;
        else
            dp[i]+=v.back()-i-1;
        v.push_back(i);
    }
    for(int i=0;i<n;i++)
        b[dp[i]]=max(b[dp[i]],a[i]);
    for(int i=n;i>0;i--)
    {
        MAX=max(MAX,b[i]);
        ans[i]=MAX;
    }
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}