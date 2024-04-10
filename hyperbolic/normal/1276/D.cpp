#include <stdio.h>
#include <vector>
#define MOD 998244353

std::vector<long long> V[200010];
long long check[200010][10];
long long func(long long k, long long prev, long long type)
{
	if(check[k][type]!=-1) return check[k][type];
	long long ans;
	if(type==1)
	{
		ans = 1;
		long long control = 0;
		for(long long i=0;i<V[k].size();i++)
		{
			if(V[k][i]==prev) control = 1;
			else if(control==1)
			{
				long long s1 = func(V[k][i],k,5);
				long long s2 = func(V[k][i],k,6);
				long long s = (s1+s2)%MOD;
				ans *= s, ans %= MOD;
			}
			else
			{
				long long s1 = func(V[k][i],k,2);
				long long s2 = func(V[k][i],k,1);
				long long s = (s1+s2)%MOD;
				ans *= s, ans %= MOD;
			}
		}
	}
	if(type==2)
	{
		std::vector<long long> check2;
		for(long long j=0;j<=V[k].size();j++) check2.push_back(1);
		
		ans = 0;
		long long S = 1;
		for(long long i=0;i<V[k].size();i++)
		{
			if(V[k][i]==prev) check2[i] = 1;
			else
			{
				long long s1 = func(V[k][i],k,5);
				long long s2 = func(V[k][i],k,6);
				check2[i] = (s1+s2)%MOD;
			}
		}
		check2[V[k].size()] = 1;
		for(long long i=V[k].size()-1;i>=0;i--) check2[i] *= check2[i+1], check2[i] %= MOD;
		
		for(long long i=0;i<V[k].size();i++)
		{
			if(V[k][i]==prev) break;
			else
			{
				// not
				long long s1 = func(V[k][i],k,1);
				long long s2 = func(V[k][i],k,2);
				long long s = (s1+s2)%MOD;
				//
				long long s3 = func(V[k][i],k,3);
				long long s4 = func(V[k][i],k,4);
				long long t = (s3+s4)%MOD;
				t *= S, t %= MOD;
				t *= check2[i+1], t %= MOD;
				ans += t, ans %= MOD;
				S *= s, S %= MOD;
			}
		}
	}
	if(type==3)
	{
		std::vector<long long> check2;
		for(long long j=0;j<=V[k].size();j++) check2.push_back(1);
		
		ans = 0;
		long long S = 1;
		for(long long i=0;i<V[k].size();i++)
		{
			if(V[k][i]==prev) check2[i] = 1;
			else
			{
				long long s1 = func(V[k][i],k,5);
				long long s2 = func(V[k][i],k,6);
				check2[i] = (s1+s2)%MOD;
			}
		}
		check2[V[k].size()] = 1;
		for(long long i=V[k].size()-1;i>=0;i--) check2[i] *= check2[i+1], check2[i] %= MOD;
		
		long long ind = -1;
		for(long long i=0;i<V[k].size();i++)
		{
			if(V[k][i]==prev)
			{
				ind = i+1;
				break;
			}
			else
			{
				long long s1 = func(V[k][i],k,1);
				long long s2 = func(V[k][i],k,2);
				long long s = (s1+s2)%MOD;
				S *= s, S %= MOD;
			}
		}
		for(long long i=ind;i<V[k].size();i++)
		{
			// not
			long long s1 = func(V[k][i],k,1);
			long long s2 = func(V[k][i],k,2);
			long long s = (s1+s2)%MOD;
			//
			long long s3 = func(V[k][i],k,3);
			long long s4 = func(V[k][i],k,4);
			long long t = (s3+s4)%MOD;
			t *= S, t %= MOD;
			t *= check2[i+1], t %= MOD;
			ans += t, ans %= MOD;
			S *= s, S %= MOD;
		}
	}
	if(type==4)
	{
		ans = 1;
		for(long long i=0;i<V[k].size();i++)
		{
			if(V[k][i]==prev) continue;
			long long s1 = func(V[k][i],k,1);
			long long s2 = func(V[k][i],k,2);
			long long s = (s1+s2)%MOD;
			ans *= s, ans %= MOD;
		}
	}
	if(type==5)
	{
		std::vector<long long> check2;
		for(long long j=0;j<=V[k].size();j++) check2.push_back(1);
		
		ans = 0;
		long long S = 1;
		for(long long i=0;i<V[k].size();i++)
		{
			if(V[k][i]==prev) check2[i] = 1;
			else
			{
				long long s1 = func(V[k][i],k,5);
				long long s2 = func(V[k][i],k,6);
				check2[i] = (s1+s2)%MOD;
			}
		}
		check2[V[k].size()] = 1;
		for(long long i=V[k].size()-1;i>=0;i--) check2[i] *= check2[i+1], check2[i] %= MOD;
		
		for(long long i=0;i<V[k].size();i++)
		{
			if(V[k][i]==prev) continue;
			else
			{
				// not
				long long s1 = func(V[k][i],k,1);
				long long s2 = func(V[k][i],k,2);
				long long s = (s1+s2)%MOD;
				//
				long long s3 = func(V[k][i],k,3);
				long long s4 = func(V[k][i],k,4);
				long long t = (s3+s4)%MOD;
				t *= S, t %= MOD;
				t *= check2[i+1], t %= MOD;
				ans += t, ans %= MOD;
				S *= s, S %= MOD;
			}
		}
	}
	if(type==6)
	{
		ans = 1;
		for(long long i=0;i<V[k].size();i++)
		{
			if(V[k][i]==prev) continue;
			long long s1 = func(V[k][i],k,1);
			long long s2 = func(V[k][i],k,2);
			long long s = (s1+s2)%MOD;
			ans *= s, ans %= MOD;
		}
	}
	
	return check[k][type] = ans;
}

int main()
{
	long long a;
	scanf("%lld",&a);
	for(long long i=1;i<a;i++)
	{
		long long b,c;
		scanf("%lld%lld",&b,&c);
		V[b].push_back(c);
		V[c].push_back(b);
	}
	for(long long i=1;i<=a;i++) for(long long j=1;j<=6;j++) check[i][j] = -1;
	
	long long s1 = func(1,0,5);
	long long s2 = func(1,0,6);
	printf("%lld",(s1+s2)%MOD);
}