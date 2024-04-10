// Hydro submission #62550b50ac286d0a56b86424@1649740627192
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    if(a==1&&b==1) printf("0\n");
    else printf("%d\n",a+b-2-!((a-b)%3));
    return 0;
}