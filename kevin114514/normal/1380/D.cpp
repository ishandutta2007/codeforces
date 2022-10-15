#include<bits/stdc++.h>
#define int long long
using namespace std;
int xx[200200],yy[200200];
int Len[200200],p;
bool allDelete[200200];
signed main()
{
	int N,M;
	cin>>N>>M;
	int X,K,Y;
	cin>>X>>K>>Y;
	for(int i=0;i<N;i++)
		cin>>xx[i];
	for(int j=0;j<M;j++)
		cin>>yy[j];
	int last=0,jj=0,mx=0;
	for(int i=0;i<N;i++)
	{
		if(xx[i]==yy[jj])
		{
			Len[p]=i-last;
			jj++;
			if(last&&xx[last-1]>mx)
				allDelete[p]=true;
			if(xx[i]>mx)
				allDelete[p]=true;
			p++;
			last=i+1;
			mx=0;
		}
		else	mx=max(mx,xx[i]);
	}
	if(jj!=M)
	{
		puts("-1");
		return 0;
	}
	Len[p++]=N-last;
	if(xx[last-1]>mx)
		allDelete[p-1]=true;
	int ttl=0;
	for(int i=0;i<p;i++)
		if(Len[i])
		{
			bool HaveAns=false;
			int Cnt=1e18;
			for(int j=1;j*K<=Len[i];j++)
			{
				HaveAns=true;
				Cnt=min(Cnt,X*j+Y*(Len[i]-K*j));
			}
			if(!HaveAns&&!allDelete[i])
			{
				puts("-1");
				return 0;
			}
			if(allDelete[i])
				Cnt=min(Cnt,Len[i]*Y);
			ttl+=Cnt;
		}
	cout<<ttl<<endl;
	return 0;
}