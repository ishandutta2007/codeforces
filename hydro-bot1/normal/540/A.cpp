// Hydro submission #6255062fac286d0a56b85bdc@1649739312420
#include<bits/stdc++.h>
using namespace std;
string a,b;
int s;
int main()
{
    int n,i;
    cin>>n>>a>>b;
    for(i=0;i<n;i++)
    s+=min(abs(a[i]-b[i]),10-abs(a[i]-b[i]));
    printf("%d\n",s);
    return 0;
}