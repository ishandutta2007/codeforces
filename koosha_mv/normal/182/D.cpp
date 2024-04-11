#include<iostream>
#include<numeric>
using namespace std;
long long lm(long long x,string s1,string s2)
{
	for(long long i=0;i<x;i++)
	{
		if(s1[i]!=s2[i])
			return 0;
	}
	return 1;
}
long long t(string s)
{
	for(long long i=0;i<s.size();i++)
	{
		if(s.size()%(i+1)==0){
			long long y=0;
			for(long long j=0;j<s.size();j++){
				if(s[j]!=s[j%(i+1)]){
					y=1;
					break;
				}
			}
			if(y==0)
				return i+1;
		}
	}
}
long long gcd(long long x,long long y)
{
	if(x==0)
		return y;
	if(y==0)
		return x;
	return gcd(y,x%y);
}
long long lcm(long long x,long long y)
{
	return(x*y)/gcd(x,y);
}
int main()
{
	string s1,s2;
	s1="  ";
	cin>>s1>>s2;
	//if(s1=="asdkjjaskldjklasjdhasjdasdas" && s2=="asdjahsgdjslkdaygsudhasdkasnjdbayusvduasdklmaklsd")
	long long km=lcm(t(s1),t(s2));
	if(km>s2.size() || km>s1.size())
	{
		cout<<0;
		return 0;
	}
	if(lm(km,s1,s2)==0)
	{
		cout<<0;
		return 0;
	}
	long long sum=0,k1=s1.size(),k2=s2.size();
	for(long long i=km;i<=min(k1,k2);i+=km)
	{
		if(k1%i==0 && k2%i==0)
			sum++;
	}
	cout<<sum;
	sum=0;
}