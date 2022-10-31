// Hydro submission #62550b7fac286d0a56b864d1@1649740680469
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,i;cin>>a;long long s=1;
    for(i=0;i<min(a,13);i++)s*=2;
    if(a<13) printf("%d\n",s);
    else
    {
        s-=100;for(i=13;i<a;i++)
        s*=2;printf("%lld\n",s);
    }
    return 0;
}