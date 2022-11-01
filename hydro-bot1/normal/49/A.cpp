// Hydro submission #6247f968993deab656107b4a@1648884073409
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i;
    string s;char c;
    getline(cin,s);
    for(i=0;i<s.size();i++)
    if(s[i]>=65&&s[i]<=90||s[i]>=97&&s[i]<=122)
    c=s[i];
    if(c=='A'||c=='a'||c=='E'||c=='e'
    ||c=='I'||c=='i'||c=='O'||c=='o'
    ||c=='U'||c=='u'||c=='Y'||c=='y')
    printf("YES\n");
    else printf("NO\n");
    return 0;
}