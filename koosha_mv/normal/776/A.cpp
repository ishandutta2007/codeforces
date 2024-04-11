#include<iostream>
using namespace std;
int main()
{
	string a,b,c,d;int n;
	cin>>a>>b>>n;
	cout<<a<<' '<<b<<endl;
	while(n--)
	{
		cin>>c>>d;
		if(a==c)a=d;else b=d;
		cout<<a<<' '<<b<<endl;
	}
}