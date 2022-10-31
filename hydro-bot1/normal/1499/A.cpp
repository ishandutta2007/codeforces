// Hydro submission #6274ceac997df5291339d7f9@1651822253416
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,k1,k2,w,b,i,j;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n>>k1>>k2>>w>>b;
        printf(2*w>k1+k2||2*b>2*n-k1-k2?"NO\n":"YES\n");
    }
    return 0;
}