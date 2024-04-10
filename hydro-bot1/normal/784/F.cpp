// Hydro submission #625a0bddcc64917dc4670fc6@1650068446627
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i;
    cin>>n;
    int a[n];
    for(i=0;i<n;++i)cin>>a[i];
    i=0;
    while(i<=10000000)stable_sort(a,a+n),i++;
    for(i=0;i<n;++i)cout<<a[i]<<" ";
}