#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n,t=0;
	cin >> n;
	int s[n*3];
	for(int i=0;i<n*3;i++)
	{
		cin >> s[i];
	}
	for(int i=0;i<n;i++)
	{
		int q=0;
		for(int j=0;j<3;j++)
		{
			if(s[i*3+j]==1)
				q++;
		}
		if(q>1)
		{
			t++;
		}
	}
	cout << t;
}