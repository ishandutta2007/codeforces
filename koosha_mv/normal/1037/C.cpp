#include<iostream>
using namespace std;
int main()
{
	long long n;
	cin >> n;
	string t1,t2;
	cin >> t1 >> t2;
	long long kh=0;
	for(int i=0;i<n;i++)
	{
		if(t1[i]!=t2[i])
		{
			kh++;
			if(t1[i+1]!=t2[i+1] && t1[i+1]!=t1[i])
				i++;
		}
	}
	cout << kh;
}