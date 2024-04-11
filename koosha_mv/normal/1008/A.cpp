using namespace std;
#include<iostream>
int main()
{
	string s;
	cin>>s;
	int t=0;
	for(int i=0;i<s.length()-1;i++)
		if(s[i]!='o' && s[i]!='a' && s[i]!='u' && s[i]!='i' && s[i]!='n' && s[i]!='e')
		{
			if(s[i+1]!='a' && s[i+1]!='o' && s[i+1]!='e' && s[i+1]!='u' && s[i+1]!='i' )
				t=1;
		}
	if(t==1 || (s[s.length()-1]!='a' && s[s.length()-1]!='o' && s[s.length()-1]!='e' && s[s.length()-1]!='i' && s[s.length()-1]!='u' && s[s.length()-1]!='n'))
		cout<<"NO";
	else
		cout<<"YES";
}