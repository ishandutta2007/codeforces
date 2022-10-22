#include <bits/stdc++.h>
using namespace std;
const int mn=1e4+10;
int ans[20][mn];
int main()
{
    int n,k,i,j;
    scanf("%d%d",&n,&k);
    for(i=0;i<k;i++){
        for(j=1<<i;j<min(n,1<<i+1);j++){
            ans[i][j]=j-(1<<i);
        }
        for(j=1<<i+1;j<n;j++)ans[i][j]=j;
    }
    for(i=0;i<k;i++){
        for(j=n-1;j>=0;j--)printf("%d ",n-ans[i][j]);
        printf("\n");
    }
}