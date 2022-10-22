#include<iostream>
using namespace std;
int main()
{
	int n,m,k;
	cin >> n >> m >> k;
	int s[n];
	int l=0,r=0;
	for(int i=0;i<n;i++)
		cin >> s[i];
	int t=0;
	int a=m-1;
	while(t==0)
	{
		if(a-l!=0)
			l++;
		if (a+r!=n-1)
			r++;
		if(s[a-l]<=k && s[a-l]!=0)
		{
			cout << l*10;
			return 0;
		}
		if(s[a+r]<=k && s[a+r]!=0)
		{
			cout << r*10;
			return 0;
		}
	}
}