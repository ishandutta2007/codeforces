#include<iostream>
#include<string>
int koochik(int c,int d)
{
	if(c<d)
		return c;
	return d;
}
using namespace std;
int main()
{
	int n=0,l=0,r=0,u=0,d=0;
	string s;
	cin >> n;
	cin >> s;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='L')
			l++;
		if(s[i]=='R')
			r++;
		if(s[i]=='D')
			d++;
		if(s[i]=='U')
			u++;
	}
	cout << koochik(l,r)*2+koochik(u,d)*2;
}