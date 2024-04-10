// Hydro submission #62591db137de167dd82bc739@1650007474244
#include<bits/stdc++.h>
using namespace std;
int a[1000];
int main()
{
    int n,i,s=0;
    cin>>n;
    for(i=0;i<n;i++)
    cin>>a[i];
    for(i=1;i<n-1;i++)
    if(a[i]>a[i+1]&&a[i]>a[i-1]
    ||a[i]<a[i+1]&&a[i]<a[i-1])
    s++;printf("%d\n",s);
    return 0;
}