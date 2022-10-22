#include<iostream>
using namespace std;
int a1[100],a2[100],a3[100],k1,k2,k3,n;
int jam1()
{
	int kk=0;
	for(int tt=0;tt<n;tt++)
	{
		kk+=a1[tt];
	}
	return kk;
}
int jam2()
{
	int kk=0;
	for(int tt=0;tt<n;tt++)
	{
		kk+=a2[tt];
	}
	return kk;
}
int jam3()
{
	int kk=0;
	for(int tt=0;tt<n;tt++)
	{
		kk+=a3[tt];
	}
	return kk;
}
int main()
{
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> a1[i] >> a2[i] >> a3[i];
	if(jam1()==0 && jam2()==0 && jam3()==0)
		cout << "YES";
	else
		cout << "NO";
}