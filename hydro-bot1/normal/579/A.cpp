// Hydro submission #6255071117cd4d0a4176480c@1649739538189
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x,s=0;
    cin>>x;
    while(x)
    {
        if(x%2)
        s++;
        x/=2;
    }
    printf("%d\n",s);
    return 0;
}