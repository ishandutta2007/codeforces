// Hydro submission #625505d417cd4d0a417646e8@1649739221149
#include<bits/stdc++.h>
using namespace std;
int main()
{
    char s;
    cin>>s;
    if(s>52&&s<57)
    printf("%c",105-s);
    else printf("%c",s);
    while(cin>>s)
    if(s>52&&s<58)
    printf("%c",105-s);
    else printf("%c",s);
    cout<<endl;
    return 0;
}