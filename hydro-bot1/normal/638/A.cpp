// Hydro submission #62550b3e17cd4d0a41764af4@1649740606786
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a;
    cin>>n>>a;
    if(a%2) printf("%d\n",(a+1)/2);
    else printf("%d\n",(n+2-a)/2);
    return 0;
}