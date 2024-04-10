// Hydro submission #62550d4417cd4d0a41764d4f@1649741169607
#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
    int n,i;
    cin>>n>>s;
    for(i=0;i<n;i++)
    if(s[i]=='o'&&s[i+1]=='g'&&s[i+2]=='o')
    {
    	printf("***");i+=3;
    	while(s[i]=='g'&&s[i+1]=='o') i+=2;
    	i--;
	}
	else printf("%c",s[i]);
    return 0;
}