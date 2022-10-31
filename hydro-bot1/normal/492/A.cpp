// Hydro submission #6255054717cd4d0a417646af@1649739080375
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,s;
    cin>>n;
    for(i=1;;i++)
    {
        s=0;
        for(j=1;j<i;j++)
        s+=j*(i-j);
        if(s>n)
        {
            printf("%d\n",i-2);
            return 0;
        }
    }
    return 0;
}