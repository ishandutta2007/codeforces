#include<iostream>
using namespace std;
int a[8]={0};
int main()
{
	string s;
	cin >> s;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='B')
			a[0]++;
		if(s[i]=='u')
			a[1]++;
		if(s[i]=='l')
			a[2]++;
		if(s[i]=='b')
			a[3]++;
		if(s[i]=='a')
			a[4]++;
		if(s[i]=='s')
			a[5]++;
		if(s[i]=='u')
			a[6]++;
		if(s[i]=='r')
			a[7]++;
	}
	a[4]=a[4]/2;
	a[6]=a[6]/2;
	a[1]=a[1]/2;
	//cout<<a[6]<<endl;
	int k=a[0];
	for(int i=1;i<8;i++)
	{
		//cout<<a[i]<<endl;
		k=min(k,a[i]);
	}
	cout << k;
}