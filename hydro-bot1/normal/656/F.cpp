// Hydro submission #62550ba1ac286d0a56b8656e@1649740713651
#include<bits/stdc++.h>
using namespace std;
int main()
{
    char s;int t=0;
    while(cin>>s)
    switch(s)
    {
        case 65:t++;break;
        case 49:t+=10;break;
        default:t+=s-48;break;
    }
    printf("%d\n",t);
    return 0;
}