#include <bits/stdc++.h>
using namespace std;

const int MAXN=520;

bool one[MAXN][MAXN];

int main()
{
    int k;
    scanf("%d",&k);
    if (k==0) printf("+");
    else
    {
        one[0][0]=one[0][1]=one[1][0]=true;
        for (int j=1;j<k;j++)
        {
            int t=1<<j;
            for (int i=0;i<t;i++)
            {
                for (int l=0;l<t;l++)
                    one[i][l+t]=one[i][l];
                for (int l=0;l<t;l++)
                    one[i+t][l]=one[i][l];
                for (int l=0;l<t;l++)
                    one[i+t][l+t]=one[i][l+t]^1;
            }
        }
        k=1<<k;
        for (int i=0;i<k;i++)
        {
            for (int j=0;j<k;j++)
                putchar(one[i][j]?'+':'*');
            puts("");
        }
    }
    return 0;
}