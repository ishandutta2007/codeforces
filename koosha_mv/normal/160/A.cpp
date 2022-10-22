#include<iostream>
using namespace std;
int a[100],n,n1,n2;
void bubble()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-1;j++)
		{
			if(a[j]<a[j+1])
			{
				swap(a[j],a[j+1]);
			}
		}	
	}
}
int jam()
{
	int kk=0;
	for(int tt=0;tt<n;tt++)
	{
		kk+=a[tt];
	}
	return kk;
}
int main()
{
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> a[i];
	bubble();
	n1=0;
	n2=0;
	for(int i=0;i<n;i++)
	{
		if(jam()>=n1)
		{
			n1+=a[i];
			n2+=1;
			a[i]=0;
		}
	}	
	cout << n2;
}