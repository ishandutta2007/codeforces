// Hydro submission #6274ce84bda16328ffbafc85@1651822212861
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,k,i,j;
    cin>>t;
    string s;
    for(i=0;i<t;i++)
    {
        cin>>n>>k>>s;
        for(j=0;j<n-2-j;j++)
        if(s[j]-s[n-1-j]) break;
        printf(j<k?"NO\n":"YES\n");
    }
    return 0;
}