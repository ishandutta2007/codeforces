// Hydro submission #6253c72dca5306014671617a@1649657645539
#include<bits/stdc++.h>
using namespace std;
int t[24][60],mx;
int main()
{
    int n,h,m,i,j;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>h>>m;
        t[h][m]++;
    }
    for(i=0;i<24;i++)
    for(j=0;j<60;j++)
    if(t[i][j]>mx)
    mx=t[i][j];
    printf("%d\n",mx);
    return 0;
}