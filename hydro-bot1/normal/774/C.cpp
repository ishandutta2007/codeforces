// Hydro submission #62590b22cc64917dc46642c4@1650002723883
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;
    if(n>2&&n&1)
    printf("7"),n-=3;
    while(n)
    printf("1"),n-=2;
    cout<<endl;
    return 0;
}