// Hydro submission #6247fa01993deab656107c59@1648884225907
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i;
    cin>>n;
    for(i=0;i<n;i++)
    if(pow(2,i)==n)
    {
        printf("YES\n");
        return 0;
    }
    printf("NO\n");
    return 0;
}