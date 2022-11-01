#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
char s[N];
int n,f[10];
int main()
{
    scanf("%d",&n);
    scanf("%s",s+1);
    for(int i=1;i<=9;i++)
        scanf("%d",&f[i]);
    int i;
    for(i=1;i<=n;i++)
    {
        if(f[s[i]-'0']>s[i]-'0') break;
        putchar(s[i]);
    }
    for(;i<=n;i++)
    {
        if(f[s[i]-'0']<s[i]-'0') break;
        putchar(f[s[i]-'0']+'0');
    }
    for(;i<=n;i++)
        putchar(s[i]);
}