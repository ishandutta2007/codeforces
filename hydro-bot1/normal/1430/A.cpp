// Hydro submission #6274cb20bda16328ffbaf840@1651821345039
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,a,b,c,i;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;
        if(n==1||n==2||n==4)
        {
            printf("-1\n");
            continue;
        }
        switch(n%3)
        {
            case 0:a=n/3,b=0,c=0;break;
            case 1:a=(n-7)/3,b=0,c=1;break;
            case 2:a=(n-5)/3,b=1,c=0;break;
        }
        printf("%d %d %d\n",a,b,c);
    }
    return 0;
}