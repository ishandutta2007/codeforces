// Hydro submission #62550b6017cd4d0a41764b26@1649740642556
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int l,h,a,b,s=0;
    cin>>l>>h>>a>>b;
    if(a<=b&&h-l>8*a)
    {
        printf("-1\n");
        return 0;
    }
    l+=8*a;
    while(l<h)
    {
        l-=12*b;
        s++;
        l+=12*a;
    }
    printf("%d\n",s);
    return 0;
}