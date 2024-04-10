#include<bits/stdc++.h>
#define ll long long
ll a,b,c,d,e,f;

int main()
{
    std::cin>>a>>b>>c>>d>>e>>f;
    if(a+b+c == c+d+e && c+d+e == e+f+a) {
        printf("%lld",(a+b+c)*(a+b+c)-a*a-c*c-e*e);
    }
    else {
        printf("%lld",(b+c+d)*(b+c+d)-b*b-d*d-f*f);
    }
}