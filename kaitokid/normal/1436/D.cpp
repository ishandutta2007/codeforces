#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll a[200009],num[200009],n,mx[200009];
vector<int>ch[200009];
void go(int x)
{
    if(ch[x].empty()){mx[x]=a[x];num[x]=1;return;}
    for(int i=0;i<ch[x].size();i++)
    {
        go(ch[x][i]);
        num[x]+=num[ch[x][i]];
        a[x]+=a[ch[x][i]];
        mx[x]=max(mx[x],mx[ch[x][i]]);

    }
    mx[x]=max(mx[x],(a[x]+num[x]-1)/num[x]);
}
int main()
{
    ios::sync_with_stdio(0);
cin>>n;
int x;
for(int i=2;i<=n;i++)
{
    cin>>x;
    ch[x].push_back(i);
}
for(int i=1;i<=n;i++)
    cin>>a[i];
go(1);
cout<<mx[1];
return 0;
}