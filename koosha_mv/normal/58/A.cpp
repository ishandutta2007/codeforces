#include<iostream>
using namespace std;
int main()
{
	int n=0;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='h' && n==0)
			n++;
		if(s[i]=='e' && n==1)
			n++;
		if(s[i]=='l' && (n==2 || n==3))
			n++;
		if(s[i]=='o' && n==4)
			n++;
	}
	if(n==5)
		cout<<"YES";
	else
		cout<<"NO";
}