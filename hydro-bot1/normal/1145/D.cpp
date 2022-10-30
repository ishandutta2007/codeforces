// Hydro submission #625cec9e81ef68d42bcbaed6@1650257055028
#include<bits/stdc++.h>
using namespace std;
int a[10];
int main()
{
    int n,i,mn=32;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        mn=min(mn,a[i]);
    }
    printf("%d\n",2+(mn^a[2]));
    return 0;
}