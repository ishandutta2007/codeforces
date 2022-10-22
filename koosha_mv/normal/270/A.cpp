#include<iostream>
using namespace std;
string fancy(float n)
{
	if(n==179)
		return "YES";
	for(float i=1;i<182;i++)
	{
		if((i*180)/(i+2)==n)
			return "YES";
		if(((i*180)/(i+2))>n)
			return "NO";
	}
	return "NO";
}
int main()
{
	int n;
	float k;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>k;
		cout<<fancy(k)<<endl;
	}
}