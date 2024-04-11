#include<iostream>
using namespace std;
int a[27]={0};
string s[101];
int main()
{
	long long n,k,sum=1;
	cin>>n>>k;
	for(long long i=0;i<n;i++)
		cin>>s[i];
	for(long long i=0;i<k;i++)
	{
		long long a[27]={0},s1=0,l;
		for(long long j=0;j<n;j++)
		{
			l=int(s[j][i])-65;
			if(a[l]==0)
			{
				a[l]=1;
				s1++;
			}
		}
		sum*=s1;
		sum=sum%1000000007;
	}
	cout<<sum;
}