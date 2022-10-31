// Hydro submission #6253c396ca53060146715b19@1649656727440
#include<bits/stdc++.h>
using namespace std;
int m[100],s,u;
int main()
{
    int n,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>m[i];
        u+=m[i];
    }
    sort(m,m+n);
    for(i=n-1;i+1;i--)
    {
        s+=m[i];
        if(s>u-s)
        {
            printf("%d\n",n-i);
            return 0;
        }
    }
    return 0;
}