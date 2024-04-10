#include <bits/stdc++.h>

using namespace std;
int l[500009],r[500009];
vector<int>v[500009];
int n,x,y;
vector<int>ans;
void go(int x,int pr)
{
    for(int i=0;i<v[x].size();i++)if(v[x][i]!=pr)go(v[x][i],x);
ans.push_back(x);
 for(int i=v[x].size()-1;i>=0;i--)if(v[x][i]!=pr)ans.push_back(-1*v[x][i]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    go(1,0);
    ans.push_back(-1);
    for(int i=0;i<2*n;i++)
        if(ans[i]>0)l[ans[i]]=i+1;
    else r[-1*ans[i]]=i+1;
    for(int i=1;i<=n;i++)cout<<l[i]<<" "<<r[i]<<endl;
    return 0;
}