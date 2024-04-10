// Hydro submission #6259202fcc64917dc46652dd@1650008111806
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,s=0;
    cin>>n;
    for(i=1;i<n;i++)
    if(n%i==0) s++;
    printf("%d\n",s);
    return 0;
}