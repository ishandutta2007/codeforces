#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int a[200009],n;
int main()
{
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>a[i];
    vector<int>v;
    v.push_back(1);
    int u=1;
    for(int i=2;i<n;i++)
    if(a[i]<a[i-1]){v.push_back(u);u=1;}
    else u++;
    v.push_back(u);
    int ans=0,d=1;
    int l=1;
    while(l<v.size())
    {
        int u=l+d;
        d=0;
        while(l<v.size()&&l<u){d+=v[l];l++;}
        ans++;
    }
    cout<<ans<<endl;
    }
    return 0;
}