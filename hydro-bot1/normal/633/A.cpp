// Hydro submission #62550b2b17cd4d0a41764ae1@1649740588200
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,x,y;
    cin>>a>>b>>c;
    for(x=0;a*x<=c;x++)
    for(y=0;b*y<=c;y++)
    if(a*x+b*y==c)
    {
        printf("Yes\n");
        return 0;
    }
    printf("No\n");
    return 0;
}