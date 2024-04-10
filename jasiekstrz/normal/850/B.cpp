#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int M=1e6+5;
int t[2*M+10];
bool com[M+10];
long long pref[2*M+10];
long long cnt[2*M+10];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,x,y,xd,a,i,j;
	cin>>n>>x>>y;
	xd=x/y;
	for(i=1;i<=n;i++)
	{
		cin>>a;
		t[a]++;
	}
	for(i=2;i<=M;i++)
	{
		if(!com[i] && i<=1e4)
		{
			for(j=i*i;j<=M;j+=i)
				com[j]=true;
		}
	}
	for(i=1;i<=2*M;i++)
	{
		cnt[i]=cnt[i-1]+t[i];
		pref[i]=pref[i-1]+(long long)i*t[i];
	}
	long long ans=(long long)x*n;
	for(int p=2;p<=M;p++)
	{
		if(com[p])
			continue;
		long long w=0;
		int g=max(p-xd-1,0);
		long long w1,w2;
		for(i=0;i<=M;i+=p,g+=p)
		{
			w1=(long long)(i+p)*(cnt[i+p]-cnt[g])-(pref[i+p]-pref[g]);
			w2=(cnt[g]-cnt[i]);
			if(w1>(ans/y)+10)
				goto brk;
			w+=w1*y;
			w+=w2*x;
			if(w>ans)
				goto brk;
		}
		ans=min(ans,w);
brk:;
	}
	cout<<ans<<"\n";
	return 0;
}