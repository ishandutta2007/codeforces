// Hydro submission #625cee3c81ef68d42bcbb2f2@1650257468968
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T,n,s,t,i;
    cin>>T;
    for(i=0;i<T;i++)
    {
        cin>>n>>s>>t;
        printf("%d\n",n-min(s,t)+1);
    }
    return 0;
}