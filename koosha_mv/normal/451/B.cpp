#include<iostream>
using namespace std;
int main()
{
	int h=0,n,adadikes,andiskes,gadadikes,adadiket,andisket,badadiket,a2,a3,k1,k2,k3,p,l=0;
	cin>>n;
	int s1=0,s2=0,s3=0;
	for(int i=0;i<n;i++)
	{
		cin>>s1;
		if(s1<s2 && l==1)
		{
			l++;
			break;
		}
		if(s1<s2 && l==0)
		{
			l++;
			andiskes=i-1;
			adadikes=s2;
			gadadikes=s3;
			while(s1<s2 && i<=n)
			{				
				s3=s2;
				s2=s1;
				h=0;
				i++;
				if(i<n)
					cin>>s1;
				if(i==n)
				{
					s1=1000000000;
				}
			}
			if(h==0);
				badadiket=s1;
			adadiket=s2;
			andisket=i-1;
		}
		s3=s2;
		s2=s1;
	}
	//cout<<adadikes<<"  "<<adadiket;
	if(n==2 && l==1)
		cout<<"yes"<<endl<<1<<" "<<2;
	else{
	if(l>1)
		cout<<"no";
	else
	{
		if(l==0)
			cout<<"yes"<<endl<<1<<" "<<1;
	else
	{
	if(adadikes<badadiket && adadiket>gadadikes)
	{
		cout<<"yes"<<endl;
		cout<<andiskes+1<<" "<<andisket+1;
	}
	else
		cout<<"no";
	}
	}
	}
}