#include<bits/stdc++.h>
using namespace std;
const int M=1000000007;
const int maxn = 1e7+7;
const int maxp = 7e5+7;

bool vis[maxn];
int prime[maxp], mu[maxn], tot, mx;

void getprime() {
    mu[1]=1;
    for(int i=2; i<=mx; ++i) {
        if(!vis[i]) prime[tot++]=i, mu[i]=-1;
        for(int j=0; j<tot&&i*prime[j]<=mx; ++j) {
            vis[i*prime[j]]=1;
            if(i%prime[j]==0) { mu[i*prime[j]]=0; break; }
            else mu[i*prime[j]]=-mu[i];
        }
    }
}
int a,i,j,f[maxn],n;
long long d[1000005],ans;
int main()
{
	scanf("%d",&n);
	d[0]=1;
	for(i=1;i<=n;++i)
	{
		scanf("%d",&a);
		++f[a];
		d[i]=d[i-1]*2%M;
		mx=max(mx,a);
	}
	getprime();
	for(i=2;i*3<=mx;++i)
		if(mu[i])
		{
			int s=0,s1=0;
			int step=2*i;
			for(j=i;j+step<=mx;j+=step)
			{
				s+=f[j];
				s1+=f[j+i];
			}
			s+=s1;
			for(;j<=mx;j+=i)
				s+=f[j];
			if(s)
				ans=(ans-mu[i]*(d[s]-1)*n+mu[i]*(2*d[s-1]-1)*s)%M;
		}
	for(i=mx/3+1;i<=mx;++i)
		if(mu[i])
		{
			int s=0;
			for(j=i;j<=mx;j+=i)
				s+=f[j];
			if(s)
				ans=(ans-mu[i]*(d[s]-1)*n+mu[i]*(2*d[s-1]-1)*s)%M;
		}
	cout<<(ans%M+M)%M;
}