using namespace std;
#include<iostream>

int main()
{
	int a[13];
	int n;
	cin >> n;
	string s;
	cin>>s;
	for(int i =0;i<12;i++)
		a[i]=i+1;
	int t=0;
	for(int i =0;t<n;i++)
	{
		cout<<s[t];
		t+=a[i];
	}
		
	
}