#include<iostream>
using namespace std;
long long a[1000002]={0};
int main()
{
	long long n,ss=0,sa=0,ag=1,ts=0;
	cin>>n;
	string s;
	cin>>s;
	s+='1';
	while(ss<s.size())
	{
		if(s[ss]=='1')
		{
			a[sa]=ts;
			sa++;
			ts=0;
		}
		else
			ts++;
		ss++;
	}
//	for(long long i=0;i<sa;i++)
//		cout<<a[i]<<endl;
	long long s1=0,s2=n,tedad=0;
	if(n==0)
	{
		for(long long i=0;i<sa;i++)
			tedad+=(a[i]*(a[i]+1))/2;
		cout<<tedad;
		return 0;
	}
	while(s2<sa)
	{
		//cout<<s1<<"  "<<s2<<" "<<tedad<<endl;
		tedad+=(a[s1]+1)*(a[s2]+1); 
		s1++;
		s2++;
	}
	cout<<tedad;    
	tedad=0;
}