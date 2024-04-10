// Hydro submission #6259208fcc64917dc4665388@1650008208088
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,a,s=0,t=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a;
        if(a>0) s+=a;
        else t+=a;
    }
    printf("%d\n",s-t);
    return 0;
}