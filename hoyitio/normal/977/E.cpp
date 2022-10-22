#include<iostream>
#include<cstdio>


using namespace std;

const int MAXN = 2e5+10;

int p[MAXN],d[MAXN],ans[MAXN];

int found(int x)
{
    return p[x] == x ? x: p[x] = found(p[x]);
}
void unin(int a,int b)
{
    int x = found(a);
    int y = found(b);
    if(x!=y)
    {
        p[x] = y;
    }
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 0 ; i < n+10 ; i++)
    {
        p[i] = i;
        d[i] = 0;
    }
    while(m--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        d[a]++;
        d[b]++;
        unin(a,b);
    }

    for(int i = 1 ; i <= n; i++)
    {
        int root = found(i);
        if(ans[root] == -1){continue;}
        if(d[i] != 2){ans[root] = -1;}
        else{
            ans[root] = 1;
        }
    }
    int cnt = 0;
    for(int i = 1 ; i <= n; i++)
    {
        if(ans[i] == 1)cnt++;
    }
    printf("%d",cnt);
}