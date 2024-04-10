#include<bits/stdc++.h>

using namespace std;
vector<long long>V;
long long q,l,r,i;

long long K(long long num){return num?upper_bound(V.begin(),V.end(),num)-V.begin()+sqrt(num):0;}

int main()
{
	//freopen("CF955C.in","r",stdin);
	for(i=2;i<=1e6;i++)
	{
		long long ret=i;
		while(ret<=1e18&&log10(ret)+log10(i)<=18)
		{
			ret*=i;
			long long s=sqrt(ret);
			if(ret!=s*s) V.push_back(ret);
		}
	}
	sort(V.begin(),V.end());
	V.erase(unique(V.begin(),V.end()),V.end());
	scanf("%lld",&q);
	while(q--)
	{
		scanf("%lld%lld",&l,&r);
		printf("%lld\n",K(r)-K(l-1));
	}
	return 0;
}