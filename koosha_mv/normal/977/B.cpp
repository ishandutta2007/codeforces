using namespace std;
#include<iostream>
int a[26][26];
int main()
{
	int n;
	string s;
	cin >> n;
	cin >> s;
	for(int i=0;i<n-1;i++)
		a[int(s[i])-65][int(s[i+1])-65]+=1;
	int i1=0,j1=0,b=0;
	for(int i=0;i<26;i++)
	{
		for(int j=0;j<26;j++)
		{
			//cout<<a[i][j];
			if(a[i][j]>b)
			{
				i1=i;
				j1=j;
				b=a[i][j];
			}
		}
	}
	cout<<char(i1+65)<<char(j1+65);
}