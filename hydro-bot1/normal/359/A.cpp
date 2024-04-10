// Hydro submission #6253d346ca53060146717233@1649660743289
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,a,i,j;
    cin>>n>>m;
    for(i=0;i<n;i++)
    for(j=0;j<m;j++)
    {
        cin>>a;
        if(a&&(!i||!j||i==n-1||j==m-1))
        {
            printf("2\n");
            return 0;
        }
    }
    printf("4\n");
    return 0;
}