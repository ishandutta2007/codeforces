// Hydro submission #631f2ee4bdf9bc31d15c8036@1662988004986
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        printf(n==1&&m==1?"0\n":"%d\n",min(n,m)+n+m-2);
    }
    return 0;
}