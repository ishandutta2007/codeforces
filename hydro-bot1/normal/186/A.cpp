// Hydro submission #6253c56248f7830132791cd1@1649657186716
#include<bits/stdc++.h>
using namespace std;
char s[10000001],r[10000001];
int main()
{
    cin>>s>>r;
    int ls=strlen(s),
    lr=strlen(r),i,t=0;
    if(ls!=lr)
    {
        printf("NO\n");
        return 0;
    }
    for(i=0;i<ls;i++)
    if(s[i]!=r[i]) t++;
    sort(s,s+ls);
    sort(r,r+lr);
    if(t==2&&strstr(s,r))
    printf("YES\n");
    else printf("NO\n");
    return 0;
}