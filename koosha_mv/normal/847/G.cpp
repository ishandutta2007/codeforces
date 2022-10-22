#include<iostream>
#include<string>
using namespace std;
int bozorg(int u,int y)
{
	if(u>y)
		return u;
	return y;
}
int main()
{
	int n,k=0;
	cin >> n;
	string s[n];
	for(int i=0;i<n;i++)
		cin >> s[i];
	for(int i=0;i<7;i++)
	{
		int t=0;
		for(int j=0;j<n;j++)
		{
			if(s[j][i]=='1')
				t++;
		}
		k=bozorg(t,k);
	}
	cout << k;
}