// Hydro submission #6259232637de167dd82bd8d0@1650008871018
#include<bits/stdc++.h>
using namespace std;
int s[100],mx;
int main()
{
    int n,a,i;
    cin>>n;
    for(i=0;i<n;i++)
    cin>>a,s[a-1]++;
    for(i=0;i<100;i++)
    if(s[i]>mx) mx=s[i];
    printf("%d\n",mx);
    return 0;
}