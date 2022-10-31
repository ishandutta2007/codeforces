// Hydro submission #6254fdb8ac286d0a56b8509f@1649737154570
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,x,s1=0,s2=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>x;
        if(x==100) s1++;
        else s2++;
    }
    if(s2&1&&!s1||s1&1) printf("NO\n");
    else printf("YES\n");
    return 0;
}