// Hydro submission #6247f6d10bc575b66aa57fd5@1648883414776
#include<bits/stdc++.h>
using namespace std;
int d[100],s;
int main()
{
    int n,i,a,b;
    cin>>n;
    for(i=0;i<n-1;i++)
    cin>>d[i];
    cin>>a>>b;
    for(i=a;i<b;i++)
    s+=d[i-1];
    printf("%d\n",s);
    return 0;
}