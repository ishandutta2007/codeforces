// Hydro submission #6274cad5997df5291339cc28@1651821270264
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,x,i,j,s;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n>>x;
        if(n==1||n==2)
        printf("1\n");
        else printf("%d\n",int(ceil((n-2)*1.0/x)+1));
    }
    return 0;
}