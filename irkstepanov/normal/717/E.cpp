#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;
vector<int>C;
vector<vector<int> > A;
void dfs(int v, int p)
{
    C[v] = 1^C[v];
    printf("%d ", v+1);
    for(auto w:A[v])
    {
        if (w==p)
        {
            continue;
        }
        dfs(w, v);
        printf("%d ", v+1);
        C[v] ^=1;
    }
    if (p==-1)
    {
        return;
    }
    if (C[v] == 0)
    {
        printf("%d ", p+1);
        C[p]^=1;
        printf("%d ", v+1);
        C[v] ^=1;
    }
}

int main()
{
    int N;
    //freopen("input.txt", "r", stdin);
    scanf("%d", &N);
    A.resize(N);
    C.resize(N);
    int all = 1;
    for(int i = 0; i < N; ++i)
    {
        scanf("%d", &C[i]);
        if (C[i] == -1)
        {
            C[i] = 0;
            all = 0;
        }
    }
    if (all)
    {
        cout<<1<<endl;
        return 0;
    }
    C[0]^=1;
    for(int i = 0; i < N-1; ++i)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        b--;
        A[a].push_back(b);
        A[b].push_back(a);
    }
    dfs(0,-1);
    if (C[0] == 0)
    {
        int v = 0;
        int w = A[v][0];
        printf("%d %d %d", w+1, 1+v, w+1);
    }
    printf("\n");
}