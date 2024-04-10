// Hydro submission #62972aaa1008115bd64b4ffa@1654074027267
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,m,k,i,j,l;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n>>k;
        if(2*k>n+1)
        {
            printf("-1\n");
            continue;
        }
        m=0;
        for(j=1;j<=n;j++)
        {
            for(l=1;l<=n;l++)
            if(j==l&&j%2&&m<k)
            printf("R"),m++;
            else printf(".");
            cout<<endl;
        }
    }
    return 0;
}