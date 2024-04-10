// Hydro submission #6274d6c3bda16328ffbb02cf@1651824324889
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,c1,c2,i;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;
        c1=c2=n/3;
        switch(n-c1*1-c2*2)
        {
            case 1:c1++;break;
            case 2:c2++;break;
        }
        printf("%d %d\n",c1,c2);
    }
}