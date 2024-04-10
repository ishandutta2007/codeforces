// Hydro submission #625cef4481ef68d42bcbb4e9@1650257732686
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[4],i;
    for(i=0;i<4;i++)
    cin>>a[i];
    sort(a,a+4);
    printf(a[1]+a[2]-a[0]-a[3]&&a[0]+a[1]+a[2]-a[3]?"NO\n":"YES\n");
    return 0;
}