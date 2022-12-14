#include <stdio.h>
#include <vector>
#define MOD 1000000007

struct segTree{
	long long int value[400010];
	long long int lazy[400010];
	void addValue(int L, int R, long long int val, int l=1, int r=100000, int v=1)
	{
		if(L<=l&&r<=R)
		{
			value[v] += (r-l+1)*val, value[v]%=MOD;
			lazy[v] += val, lazy[v]%=MOD;
		}
		else if(R<l) return;
		else if(r<L) return;
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=0)
			{
				value[2*v] += (h-l+1)*lazy[v], value[2*v]%=MOD;
				lazy[2*v] += lazy[v], lazy[2*v] %= MOD;
				value[2*v+1] += (r-h)*lazy[v], value[2*v+1]%=MOD;
				lazy[2*v+1] += lazy[v], lazy[2*v+1] %= MOD;
				lazy[v] = 0;
			}
			addValue(L,R,val,l,h,2*v);
			addValue(L,R,val,h+1,r,2*v+1);
			value[v] = value[2*v]+value[2*v+1];
			value[v]%=MOD;
		}
	}
	long long int getSum(int L, int R, int l=1, int r=100000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return 0;
		else if(R<l) return 0;
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=0)
			{
				value[2*v] += (h-l+1)*lazy[v], value[2*v]%=MOD;
				lazy[2*v] += lazy[v], lazy[2*v] %= MOD;
				value[2*v+1] += (r-h)*lazy[v], value[2*v+1]%=MOD;
				lazy[2*v+1] += lazy[v], lazy[2*v+1] %= MOD;
				lazy[v] = 0;
			}
			return (getSum(L,R,l,h,2*v) + getSum(L,R,h+1,r,2*v+1))%MOD;
		}
	}
}T;

long long int power(long long int a, long long int b)
{
	long long int ans = 1;
	long long int k = b;
	long long int s = a;
	while(k)
	{
		if(k%2==1) ans*=s, ans%=MOD;
		s*=s, s%=MOD;
		k/=2;
	}
	return ans;
}
long long int inv(long long int k)
{
	return power(k,MOD-2);
}

std::vector<int> V[100010];
int parent[100010];
int size[100010],depth[100010],heavy[100010];
int index[100010],up[100010];

int getSize(int k, int prev)
{
	if(size[k]) return size[k];
	
	int ans = 1;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		ans += getSize(V[k][i],k);
	}
	return size[k] = ans;
}

void setHLD(int k, int prev, int u, int h, int& C)
{
	int max = -1;
	
	index[k] = C++;
	heavy[k] = -1;
	up[k] = u;
	parent[k] = prev;
	depth[k] = h;
	
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		if(max<getSize(V[k][i],k))
		{
			max = getSize(V[k][i],k);
			heavy[k] = V[k][i];
		}
	}
	for(int i=0;i<V[k].size();i++) if(V[k][i]!=prev && heavy[k]==V[k][i]) setHLD(V[k][i],k,u,h+1,C);
	for(int i=0;i<V[k].size();i++) if(V[k][i]!=prev && heavy[k]!=V[k][i]) setHLD(V[k][i],k,V[k][i],h+1,C);
}

int left[100010],right[100010];
std::vector< std::pair<int,int> > event[100010];

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d%d",&left[i],&right[i]);
	for(int i=1;i<a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		V[b].push_back(c);
		V[c].push_back(b);
	}
	
	int C = 1;
	setHLD(1,0,1,1,C);
	
	long long int P = 1;
	for(int i=1;i<=a;i++)
	{
		P *= (right[i]-left[i]+1);
		P%=MOD;
	}
	
	for(int i=1;i<=a;i++)
	{
		event[left[i]].push_back(std::make_pair(i,1));
		event[right[i]+1].push_back(std::make_pair(i,-1));
	}
	
	long long int S1 = 0, S2 = 0, S3 = 0, S4 = 0;
	long long int ans = 0;
	for(int i=1;i<=100000;i++)
	{
		for(int j=0;j<event[i].size();j++)
		{
			if(event[i][j].second==1)
			{
				int u = event[i][j].first;
				int L = right[u] - left[u] + 1;
				S1 += inv(L);
				S2 += inv(L) * depth[u];
				S3 += (inv(L) * inv(L))%MOD * depth[u];
				
				long long int temp = 0;
				while(u)
				{
					temp += T.getSum(index[up[u]],index[u]);
					temp %= MOD;
					u = parent[up[u]];
				}
				S4 += temp*inv(L);
				S1%=MOD, S2%=MOD, S3%=MOD, S4 %=MOD;
				
				u = event[i][j].first;
				while(u)
				{
					T.addValue(index[up[u]],index[u],inv(L));
					u = parent[up[u]];
				}
			}
			else
			{
				int u = event[i][j].first;
				int L = right[u]-left[u]+1;
				
				while(u)
				{
					T.addValue(index[up[u]],index[u],MOD-inv(L));
					u = parent[up[u]];
				}
				
				u = event[i][j].first;
				S1 += (MOD-inv(L));
				S2 += (MOD-inv(L) * depth[u]%MOD);
				S3 += (MOD-((inv(L) * inv(L))%MOD * depth[u])%MOD);
				
				long long int temp = 0;
				while(u)
				{
					temp += (MOD-T.getSum(index[up[u]],index[u]));
					temp %= MOD;
					u = parent[up[u]];
				}
				
				S4 += temp*inv(L);
				S1%=MOD, S2%=MOD, S3%=MOD, S4 %=MOD;
			}
		}
		long long int S = S2*S1%MOD*P%MOD + S3*(MOD-P)%MOD + 2*(MOD-P)%MOD*S4%MOD;
		S%=MOD;
		ans += S;
		ans %= MOD;
	}
	printf("%lld",ans);
}