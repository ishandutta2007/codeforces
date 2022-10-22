#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int N=1e5+5;

int dep_num[N];
vector<int>v[N];

void dfs(int u,int dep)
{
    dep_num[dep]++;
    for(int i=0;i<v[u].size();i++)
	{
        int t=v[u][i];
        dfs(t,dep+1);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=2;i<=n;i++)
	{
        int fa;
        scanf("%d",&fa);
        v[fa].push_back(i);
    }
    dfs(1,1);
    int ans=0;
    for(int i=0;i<N;i++)
	{
        ans+=dep_num[i]%2;
    }
    printf("%d\n",ans);
    return 0;
}