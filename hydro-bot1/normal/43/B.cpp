// Hydro submission #6247f818993deab6561077ee@1648883736733
#include<bits/stdc++.h>
using namespace std;
int ss[123],rr[123];
int main()
{
    string s,r;
    int i;
    getline(cin,s);
    getline(cin,r);
    for(i=0;i<s.size();i++)
    if(s[i]!=' ') ss[s[i]]++;
    for(i=0;i<r.size();i++)
    if(r[i]!=' ') rr[r[i]]++;
    for(i=65;i<123;i++)
    if(rr[i]>ss[i])
    {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    return 0;
}