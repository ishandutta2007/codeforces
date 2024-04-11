#include<iostream>
using namespace std;
int a[100001];
int main()
{
	long long n,d,t=0,s1,s2;
	cin>>n>>d;
	for(long long i=0;i<n;i++)
	{
		cin>>a[i];
	}
	s1=0;
	s2=2;
	for(long long i=0;i<n*2;i++)
	{
		if(s2>=n)
			break;
		if(s1+1==s2)
			s2++;
		else
		{
			if(a[s2]-a[s1]<=d)
			{
				//cout<<s1<<"  "<<s2<<endl;
				t+=(((s2-s1)-1)*((s2-s1)))/2;
				s2++;
			}
			else
				s1++;
		}
	}
	cout<<t;
}