// Hydro submission #6274cffbbda16328ffbafe06@1651822589464
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,s,x,y,m,i,j;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;
        x=n;s=0;
        while(x)
        {
            s++;
            m=x%10;
            x/=10;
        }
        y=m;for(j=0;j<s-1;j++)
        y=y*10+m;s=(s-1)*9+m;
        printf("%d\n",n<y?s-1:s);
    }
    return 0;
}