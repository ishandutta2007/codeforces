// Hydro submission #6253b3a448f78301327912ae@1649652644792
#include<bits/stdc++.h>
using namespace std;
int m(string x)
{
    int s=0,i;
    for(i=0;i<x.size();i++)
    if(x[i]=='a'||x[i]=='e'||x[i]=='i'||x[i]=='o'||x[i]=='u')
    s++;
    return s;
}
int main()
{
    string a,b,c;
    getline(cin,a);
    getline(cin,b);
    getline(cin,c);
    if(m(a)==5&&m(b)==7&&m(c)==5)
    printf("YES\n");
    else printf("NO\n");
    return 0;
}