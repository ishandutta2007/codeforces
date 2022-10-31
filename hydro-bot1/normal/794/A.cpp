// Hydro submission #62590c7537de167dd82bb00f@1650003070428
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,n,x,i,s=0;
    cin>>a>>b>>c>>n;
    for(i=0;i<n;i++)
    {
        cin>>x;
        if(x>b&&x<c)
        s++;
    }
    printf("%d\n",s);
    return 0;
}