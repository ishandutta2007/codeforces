// Hydro submission #62590c3f37de167dd82baf1a@1650003025640
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if((d-b)%__gcd(a,c)) 
    {
        printf("-1\n");
        return 0;
    }
    while(b-d)
    b<d?b+=a:d+=c;
    printf("%d\n",b);
    return 0;
}