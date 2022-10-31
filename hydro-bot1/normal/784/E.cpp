// Hydro submission #62590a23cc64917dc4664291@1650002511324
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    printf("%d\n",((a^b)&(c|d)^(b&c|a^d)));
    return 0;
}