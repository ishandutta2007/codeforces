// Hydro submission #6274cb94997df5291339ce96@1651821460167
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,i;
    char a[200];
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n>>a;
        sort(a,a+n);
        printf("%s\n",a);
    }
    return 0;
}