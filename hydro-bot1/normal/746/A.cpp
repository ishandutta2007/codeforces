// Hydro submission #62550f2717cd4d0a41764e25@1649741618701
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    printf("%d\n",min(a,min(b/2,c/4))*7);
    return 0;
}