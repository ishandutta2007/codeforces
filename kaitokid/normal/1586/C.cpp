#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s[1000009];
vector<int>v[1000009];
int mx[1000009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>s[i];
    for(int j=0;j<m;j++)v[0].push_back(0);
    for(int i=1;i<n;i++)
    for(int j=0;j<m;j++)
    {
        int r=j;
        if(i>0 && s[i-1][j]=='.')r=min(r,v[i-1][j]);
        if(j>0 && s[i][j-1]=='.')r=min(r,v[i][j-1]);

        v[i].push_back(r);

    }
    for(int i=0;i<m;i++)
    {
        mx[i]=0;
        for(int j=0;j<n;j++)mx[i]=max(mx[i],v[j][i]);
        if(i>0)mx[i]=max(mx[i],mx[i-1]);
    }
    int q;
    cin>>q;
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        x--,y--;
        if(mx[y]>x)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }

    return 0;
}