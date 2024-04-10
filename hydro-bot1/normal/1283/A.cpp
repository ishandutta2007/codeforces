// Hydro submission #626778e0255d14008c299bc8@1650948321174
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,h,m,i;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>h>>m;
        printf("%d\n",1440-h*60-m);
    }
    return 0;
}