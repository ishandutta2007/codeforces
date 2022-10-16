#include <bits/stdc++.h>

using namespace std;

int dx[]={0, 0, -1, 1};
int dy[]={-1, 1, 0, 0};

int ans[2015];
int n, m, k;

char s[2015][2015];

int main()
{
cin>>n>>m>>k;


char c[]="RLDU";

    for(int i=0;i<n;i++)
    {
        scanf("%s", &s[i]);
    }

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
    {
        //i==nr pasului;
        for(int k=0;k<4;k++)
        if(0<i+(i-1)*dx[k] && i+(i-1)*dx[k]<=n && 0<j+(i-1)*dy[k] && j+(i-1)*dy[k]<=m)
            if(s[i+(i-1)*dx[k]-1][j+(i-1)*dy[k]-1]==c[k])
                ans[j]++;

    }


    for(int i=1;i<=m;i++)
        printf("%i ", ans[i]);

    return 0;
}