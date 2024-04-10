#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100];
int b[100];
void go(int l,int r)
{
    int u=a[r];
    for(int i=r;i>l;i--)a[i]=a[i-1];
    a[l]=u;
}
int main() {
ios::sync_with_stdio(0);
cin.tie(0);
int t;
cin>>t;
while(t--)
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    vector<pair<pair<int,int> ,int> > ans;
    for(int k=1;k<=n;k++)
    {
        int id=k;
        for(int j=k+1;j<=n;j++)if(a[j]<a[id])id=j;
        if(id==k)continue;
      //  cout<<k<<" "<<id<<endl;
        ans.push_back({{k,id},id-k});
        go(k,id);
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
        cout<<ans[i].first.first<<" "<<ans[i].first.second<<" "<<ans[i].second<<endl;

}
return 0;
}