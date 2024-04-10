#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int a[100009];
int main()
{
    ios::sync_with_stdio(0);
int t;
cin>>t;
while(t--)
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    vector<int>ans;
    ans.push_back(a[0]);
    for(int i=1;i<n-1;i++)
    {
        if(a[i]>a[i-1]&&a[i]>a[i+1])ans.push_back(a[i]);
        else if(a[i]<a[i-1]&&a[i]<a[i+1])ans.push_back(a[i]);
    }
    ans.push_back(a[n-1]);
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
    cout<<endl;
}
       return 0;
}