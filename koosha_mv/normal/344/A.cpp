#include<iostream>
using namespace std;
int main()
{
	int n,n1=1;
	string s1,s2;
	cin >> n;
	cin >> s1;
	for(int i=0;i<n-1;i++)
	{
		s2=s1;
		cin >> s1;
		if(s1!=s2)
			n1++;
	}
	cout << n1;
}