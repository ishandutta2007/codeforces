#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int a[1009],n,p[1009];
bool ch(int x)
{
    for(int i=0;i<x;i++)
        for(int j=i;j<n;j+=x)
        if(p[j]!=p[i])return false;
    return true;
}
int main()
{ios::sync_with_stdio(0);
cin>>n;
for(int i=0;i<n;i++){cin>>a[i];p[i]=a[i]-a[i-1];}
vector<int>ans;
for(int i=1;i<=n;i++)
{
    if(ch(i))ans.push_back(i);

}
cout<<ans.size()<<endl;
for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";
    return 0;
}