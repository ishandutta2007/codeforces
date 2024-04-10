// Hydro submission #625ceefd81ef68d42bcbb456@1650257662586
#include<bits/stdc++.h>
using namespace std;
int o,e;
int main()
{
    int n,x,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>x;
        x%2?o++:e++;
    }
    printf("%d\n",min(o,e));
    return 0;
}