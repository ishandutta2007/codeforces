// Hydro submission #62550578ac286d0a56b859af@1649739128685
#include<bits/stdc++.h>
using namespace std;
int m[10][10];
int main()
{
    int n,i,j;
    cin>>n;
    for(i=0;i<n;i++)
    m[i][0]=m[0][i]=1;
    for(i=1;i<n;i++)
    for(j=1;j<n;j++)
    m[i][j]=m[i-1][j]+m[i][j-1];
    printf("%d\n",m[n-1][n-1]);
    return 0;
}