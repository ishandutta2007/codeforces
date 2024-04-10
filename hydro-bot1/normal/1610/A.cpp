// Hydro submission #629729d01008115bd64b4f40@1654073816786
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,m,i;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n>>m;
        printf("%d\n",n*m-1?(n-1&&m-1?2:1):0);
    }
    return 0;
}