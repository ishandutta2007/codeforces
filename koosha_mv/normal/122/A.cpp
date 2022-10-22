#include<iostream>
using namespace std;
int main()
{
	int n,a[16]={4,7,47,74,77,44,444,777,447,477,774,744,474,747},t=0;
	cin >> n;
	for(int i=0;i<14;i++)
	{
		if(n%a[i]==0)
			t=1;
	}
	if(t==1)
		cout << "YES";
	else
	{
		cout<<"NO";
	}
}