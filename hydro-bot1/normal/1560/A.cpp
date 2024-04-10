// Hydro submission #6274d757997df5291339e5e6@1651824472331
#include<bits/stdc++.h>
using namespace std;
int a[1000],s;
int main()
{
    int t,k,i;
    for(i=1;s<1000;i++)
    if(i%3&&i%10-3)
    a[s]=i,s++;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>k;
        printf("%d\n",a[k-1]);
    }
    return 0;
}