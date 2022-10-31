// Hydro submission #6254fd9817cd4d0a41763cef@1649737113153
#include<bits/stdc++.h>
using namespace std;
int a[4],t;
int main()
{
    int i;
    for(i=0;i<4;i++)
    cin>>a[i];
    string s;
    cin>>s;
    for(i=0;i<s.size();i++)
    t+=a[s[i]-49];
    printf("%d\n",t);
    return 0;
}