// Hydro submission #6274cfddbda16328ffbafddc@1651822558021
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,m,k,i;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n>>m>>k;
        printf(k+1-n*m?"NO\n":"YES\n");
    }
    return 0;
}