// Hydro submission #62972bfdb0c5e75beb158650@1654074365958
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
        if(k)
        {
            for(j=0;j<(n+1)/2;j++)
            if(s[j]-s[n-j-1])
            {
                printf("2\n");
                goto next;
            }
            printf("1\n");
            next:;
        }
        else printf("1\n");
    }
    return 0;
}