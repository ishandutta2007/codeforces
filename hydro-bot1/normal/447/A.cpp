// Hydro submission #6254fe3bac286d0a56b851cd@1649737275944
#include<bits/stdc++.h>
using namespace std;
int x[300];
int main()
{
    int p,n,i,j;
    cin>>p>>n;
    for(i=0;i<n;i++)
    {
        cin>>x[i];
        x[i]%=p;
        for(j=0;j<i;j++)
        if(x[j]==x[i])
        {
            printf("%d\n",i+1);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}