#include <iostream>
#include <cstdio>

using namespace std;

const int maxn=305;

int a[maxn][maxn];

int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<=n;i++)
    {
        for (int j=0;j<n;j++) scanf("%d",&a[i][j]);
    }
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++) if (a[i][j]!=i+1)
        {
            bool can=true;
            for (int k=0;k<n;k++)
            {
                if (a[n][k]<a[i][j] && a[n][k]!=i+1)
                {
                    can=false;
                }
                if (a[n][k]==a[i][j]) break;
            }
            if (can)
            {
                cout << a[i][j] << ' ';
                break;
            }
        }
    }
    return 0;
}