// Hydro submission #62be50b489ffbb18f0fdae8f@1656639669886
#include<bits/stdc++.h>
using namespace std;
int s[10001];
int main()
{
    int t,c1,c2,n,a,i;
    cin>>t;
    while(t--)
    {
        memset(s,0,sizeof(s));
        cin>>n;c1=0,c2=0;
        for(i=0;i<n;i++)
        {
            cin>>a;
            s[a]++;
        }
        for(i=1;i<10001;i++)
        if(s[i]) (s[i]%2?c1:c2)++;
        printf("%d\n",c1+c2/2*2);
    }
    return 0;
}