// Hydro submission #626777d5255d14008c29996c@1650948053717
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int q,n,s,a,i,j;
    cin>>q;
    for(i=0;i<q;i++)
    {
        cin>>n;s=0;
        for(j=0;j<n;j++)
        cin>>a,s+=a;
        printf("%d\n",int(ceil(s*1.0/n)));
    }
    return 0;
}