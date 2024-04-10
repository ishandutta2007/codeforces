#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > type1,type2;
long long sum1[200200],sum2[200200];
int p1,p2;
int rate1[200200],rate2[200200];
int n,m,k,s;
int check(int d)
{
	for(int i=max(0,k-p2);i<=min(p1,k);i++)
		if(sum1[i]*rate1[d]+sum2[k-i]*rate2[d]<=s)
		{
//			cout<<"day:"<<d<<endl;
//			cout<<"num:"<<i<<" "<<k-i<<endl;
//			cout<<"sum:"<<sum1[i]<<" "<<sum2[k-i]<<endl;
//			cout<<"rate:"<<rate1[d]<<" "<<rate2[d]<<endl;
			return i+1;
		}
	return false;
}
int main()
{
	rate1[0]=rate2[0]=10000000;
	cin>>n>>m>>k>>s;
	for(int i=1;i<=n;i++)
		cin>>rate1[i];
	for(int i=1;i<=n;i++)
		cin>>rate2[i];
	for(int i=1;i<=n;i++)
	{
		rate1[i]=min(rate1[i],rate1[i-1]);
		rate2[i]=min(rate2[i],rate2[i-1]);
	}
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		if(a==1)
			type1.push_back(make_pair(b,i));
		else	type2.push_back(make_pair(b,i));
	}
	sort(type1.begin(),type1.end());
	sort(type2.begin(),type2.end());
	for(int i=0;i<(int)(type1.size());i++)
	{
		p1++;
		sum1[p1]=sum1[p1-1]+type1[i].first;
	}
	for(int i=0;i<(int)(type2.size());i++)
	{
		p2++;
		sum2[p2]=sum2[p2-1]+type2[i].first;
	}
	int lb=1,ub=n+1;
	while(lb<ub)
	{
		int mid=(lb+ub)/2;
		if(check(mid))
			ub=mid;
		else	lb=mid+1;
	}
	if(lb==n+1)
	{
		puts("-1");
		return 0;
	}
	cout<<lb<<endl;
	int pos=check(lb)-1;
	for(int i=1;i<=n;i++)
		if(rate1[i]==rate1[lb])
		{
			for(int j=0;j<pos;j++)
				cout<<type1[j].second+1<<" "<<i<<endl;
			break;
		}
//	puts("");
	pos=k-pos;
	for(int i=1;i<=n;i++)
		if(rate2[i]==rate2[lb])
		{
			for(int j=0;j<pos;j++)
				cout<<type2[j].second+1<<" "<<i<<endl;
			break;
		}
//	puts("-----");
//	cout<<sum2[2]<<endl;
	return 0;
}