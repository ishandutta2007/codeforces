#include <stdio.h>
#include <vector>
#include <queue>
#define MAX 1000000001
struct Query{
    int x0;
    int y0;
    int weight;
}query[10010];
struct str{
    int node;
    long long int weight;
};
str Str(int a, long long int b)
{
    str A;
    A.node = a;
    A.weight = b;
    return A;
}
bool operator<(str a, str b)
{
    return a.weight>b.weight;
}
int q;
int dist[1010][1010];
long long int check[1010];
int start,end,a,b;
std::priority_queue<str> Q;
std::queue<int> Q2;
std::vector<int> V[1010];
long long int func(int k)
{
    for(int i=0;i<q;i++) if(query[i].weight==0) dist[query[i].x0][query[i].y0] = dist[query[i].y0][query[i].x0] = k;
    for(int i=0;i<=a;i++) check[i] = MAX;
    Q.push(Str(start,0));
    while(!Q.empty())
    {
        int x0 = Q.top().node;
        long long int y0 = Q.top().weight;
        Q.pop();
        if(check[x0]<=y0) continue;
        check[x0] = y0;
        for(int i=0;i<V[x0].size();i++)
        {
            if(check[V[x0][i]]<=y0+dist[x0][V[x0][i]]) continue;
            Q.push(Str(V[x0][i],y0+dist[x0][V[x0][i]]));
        }
    }
    return check[end];
}
long long int func2(int k)
{
    Q2.push(k);
    while(!Q2.empty())
    {
        int x0 = Q2.front();
        Q2.pop();
        for(int i=0;i<V[x0].size();i++) if(check[V[x0][i]]>check[x0]+dist[x0][V[x0][i]]) check[V[x0][i]] = check[x0]+dist[x0][V[x0][i]],Q2.push(V[x0][i]);
    }
    return check[end];
}
void printAns()
{
    for(int i=0;i<q;i++)
    {
        printf("%d %d %d\n",query[i].x0,query[i].y0,dist[query[i].x0][query[i].y0]);
    }
}
int main()
{
    int c,d,e,L;
    scanf("%d%d%d%d%d",&a,&b,&L,&start,&end);
    for(int i=0;i<=a;i++) for(int j=0;j<=a;j++) dist[i][j] = MAX;
    for(int i=1;i<=b;i++)
    {
        scanf("%d%d%d",&c,&d,&e);
        V[c].push_back(d);
        V[d].push_back(c);
        dist[c][d]=dist[d][c]=e;
        query[q].x0 = c, query[q].y0 =d ,query[q].weight=e, q++;
    }
    if(func(1)<=L&&L<=func(MAX))
    {
        printf("YES\n");
        if(func(1)==L)
        {
            printAns();
            return 0;
        }
        int min = 1, max = MAX , ans = 1;
        while(min<=max)
        {
            int h = (min+max)/2;
            long long int s = func(h);
            if(s==L)
            {
                printAns();
                return 0;
            }
            else if(s>L)
            {
                ans = h;
                max = h-1;
            }
            else min = h+1;
        }
        func(ans);

        for(int i=0;i<q;i++)
        {
            if(query[i].weight==0)
            {
                dist[query[i].x0][query[i].y0]--;
                dist[query[i].y0][query[i].x0]--;

                long long int s2;
                if(check[query[i].x0]<check[query[i].y0]) s2=func2(query[i].x0);
                else if(check[query[i].x0]>check[query[i].y0]) s2 = func2(query[i].y0);
                else continue;

                if(s2==L)
                {
                    printAns();
                    return 0;
                }
            }
        }
    }
    else printf("NO");
}