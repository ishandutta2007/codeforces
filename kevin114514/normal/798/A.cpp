#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s,t;
	cin>>s;
	t=s;
	reverse(s.begin(),s.end());
	int d=0;
	for(int i=0;i<s.length()/2;i++)
		if(s[i]!=t[i])
			d++;
	puts((d==1 or d==0 and s.length()%2!=0)?"YES":"NO");
	return 0;
}