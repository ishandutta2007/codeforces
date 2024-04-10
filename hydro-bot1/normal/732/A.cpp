// Hydro submission #62550d5817cd4d0a41764d56@1649741263476
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k,r,i;
    cin>>k>>r;
    for(i=1;;i++)
    if(i*k%10==r||i*k%10==0)
    {
        printf("%d\n",i);
        break;
    }
    return 0;
}