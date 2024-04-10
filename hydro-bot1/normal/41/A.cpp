// Hydro submission #6247f7bc993deab6561077a7@1648883645381
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s,r;
    cin>>s>>r;
    reverse(s.begin(),s.end());
    if(s==r)
    printf("YES\n");
    else printf("NO\n");
    return 0;
}