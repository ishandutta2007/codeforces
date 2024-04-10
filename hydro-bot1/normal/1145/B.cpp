// Hydro submission #625cec6dfa9408d417fea9a6@1650257005721
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,b;cin>>n;a=n/10;b=n%10;
    printf(n>9&&n<30||a==1||a==7||a==9||b==1||b==7||b==9?(n==12?"YES\n":"NO\n"):"YES\n");
    return 0;
}