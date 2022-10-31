// Hydro submission #62677cfd9f31360077e12cf6@1650949373658
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,k,i,j;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n>>k;
        if(n%2)
        for(j=2;j<=n;j++)
        if(n%j==0)
        {
            n+=j;
            k--;
            break;
        }
        printf("%d\n",n+2*k);
    }
    return 0;
}