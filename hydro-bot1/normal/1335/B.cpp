// Hydro submission #62677c6b9f31360077e12c40@1650949227888
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,m,a,b,i,j;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n>>a>>b;m=0;
        for(j=1;j<=n;j++,m++,m%=b)
        printf("%c",m+97);
        cout<<endl;
    }
    return 0;
}