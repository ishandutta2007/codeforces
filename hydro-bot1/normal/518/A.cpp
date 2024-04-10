// Hydro submission #625505e5ac286d0a56b85ae1@1649739237450
#include<bits/stdc++.h>
using namespace std;
string s,t;
int main()
{
    cin>>s>>t;
    int l=s.size()-1;
    s[l]++;
    if(s<t) while(s[l]>122)
    s[l]-=26,s[--l]++;
    else
	{
		printf("No such string\n");
		return 0;
	}
    if(s<t) cout<<s;
	else printf("No such string\n"); 
    return 0;
}