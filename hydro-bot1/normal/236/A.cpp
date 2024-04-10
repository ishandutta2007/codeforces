// Hydro submission #6253c71448f7830132791e06@1649657620391
#include<bits/stdc++.h>
using namespace std;
int s[26],t;
int main()
{
    char c;
    while(cin>>c)
    s[c-97]++;
    for(int i=0;i<26;i++)
    if(s[i]) t++;
    if(t%2) printf("IGNORE HIM!\n");
    else printf("CHAT WITH HER!\n");
    return 0;
}