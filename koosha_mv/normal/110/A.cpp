#include<iostream>
using namespace std;
int tavan(int q,int w)
{
	int e=1;
	for(int i=0;i<w;i++)
		e=e*q;
	return e;
}
string lucky(int k)
{
	int p=0,o;
	for(int i=1;i<5;i++)
	{
		if(tavan(10,i)>k)
		{
			o=i;
			break;
		}
	}
	for(int i=1;i<o+1;i++)
	{
		if((k%tavan(10,i))/tavan(10,i-1) != 4 && (k%tavan(10,i))/tavan(10,i-1)!=7)
			p=1;
	}
	if(p==1)
		return"NO";
	return"YES";
}
int main()
{
	string n;
	cin >> n;
	int t=0;
	for(int i=0;i<n.size();i++)
	{
		if(n[i]=='4' || n[i]=='7')
			t++;
	}
	string k;
	cout << lucky(t);
}