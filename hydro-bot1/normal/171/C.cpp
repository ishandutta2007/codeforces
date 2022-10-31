// Hydro submission #6253c423ca53060146715bf6@1649656868723
#include<bits/stdc++.h>
using namespace std;
int m[100],s;
int main()
{
    int n,i;
    cin>>n;
    for(i=0;i<n;i++)
    cin>>m[i];
    for(i=0;i<n;i++)
    s+=m[i]*(i+1);
    printf("%d\n",s);
    return 0;
}