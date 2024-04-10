// Hydro submission #62590ceb37de167dd82bb16f@1650003182207
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,s=1,i;
    cin>>a>>b;
    for(i=1;i<=min(a,b);i++)
    s*=i;
    printf("%d\n",s);
    return 0;
}