// Hydro submission #62550f89ac286d0a56b87176@1649741714327
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,z,i,s=0;
    cin>>n>>m>>z;
    for(i=max(n,m);i<=z;i++)
    if(i%n==0&&i%m==0) s++;
    printf("%d\n",s);
    return 0;
}