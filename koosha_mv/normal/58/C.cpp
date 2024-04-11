#include<iostream>
#include<algorithm>
using namespace std;
long long a[100000]={0};
int main()
{
	long long n;
	cin>>n;
	for(long long i=0;i<n;i++)
		cin>>a[i];
	long long aval=0,s1=0,fa=0,t=0,l=0,kh=0;
	while(l!=-1){
		s1=aval;
		fa=a[s1]-min(s1,(n-1)-s1);
		t=0;
		l=-1;
		while(s1<n && fa>0)
		{
			if(a[s1]-min(s1,(n-1)-s1)==fa)
			{
				t++;
				a[s1]=0;
			}
			else
			{
				if(l==-1)
					l=s1;	
			}	
			s1++;
		}
		aval=l;
		kh=max(kh,t);
	}
	cout<<n-kh;
}