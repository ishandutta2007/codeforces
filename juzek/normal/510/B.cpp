#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

char tab[51][51];

vector<pair<int,int> >v[50][50];

int zbiory[51][51];

bool dfs(int a,int b,int pa,int pb,int zbior)
{
    zbiory[a][b] = zbior;
    for (vector<pair<int,int> >::iterator it = v[a][b].begin();it != v[a][b].end();it++)
    {
        if (zbiory[(*it).first][(*it).second] == zbior)
        {
            if ((*it).first != pa && (*it).second != pb)
                return true;
        }
        else
        {
            if (dfs((*it).first,(*it).second,a,b,zbior))
                return true;
        }
    }
    return false;
}

int main()
{
    int N,M;
    scanf("%d %d",&N,&M);
    for (int i = 0;i < N;i++)
    {
        for (int  w = 0;w < M;w++)
        {
            scanf(" %c",&tab[i][w]);
        }
    }
    for (int i = 0;i < N;i++)
    {
        for (int w = 0;w < M;w++)
        {
            if (tab[i][w] == tab[i+1][w])
                v[i][w].push_back(make_pair(i+1,w));

            if (i != 0)
                if (tab[i][w] == tab[i-1][w])
                    v[i][w].push_back(make_pair(i-1,w));

            if (tab[i][w] == tab[i][w+1])
                v[i][w].push_back(make_pair(i,w+1));

            if (w != 0)
                if (tab[i][w] == tab[i][w-1])
                    v[i][w].push_back(make_pair(i,w-1));
        }
    }
    int num = 1;
    bool odp = false;
    for (int i = 0;i < N;i++)
    {
        for (int w = 0;w < M;w++)
        {
            if (zbiory[i][w] == 0)
            {
                odp = dfs(i,w,-1,-1,num);
                num++;
                if (odp)
                {
                    printf("Yes");
                    return 0;
                }
            }
        }
    }
    printf("No");
    return 0;
}