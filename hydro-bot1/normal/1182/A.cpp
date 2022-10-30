// Hydro submission #625cedca81ef68d42bcbb178@1650257354201
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n%2) printf("0\n");
    else printf("%d\n",1<<(n>>1));
    return 0;
}