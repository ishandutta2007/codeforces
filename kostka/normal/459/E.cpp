//Bartosz Kostka
//You are not prepared!

#include "bits/stdc++.h"

using namespace std;

const int MAXN = 300007,
          MAXE = 100007;

static vector <pair <int, int> > E[MAXE];
static int maxi[MAXN], tmp[MAXN];

int main()
{
    
    int n, m;
    scanf("%d%d", &n, &m);
    while(m--)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        E[c].push_back(make_pair(a,b));
    }
    for(int i=1; i<MAXE; i++)
    {
        for(auto edge : E[i])
        {
            tmp[edge.first] = 0;
            tmp[edge.second] = 0;
        }
        for(auto edge : E[i])
            tmp[edge.second] = max(tmp[edge.second], maxi[edge.first]+1);
        for(auto edge : E[i])
            maxi[edge.second] = max(maxi[edge.second], tmp[edge.second]);
    }
    int res = 0;
    for(int i=1; i<=n; i++)
    {
        //printf("%d ", maxi[i]);
        res = max(maxi[i], res);
    }
    printf("%d\n", res);
    return 0;
}