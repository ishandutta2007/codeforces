#include<cstdio>
#include<map>

int s[300000];
int e[300000];
int d[300001];
int k[300001];
int x[300001];

std::pair<int,int> pa;
std::map<std::pair<int,int>,int> cnt;
std::map<std::pair<int,int>,int>::iterator it;

int main()
{
	long long res=0;
	int i,n,p,temp;
	scanf("%d%d",&n,&p);
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&s[i],&e[i]);
		if(s[i]>e[i])
		{
			temp=s[i];
			s[i]=e[i];
			e[i]=temp;
		}
		pa.first=s[i];
		pa.second=e[i];
		if(cnt.find(pa)==cnt.end())cnt[pa]=1;
		else cnt[pa]=cnt[pa]+1;
		d[s[i]]++;
		d[e[i]]++;
	}
	for(i=1;i<=n;i++)k[d[i]]++;
	for(i=0;i<=n;i++)x[i]=k[i];
	for(i=n-1;i>=0;i--)x[i]+=x[i+1];
	for(i=0;i<=p;i++)res+=1LL*k[i]*x[p-i];
	for(;i<=n;i++)res+=1LL*k[i]*n;
	for(i=1;i<=n;i++)if(d[i]+d[i]>=p)res--;
	res/=2;
	for(it=cnt.begin();it!=cnt.end();it++)if(d[it->first.first]+d[it->first.second]>=p&&d[it->first.first]+d[it->first.second]-it->second<p)res--;
	printf("%I64d",res);
}