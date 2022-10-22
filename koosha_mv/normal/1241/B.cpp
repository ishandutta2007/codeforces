#include<iostream>
using namespace std;
int a1[30]={0},a2[30]={0};
string t(string s1,string s2)
{
	for(int i=0;i<30;i++)
	{
		a1[i]=0;
		a2[i]=0;
	}
	if(s1==s2)
		return "YES";
	if(s1.length()!=s2.length())
		return "NO";
	for(int i=0;i<s1.length();i++)
	{
		a1[(int(s1[i]))-97]=1;
		a2[(int(s2[i]))-97]=1;
		//cout<<"   "<<(int(s1[i]))-97<<"  "<<(int(s2[i]))-97;
	}
	for(int i=0;i<30;i++)
	{
		if(a1[i]==1 && a1[i]==a2[i])
		{
			//cout<<a1[i]<<" "<<a2[i]<<endl;
			return "YES";
		}
	}
	return "NO";
}
int main()
{
	int q;
	//cout<<int('z');
	string s1,s2;
	cin>>q;
	for(int i=0;i<q;i++)
	{
		cin>> s1>>s2;
		cout<<t(s1,s2)<<endl;
	}
}