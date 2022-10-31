// Hydro submission #62677d5e255d14008c29a395@1650949471289
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,m,s,i;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n>>m;
        s=n*m;
        printf("%d\n",int(ceil(s*1.0/2)));
    }
    return 0;
}