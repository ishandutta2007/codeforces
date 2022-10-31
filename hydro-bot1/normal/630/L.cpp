// Hydro submission #631f31e2bdf9bc31d15c86cd@1662988771183
#include<bits/stdc++.h>
using namespace std;
long long quick_pow(int a,int b,int p)
{
    if(!b) return 1;
    long long s=quick_pow(a,b/2,p);
    s=s*s%p;
    if(b%2) s=s*a%p;
    return s;
}
int main()
{
    int n;
    cin>>n;
    n=n/10000*10000+n/1000%10+n/100%10*1000+n/10%10*10+n%10*100;
    printf(n%10?"%d\n":"00000\n",quick_pow(n,5,100000));
    return 0;
}