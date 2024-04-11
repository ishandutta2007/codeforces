#include<iostream>
using namespace std;
int main()
{
	int q,n;
	string s;
	cin>>q;
	int s1=-1,s2=-1;
	for(int i=0;i<q;i++)
	{
		s1=-1;
		s2=-1;
		cin>>n;
		cin>>s;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='1')
			{
				s1=i;

			}
		}
		for(int i=n-1;i>=0;i--)
		{
			if(s[i]=='1')
			{
				s2=i;
			}
		}
		if(s1==-1)
			cout<<n<<endl;
		else
		{
			s2=(n-1)-s2;
			cout<<(max(s1,s2)+1)*2<<endl;
		}
	}
}