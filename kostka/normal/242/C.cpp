#include "bits/stdc++.h"

using namespace std;

set <pair <int, int> > S, O;
queue <pair <int, int> > Q[2];

int dx[] = {0,0,1,1,1,-1,-1,-1}, dy[] = {1,-1,1,0,-1,1,0,-1};

int bfs(int a, int b, int c, int d)
{
    O.insert(make_pair(a,b));
    Q[0].push(make_pair(a,b));
    for(int i=0; true; i++)
    {
        if(Q[i%2].empty())
            break;
        while(!Q[i%2].empty())
        {
            int a = Q[i%2].front().first, b = Q[i%2].front().second;
            Q[i%2].pop();
            for(int k=0; k<8; k++)
            {
                int na = a + dx[k], nb = b + dy[k];
                if(na == c && nb == d)
                    return i+1;
                if((O.find(make_pair(na,nb))==O.end()) && (S.find(make_pair(na,nb))!=S.end()))
                {
                    O.insert(make_pair(na,nb));
                    Q[(i+1)%2].push(make_pair(na,nb));
                }
            }
        }
    }
    return -1;
}

int main()
{
    int a,b,c,d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    int n;
    scanf("%d", &n);
    while(n--)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        for(int i=y; i<=z; i++)
            S.insert(make_pair(x,i));
    }
    printf("%d\n", bfs(a,b,c,d));
    return 0;
}