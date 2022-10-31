// Hydro submission #62550c56ac286d0a56b8685a@1649740904819
#include<bits/stdc++.h>
using namespace std;
bool u,d,l,r;
int main()
{
    int n,i;
    string s;
    cin>>n>>s;
    for(i=0;i<n;i++)
    {
	    if(s[i]==49||s[i]==50||s[i]==51) u=true;
	    if(s[i]==55||s[i]==48||s[i]==57) d=true;
	    if(s[i]==49||s[i]==52||s[i]==55||s[i]==48) l=true;
	    if(s[i]==51||s[i]==54||s[i]==57||s[i]==48) r=true;
    }
    if(u&&d&&l&&r)
    printf("YES\n");
    else printf("NO\n");
    return 0;
}