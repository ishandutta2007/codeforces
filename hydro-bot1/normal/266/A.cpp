// Hydro submission #6253ca81ca5306014671670f@1649658498952
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,t=0,i;string s;
    cin>>n>>s;
    for(i=1;i<n;i++)
    if(s[i]==s[i-1])
    t++;printf("%d\n",t);
    return 0;
}