#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	int n=0,k=0,k1=0;
	cin >> n >> s;
	for(int i=0;i<n;i++){
		if(s[i]=='x')
			k++;
		if(s[i]!='x' || i==n-1)
		{
			if(k>2)
				k1+=k-2;
			k=0;
		}
	}
	cout << k1;
	return 0;
}