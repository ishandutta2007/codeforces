// Hydro submission #62590c6037de167dd82baf9a@1650003040991
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,s=0;
    cin>>a>>b;
    while(a<=b)
    {
        a*=3;
        b*=2;
        s++;
    }
    printf("%d\n",s);
    return 0;
}