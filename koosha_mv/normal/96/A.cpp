#include<iostream>
using namespace std;
int main()
{
	string s;
	int a1,a2,a3;
	cin >> s;
	a1=s[0]*(-1)+1;
	a2=0;
	a3=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!=a1)
		{
			a1=s[i];
			a2=1;	
		}
		else
		{
			a2++;
		}
		if(a2>=7)
			a3=1;
	}
	if(a3==1)
		cout << "YES";
	else
		cout << "NO";
	
	
}