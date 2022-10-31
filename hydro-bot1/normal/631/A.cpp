// Hydro submission #62550b0517cd4d0a41764ac3@1649740549991
#include<bits/stdc++.h>
using namespace std;
int s1,s2;
int main()
{
    int n,a,b,i;
    cin>>n;
    for(i=0;i<n;i++)
    cin>>a,s1|=a;
    for(i=0;i<n;i++)
    cin>>b,s2|=b;
    printf("%d\n",s1+s2);
    return 0;
}