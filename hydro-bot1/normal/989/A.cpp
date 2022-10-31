// Hydro submission #625922b437de167dd82bd5c4@1650008756518
#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;cin>>s;
	int l=s.size(),i;
	for(i=1;i<l-1;i++)
	if(s[i-1]!=46&&s[i]!=46&&s[i+1]!=46&&s[i]!=s[i-1]&&s[i]!=s[i+1]&&s[i-1]!=s[i+1])
	{
	    printf("Yes\n");
	    return 0;
	}
	printf("No\n");
	return 0;
}