// Hydro submission #62550520ac286d0a56b85859@1649739042166
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,d,e,f,g,h,i;
    cin>>a>>b>>c;
    d=a+b+c;
    e=a+b*c;
    f=(a+b)*c;
    g=a*b*c;
    h=a*b+c;
    i=a*(b+c);
    printf("%d\n",max(d,max(e,max(f,max(g,max(h,i))))));
    return 0;
}