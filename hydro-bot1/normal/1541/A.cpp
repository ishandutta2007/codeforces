// Hydro submission #6274d63cbda16328ffbb022d@1651824189174
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,i,j;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;
        if(n%2)
        {
            printf("3 1 2");
            for(j=4;j<=n;j+=2)
            printf(" %d %d",j+1,j);
        }
        else
        {
            for(j=1;j<=n;j+=2)
            printf("%d %d ",j+1,j);
        }
        cout<<endl;
    }
    return 0;
}