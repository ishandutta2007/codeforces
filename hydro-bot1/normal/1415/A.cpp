// Hydro submission #6274ca69bda16328ffbaf76c@1651821162773
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,m,r,c,i;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n>>m>>r>>c;
        printf("%d\n",max(max(max(n-r+c-1,r-c+m-1),r+c-2),n-r+m-c));
    }
    return 0;
}