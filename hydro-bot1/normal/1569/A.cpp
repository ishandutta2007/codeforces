// Hydro submission #629728a5b0c5e75beb158082@1654073518627
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,l,r,i,j;
    string s;
    char c;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n>>s;
        c=s[0],l=-1,r=-1;
        for(j=1;j<n;j++)
        if(s[j]-c)
        {
            l=j,r=j+1;
            break;
        }
        printf("%d %d\n",l,r);
    }
    return 0;
}