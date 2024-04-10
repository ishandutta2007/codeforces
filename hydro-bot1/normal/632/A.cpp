// Hydro submission #62550b1b17cd4d0a41764acf@1649740572505
#include<bits/stdc++.h>
using namespace std;
string s[40];
long long t,m;
int main()
{
    int n,p,i;
    cin>>n>>p;
    for(i=0;i<n;i++)
    cin>>s[i];
    for(i=n-1;i+1;i--)
    {
        m*=2;
        if(s[i]=="halfplus") m++;
        t+=m;
    }
    printf("%lld\n",t*p/2);
    return 0;
}