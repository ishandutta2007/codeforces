// Hydro submission #62677d2a9f31360077e12d17@1650949419220
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,m,i;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n>>m;
        switch(n)
        {
            case 1:printf("0\n");break;
            case 2:printf("%d\n",m);break;
            default:printf("%d\n",m*2);break;
        }
    }
    return 0;
}