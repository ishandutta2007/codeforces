// Hydro submission #625cec0981ef68d42bcbad8d@1650256907242
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,m=0;
    string s;
    cin>>n>>s;
    for(;i<n;i+=m+1,m++)
    printf("%c",s[i]);
    return 0;
}