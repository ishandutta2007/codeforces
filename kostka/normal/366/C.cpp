//Bartosz Kostka
//You are not prepared!

#include "bits/stdc++.h"

using namespace std;

int pos[2][200007];

const int MAXN = 107;
int a[MAXN], b[MAXN];

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i=0; i<n; i++)
        scanf("%d", a+i);
    for(int i=0; i<n; i++)
    {
        scanf("%d", b+i);
        b[i] *= k;
    }
    pos[1][100000] = 1;
    for(int i=0; i<n; i++)
    {
        int pre = (i+1)%2, cur = i%2;
        int dif = a[i]-b[i];
        for(int j=0; j<=200000; j++)
            pos[cur][j] = 0;
        for(int j=0; j<=200000; j++)
            if(pos[pre][j])
                pos[cur][j+dif] = max(pos[cur][j+dif], pos[pre][j]+a[i]);
        for(int j=0; j<=200000; j++)
            pos[cur][j] = max(pos[cur][j], pos[pre][j]);
    }
    if(pos[(n-1)%2][100000] != 1)
        printf("%d\n", pos[(n-1)%2][100000]-1);
    else
        printf("-1\n");
    return 0;
}