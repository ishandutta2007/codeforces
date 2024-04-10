// Hydro submission #625cede381ef68d42bcbb1a1@1650257380071
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,s,n,i;
    cin>>a;
    for(i=a;;i++)
    {
        n=i,s=0;
        while(n)
        s+=n%10,n/=10;
        if(s%4==0)
        {
            printf("%d\n",i);
            return 0;
        }
    }
    return 0;
}