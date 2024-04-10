// Hydro submission #6253b3eeca53060146714b12@1649652718931
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n%4)
    printf("%d\n",n*2-n/4-n/4-1);
    else
    printf("%d\n",n*2-n/4-n/4);
    return 0;
}