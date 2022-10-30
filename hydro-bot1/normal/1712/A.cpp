// Hydro submission #62fb46204b7288bafe609c2c@1660634656891
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,k,p,s,i;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;s=0;
        for(i=1;i<=n;i++)
        {
            cin>>p;
            if(i<=k&&p>k) s++;
        }
        printf("%d\n",s);
    }
    return 0;
}