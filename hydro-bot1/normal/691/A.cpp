// Hydro submission #62550c6c17cd4d0a41764c79@1649740923807
#include<bits/stdc++.h>
using namespace std;
int s[2];
int main()
{
    int a,n,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a;
        if(n==1)
        {
            if(a==1) printf("YES\n");
            else printf("NO\n");
            return 0;
        }
        else s[a]++;
    }
    if(s[0]==1) printf("YES\n");
    else printf("NO\n");
    return 0;
}