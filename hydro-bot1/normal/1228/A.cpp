// Hydro submission #62a5a964cd1ee6a7e16ba1c9@1655023972693
#include<bits/stdc++.h>
using namespace std;
bool f[10],g;
int main()
{
    int l,r,i,j;
    cin>>l>>r;
    for(i=l;i<=r;i++)
    {
        for(j=0;j<10;j++)
        f[j]=false;g=false,j=i;
        while(j)
        {
            if(f[j%10]) g=true;
            else f[j%10]=true;
            j/=10;
        }
        if(!g)
        {
            printf("%d\n",i);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}