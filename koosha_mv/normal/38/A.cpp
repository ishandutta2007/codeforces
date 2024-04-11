#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int s[n-1];
	for(int i=0;i<n-1;i++)
		cin >> s[i];
	int a,b,k=0;
	cin >> a >> b;
	for(int i=a-1;i<b-1;i++)
	{
		k+=s[i];
	}
	cout<<k;
}