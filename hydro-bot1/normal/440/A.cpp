// Hydro submission #6254fdf6ac286d0a56b85112@1649737207100
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,a;
    cin>>n;
    n=(n+1)*n/2;
    while(cin>>a)
    n-=a;
    printf("%d\n",n);
    return 0;
}