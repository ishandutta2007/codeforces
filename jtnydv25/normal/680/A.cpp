#include <bits/stdc++.h>
using namespace std;
int main()
{
	int A[101];
	memset(A,0,sizeof A);
	int sm = 0;
	for(int i =0;i<5;i++)
	{
		int x;
		cin>>x;
		A[x]++;
		sm+=x;
	}
	int ret = sm;
	for(int i = 1;i<=100;i++)
	{
		if(A[i]>=2)
			ret = min(ret,sm-i*min(3,A[i]));
	}
	cout<<ret;
}