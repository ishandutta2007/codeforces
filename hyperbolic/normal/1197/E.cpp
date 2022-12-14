#include <stdio.h>
#include <vector>
#include <algorithm>
#define MAX 1234567890
#define MOD 1000000007

struct segTree{
	std::pair<int,long long int> value[800010];
	void update(int k)
	{
		std::pair<int,long long int> P1 = value[2*k];
		std::pair<int,long long int> P2 = value[2*k+1];
		if(P1.first<P2.first) value[k] = P1;
		else if(P1.first>P2.first) value[k] = P2;
		else value[k] = std::make_pair(P1.first,(P1.second+P2.second)%MOD);
	}
	void set(int ind, std::pair<int,long long int> val, int l=1, int r= 200000, int v=1)
	{
		if(l==r) value[v] = val;
		else
		{
			int h = (l+r)/2;
			if(ind<=h) set(ind,val,l,h,2*v);
			else set(ind,val,h+1,r,2*v+1);
			update(v);
		}
	}
	std::pair<int,long long int> get(int L, int R, int l=1, int r= 200000, int v=1)
	{
		if(L>R) return std::make_pair(MAX,0);
		
		if(L<=l&&r<=R) return value[v];
		else if(R<l) return std::make_pair(MAX,0);
		else if(r<L) return std::make_pair(MAX,0);
		else
		{
			int h =(l+r)/2;
			std::pair<int,long long int> P1 = get(L,R,l,h,2*v);
			std::pair<int,long long int> P2 = get(L,R,h+1,r,2*v+1);
			
			if(P1.first<P2.first) return P1;
			else if(P1.first>P2.first) return P2;
			else return std::make_pair(P1.first,(P1.second+P2.second)%MOD);
		}
	}
}T;

std::pair<int,int> x[200010];
bool cmp(std::pair<int,int> P1, std::pair<int,int> P2)
{
	return P1.first<P2.first;
}

int check[200010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d %d",&x[i].first,&x[i].second);
	std::sort(x+1,x+a+1,cmp);
	for(int i=1;i<=a;i++) T.set(i,std::make_pair(MAX,0));
	
	for(int i=1;i<=a;i++)
	{
		int min = 1, max = i-1;
		int ind = 0;
		while(min<=max)
		{
			int h = (min+max)/2;
			if(x[h].first<=x[i].second)
			{
				ind = h;
				min = h +1;
			}
			else max = h-1;
		}
		check[ind] = 1;
		if(ind==0) T.set(i,std::make_pair(x[i].second-x[i].first,1));
		else
		{
			std::pair<int,long long int> P1 = T.get(1,ind);
			T.set(i,std::make_pair(P1.first+x[i].second-x[i].first,P1.second));
		}
	}
	
	std::pair<int,long long int> ans = std::make_pair(MAX,0);
	for(int i=a;i>=1;i--)
	{
		if(check[i]) break;
		std::pair<int,long long int> P1 = T.get(i,i);
		P1.first += x[i].first;
		if(ans.first>P1.first) ans = P1;
		else if(ans.first==P1.first) ans.second += P1.second, ans.second %= MOD;
	}
	printf("%lld",ans.second);
}