// Hydro submission #62592165cc64917dc4665504@1650008424586
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,i;
    cin>>n>>k;
    for(i=0;i<k;i++)
    if(n%10) n--;
    else n/=10;
    printf("%d\n",n);
    return 0;
}