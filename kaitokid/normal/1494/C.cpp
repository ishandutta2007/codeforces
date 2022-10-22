#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
int t;
cin>>t;
while(t--)
{
    map<int,bool>mp[2];

    int n,m,x;
    cin>>n>>m;
    vector<int>a[2],b[2];
    for(int i=0;i<n;i++)
    {
        cin>>x;
        if(x>0)
        {a[1].push_back(x);mp[1][x]=true;}
        else {a[0].push_back(-x);mp[0][-x]=true;}
    }
     for(int i=0;i<m;i++)
    {
        cin>>x;
        if(x>0)
        b[1].push_back(x);
        else b[0].push_back(-x);
    }
    reverse(b[0].begin(),b[0].end());
    reverse(a[0].begin(),a[0].end());
    int ans[2]={0,0};
    for(int q=0;q<2;q++)
    {
for(int i=0;i<b[q].size();i++)
    if(mp[q][b[q][i]])ans[q]++;
        int j=0,f=0,gg=ans[q];
        for(int i=0;i<b[q].size();i++)
        {
            if(mp[q][b[q][i]])gg--;
            while(j<a[q].size()&&a[q][j]<=b[q][i])j++;
            int v=b[q][i]-j;
            while(f<b[q].size()&&b[q][f]<=v)f++;

            ans[q]=max(ans[q],i-f+gg+1);

        }
    }
    cout<<ans[0]+ans[1]<<endl;
}
    return 0;
}