// Hydro submission #625925a5cc64917dc4665acd@1650009509192
#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;cin>>s;
	int l=s.size(),t=0,i;
	for(i=0;i<l/2;i++)
	{
		if(s[i]!=s[l-i-1])
		{
			printf("%d\n",l);
			return 0;
		}
		if(s[i]!=s[i+1]) t++;
	}
	if(t) printf("%d\n",l-1); 
    else printf("0\n");
	return 0;
}