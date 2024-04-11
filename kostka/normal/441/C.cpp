#include "bits/stdc++.h"

using namespace std;

vector <pair <int, int> > X[100007];

int main()
{
    int n, m, k, nr = 2;
    scanf("%d%d%d", &n, &m, &k);
    for(int i=0; i<n; i++)
    {
        if(i%2==0)
        {
            for(int j=0; j<m; j++)
                X[min((nr++)/2,k)].push_back(make_pair(i+1,j+1));
        }
        else
        {
            for(int j=m-1; j>=0; j--)
                X[min((nr++)/2,k)].push_back(make_pair(i+1,j+1));
        }
    }
    for(int i=1; i<=k; i++)
    {
        printf("%d ", (int)X[i].size());
        for(int j=0; j<(int)X[i].size(); j++)
            printf("%d %d ", X[i][j].first, X[i][j].second);
        printf("\n");
    }
    return 0;
}