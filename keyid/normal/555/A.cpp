#include <bits/stdc++.h>
using namespace std;

const int MAXN=100005;

vector <int> a[MAXN];

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int rn=n;
    for (int i=0;i<k;i++)
    {
        int m;
        scanf("%d",&m);
        for (int j=0;j<m;j++)
        {
            int x;
            scanf("%d",&x);
            a[i].push_back(x);
        }
        if (a[i][0]==1)
            for (int j=1;j<m;j++)
                if (a[i][j]==j+1) rn--;
                else break;
    }
    printf("%d",rn-k+rn-1);
    return 0;
}