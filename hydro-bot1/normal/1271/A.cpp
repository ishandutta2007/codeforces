// Hydro submission #626778b89f31360077e12a84@1650948281356
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    printf("%d\n",e<f?min(min(b,c),d)*f+min(a,d-min(min(b,c),d))*e:min(a,d)*e+min(min(b,c),d-min(a,d))*f);
    return 0;
}