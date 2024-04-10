#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	int i,dl,a,b,c;
	char ost;
	cin>>s;
	ost='a';
	dl=s.size();
	a=0;
	b=0;
	c=0;
	for(i=0;i<dl;i++)
	{
		if(s[i]!=ost)
		{
			if((ost=='a')&&(s[i]=='b'))
				ost='b';
			else if((ost=='b')&&(s[i]=='c'))
				ost='c';
			else
			{
				cout<<"NO";
				return 0;
			}
		}
		if(ost=='a')
			a++;
		else if(ost=='b')
			b++;
		else
			c++;
	}
	if((a!=0)&&(b!=0)&&((c==b)||(c==a)))
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}