#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
#define fr(i,a,b) for(long long i=a,_end_=b;i<=_end_;i++)
#define fd(i,a,b) for(long long i=a,_end_=b;i>=_end_;i--)
using namespace std;
long long read(){
	long long s=0,k=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		k=c=='-'?-1:1;
		c=getchar();
	}		
	while(c>='0'&&c<='9'){
		s=(s<<1)+(s<<3)+(c^48);
		c=getchar();
	}
	return s*k;
}
#define N 100010
long long n,w[N],v[N],s;
#include<queue>
priority_queue<long long>q;
int main()
{
	n=read();
	fr(i,1,n)v[i]=read();
	fr(i,1,n)w[i]=read();
	fr(i,1,n)
	{
		long long ans=0;
		q.push(-v[i]-s);
		while(!q.empty()&&-q.top()-s<=w[i])
		{
			ans+=-q.top()-s;
			q.pop();
		}
		s+=w[i];
		printf("%I64d%c",w[i]*q.size()+ans,i==n?'\n':' ');
	}
	return 0;
}