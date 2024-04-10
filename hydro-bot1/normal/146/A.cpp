// Hydro submission #6253c2edca530601467159d9@1649656557365
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,sl=0,sr=0;string s;
    cin>>n>>s;
    for(i=0;i<n;i++)
    if(s[i]!=52&&s[i]!=55)
    {
        printf("NO\n");
        return 0;
    }
    for(i=0;i<n/2;i++)
    sl+=s[i]-48;
    for(i=n/2;i<n;i++)
    sr+=s[i]-48;
    if(sl!=sr) printf("NO\n");
    else printf("YES\n");
    return 0;
}