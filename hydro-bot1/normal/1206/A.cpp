// Hydro submission #625ceeca81ef68d42bcbb422@1650257611465
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,a,b,i,mxa=0,mxb=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a;
        mxa=max(mxa,a);
    }
    cin>>m;
    for(i=0;i<m;i++)
    {
        cin>>b;
        mxb=max(mxb,b);
    }
    printf("%d %d\n",mxa,mxb);
    return 0;
}