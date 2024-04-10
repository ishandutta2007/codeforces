// Hydro submission #6274cb0cbda16328ffbaf821@1651821324918
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,x1,x2,y1,y2,s,i;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>x1>>y1>>x2>>y2;
        s=abs(x1-x2)+abs(y1-y2);
        printf("%d\n",x1-x2&&y1-y2?s+2:s);
    }
    return 0;
}