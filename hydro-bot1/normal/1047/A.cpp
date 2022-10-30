// Hydro submission #625cead681ef68d42bcbaa32@1650256599252
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if((n-2)%3) printf("1 1 %d\n",n-2);
    else printf("1 2 %d\n",n-3);
    return 0;
}