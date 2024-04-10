#include <bits/stdc++.h>

using namespace std;

int n,x,cnt=1,a[10003];
vector <int> tree[10003];
void dfs(int i)
{
    for(int j=0;j<tree[i].size();j++)
    {
        if(a[tree[i][j]]!=a[i])cnt++;
        dfs(tree[i][j]);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
cin>>n;
for(int i=2;i<=n;i++)
   cin>>x,tree[x].push_back(i);
   for(int i=1;i<=n;i++) cin>>a[i];
   dfs(1);
   cout<<cnt;

    return 0;
}