#include<iostream>
using namespace std;
int main()
{
	int n;
	string s;
	cin >> n;
	cin >> s;
	int k=0;
	for(int i=1;i<n;i++)
	{
		if(s[i]==s[i-1])
		{
			k++;
			s[i]=s[i-1];
		}
	}
	cout << k;
}