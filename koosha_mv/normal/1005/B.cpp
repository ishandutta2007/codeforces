#include<iostream>
using namespace std;
int main()
{
	string s,t;
	cin >>t>>s;
	int r=0,i=1;
	while(r==0)
	{
		if(i>s.size() || i> t.size())
			break;
		if(s[s.size()-i]!=t[t.size()-i])
			break; 
		i++;
	}
	i-=1;
	cout << (s.size()-i)+(t.size()-i);
	
}