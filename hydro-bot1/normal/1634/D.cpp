#include<bits/stdc++.h>
using namespace std;
int arr[233];
int query(int x,int y,int z)
{
//	return max({arr[x],arr[y],arr[z]})-min({arr[x],arr[y],arr[z]});
	cout<<"? "<<x<<' '<<y<<' '<<z<<endl;
	int res;
	cin>>res;
	return res;
}
mt19937 rng(58);
int main()
{
	ios_base::sync_with_stdio(false);
	int T,n;
	cin>>T;
	while(T--)
	{
		cin>>n;
/*
		for(int i=1;i<=n;i++)
		{
			arr[i]=rng()%3+1;
		}
		int pos=rng()%n+1;
		arr[pos]=0;
//*/
		int a=1,b=2,p=3,maxx=0,maxc=0;
		for(int i=3;i<=n;i++)
		{
			int t=query(a,b,i);
			if(t>maxx)
			{
				maxx=t,p=i;
				maxc=1;
			}
			else if(t==maxx)
			{
				maxc++;
			}
		}
		b=p;
		p=2;
		int maxx2=0,maxc2=0;
		for(int i=2;i<=n;i++)
		{
			if(i==b)continue;
			int t=query(a,b,i);
			if(t>maxx2)
			{
				maxx2=t,p=i;
				maxc2=1;
			}
			else if(t==maxx2)maxc2++;
		}
		if(maxc2==n-2 and maxx2>=maxx)
		{
			cout<<"! "<<1<<' '<<b<<endl;
/*
			if(pos!=1 and pos!=b)
			{
				for(int i=1;i<=n;i++)cerr<<arr[i]<<' ';
				cerr<<endl;
			}
//*/
		}
		else if(maxc==n-2 and maxx>=maxx2)
		{
			cout<<"! "<<1<<' '<<2<<endl;
/*
			if(pos!=1 and pos!=2)
			{
				for(int i=1;i<=n;i++)cerr<<arr[i]<<' ';
				cerr<<endl;
			}
//*/
		}
		else
		{
			cout<<"! "<<b<<' '<<p<<endl;
/*
			if(pos!=b and pos!=p)
			{
				for(int i=1;i<=n;i++)cerr<<arr[i]<<' ';
				cerr<<endl;
			}
//*/
		}
	}
	
	return 0;
}