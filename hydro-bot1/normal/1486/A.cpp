// Hydro submission #6274cdd7bda16328ffbafb41@1651822040431
#include<bits/stdc++.h>
using namespace std;
long long h[100],s;
int main()
{
    int t,n,i,j;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;
        for(j=0;j<n;j++)
        cin>>h[j];
        for(j=0;j<n;j++)
        {
            if(h[j]<j)
            {
                printf("NO\n");
                goto next;
            }
            s=h[j]-j;
            h[j+1]+=s;
            h[j]-=s;
        }
        printf("YES\n");
        next:;
    
    }
    return 0;
}