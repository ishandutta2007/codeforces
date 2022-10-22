#include<iostream>
using namespace std;
int a[2001],b[2001],sb=0,sa=0;
void bubblea(int n)
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
void bubbleb(int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-1;j++)
		{
			if(b[j]<b[j+1])
			{
				swap(b[j],b[j+1]);
			}
		}	
	}
}
int main()
{
	int n,k;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>k;
		if(k%2==0)
		{
			a[sa]=k;
			sa++;
		}
		else
		{
			b[sb]=k;
			sb++;
		}
	}
	if(sb-sa>-2 && sb-sa<2)
		cout<<0;
	else
	{
		int p=0;
		if(sb>sa)
		{
			bubbleb(sb);
			for(int i=sa+1;i<sb;i++)
			{
				p+=b[i];
			}
		}
		else
		{
			bubblea(sa);
			for(int i=sb+1;i<sa;i++)
			{
				p+=a[i];
			}
		}
		cout<<p;
	}
}