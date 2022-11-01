#include <bits/stdc++.h>
using namespace std;

int h[2000007];
int sh[2000007];
int w[2000007];

int main()
{
    int N;
    scanf("%d",&N);
    long long sumi = 0;
    for (int i = 0;i < N;i++)
    {
        scanf("%d %d",&w[i],&h[i]);
        sumi += w[i];
        sh[i] = h[i];
    }
    sort(sh,sh+N);
    long long maxsh = sh[N-1];
    long long maxsh1 = sh[N-2];
    for (int i = 0;i < N;i++)
    {
        if (h[i] == maxsh)
        {
            printf("%I64d ",(sumi-w[i])*maxsh1);
        }
        else
        {
            printf("%I64d ",(sumi-w[i])*maxsh);
        }
    }
    return 0;
}