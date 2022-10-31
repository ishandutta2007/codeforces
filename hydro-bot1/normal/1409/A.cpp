// Hydro submission #6274ca0f997df5291339c97d@1651821072621
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,a,b,c,i;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>a>>b;
        c=abs(a-b);
        printf("%d\n",c%10?c/10+1:c/10);
    }
    return 0;
}