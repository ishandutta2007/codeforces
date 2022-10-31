// Hydro submission #6253d4a048f7830132792a1c@1649661089178
#include<bits/stdc++.h>
using namespace std;
int a[100];
int main()
{
    int n,i;
    cin>>n;
    for(i=0;i<n;i++)
    cin>>a[i];
    sort(a,a+n);
    for(i=0;i<n;i++)
    printf("%d ",a[i]);
    return 0;
}