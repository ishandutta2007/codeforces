// Hydro submission #6253d120ca53060146716f69@1649660193551
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,i,s=0;char c;
    cin>>n>>k;
    for(i=0;i<n;i++)
    {
        cin>>c;
        if(c=='#') s++;
        else s=0;
        if(s==k)
        {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}