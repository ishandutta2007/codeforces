#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<int>ch[2009];
int n;
bool bl=false;
int c[2009],ans[2009];
vector<int> go(int x)
{
    vector<int> v,h,k;
    if(bl)return v;
    for(int i=0;i<ch[x].size();i++)
    {
        h=go(ch[x][i]);
        for(int j=0;j<h.size();j++)k.push_back(h[j]);

    }
    if(c[x]>k.size()){bl=true;return v;}
   for(int i=0;i<c[x];i++)v.push_back(k[i]);
   v.push_back(x);
   for(int i=c[x];i<k.size();i++)v.push_back(k[i]);
   return v;
}
int main()
{
ios::sync_with_stdio(0);
cin>>n;
int x;
for(int i=1;i<=n;i++)
{
    cin>>x>>c[i];
    ch[x].push_back(i);
}
vector<int> r=go(ch[0][0]);
if(bl){cout<<"NO";return 0;}
for(int i=0;i<n;i++)ans[r[i]]=i+1;
cout<<"YES\n";
for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
    return 0;
}