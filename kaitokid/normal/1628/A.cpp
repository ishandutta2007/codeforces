#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[200009],lst[200009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    set<int>u;
    for(int i=0;i<=n+1;i++){lst[i]=-1;u.insert(i);}
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        lst[a[i]]=i;
    }
    vector<int>ans;
    int h=0;
    for(int i=0;i<n;i++)
    {
        u.erase(a[i]);
        int f=*u.begin();
        if(lst[f]>i)continue;
        ans.push_back(f);
        for(int j=h;j<=i;j++)u.insert(a[j]);
        h=i+1;
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
    cout<<endl;
    }
    return 0;
}