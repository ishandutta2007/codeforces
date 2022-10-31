// Hydro submission #6255076eac286d0a56b85fb8@1649739631316
#include<bits/stdc++.h>
using namespace std;
int a[100],s;
int main()
{
    int n,m,i;
    cin>>n>>m;
    for(i=0;i<n;i++)
    cin>>a[i];
    sort(a,a+n);
    for(i=n-1;i+1;i--)
    {
        s+=a[i];
        if(s>=m)
        {
            printf("%d\n",n-i);
            return 0;
        }
    }
    return 0;
}