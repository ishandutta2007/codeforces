#include<iostream>
using namespace std;
int main()
{
	int n,f1=0,s1=0;
	string s;
	cin >> n >> s;
	
	for(int i=0;i<n-1;i++)
	{
		if(s[i]=='S' && s[i+1]=='F')
			f1++;
		if(s[i]=='F' && s[i+1]=='S')
			s1++;
}
	if(f1>s1)
		cout << "YES";
	else
		cout << "NO";
}