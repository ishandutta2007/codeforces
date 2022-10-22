using namespace std;
#include<iostream>
	int n,a[100001],p[100001];
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>> a[i]>>p[i];
	int g=0,j=0;
	for (int i=0;i<n;i++)
	{
		j=i;
		while(p[i]>=p[j])
		{
			g+=a[i]*p[j];
			i++;
		}
		i--;
	}
	cout<<g;
	
}