// Hydro submission #62baa2215ffd6a7e32a8af09@1656398369361
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int x;
    cin>>s>>x;
    switch(s[1])
    {
        case 'B':printf(x<2000?"YES\n":"NO\n");break;
        case 'R':printf(x<2800?"YES\n":"NO\n");break;
        case 'G':printf(x>1199?"YES\n":"NO\n");break;
    }
    return 0;
}