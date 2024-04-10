// Hydro submission #6253c58aca53060146715e9b@1649657226882
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    if(k/n>=3)
    {
        printf("0\n");
        return 0;
    }
    printf("%d\n",n-(k-n*2));
    return 0;
}