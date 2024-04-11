#include<iostream>
#include<string>
using namespace std;
int n,n1;
string s1[101],s2;
int srt(string s1[101],string s2,int n)
{
	for(int i=0;i<n;i++)
	{
		if(s1[i]==s2)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	n=0;

	string s3,c1,c2;
	cin >> s2 ;
	for(int j=0;j<s2.size();j++)
	{
		s3=s2[j];
		if(srt(s1,s3,n)==1)
		{

			s1[n]=s2[j];
			n+=1;
		}
	}
	if(n%2==0)
		cout << "CHAT WITH HER!";
	else
		cout << "IGNORE HIM!";
}