// Hydro submission #62550ca417cd4d0a41764c99@1649740967892
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i;cin>>n;
    for(i=1;i<n;i++)
    if(i%2) printf("I hate that ");
    else printf("I love that ");
    if(n%2) printf("I hate it\n");
    else printf("I love it\n");
    return 0;
}