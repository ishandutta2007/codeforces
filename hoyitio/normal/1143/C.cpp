#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;

const int MAXN = 1e5+10;
vector<int> G[MAXN];
int flag[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; i++)
    {
        int x;
        scanf("%d %d",&x,&flag[i]);
        if(x==-1)continue;
        G[x].push_back(i);
    }
    bool ans = false;
    for(int i = 1 ; i <= n ; i++)
    {
        bool r = false;
        for(int j = 0 ; j < G[i].size() ; j++)
        {
            if(!flag[G[i][j]])
            {
                r = true;
            }
        }
        if(flag[i]&&!r)
        {
            cout<<i<<" ";
            ans = true;
        }
    }
    if(!ans){cout<<"-1";}
    return 0;
}