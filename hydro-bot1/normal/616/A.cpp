// Hydro submission #6255079817cd4d0a4176488e@1649739673480
#include<bits/stdc++.h>
using namespace std;
int l1,l2;
string s1,s2;
int main()
{
	cin>>s1>>s2;
	while(s1[l1]=='0') l1++;
	while(s2[l2]=='0') l2++;
	s1.erase(0,l1);
	s2.erase(0,l2);
	if(s1.length()>s2.length()) printf(">\n");
	else if(s1.length()<s2.length()) printf("<\n");
	else if(s1>s2) printf(">\n");
	else if(s1<s2) printf("<\n");
	else printf("=\n");
	return 0;
}