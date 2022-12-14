#include <stdio.h>
#include <vector>
#include <map>
#define MOD 998244353

struct segTree{
	long long int value[4000010];
	void setValue(int ind, int val, int l=1, int r=1000000, int v=1)
	{
		if(l==r) value[v] = val;
		else
		{
			int h = (l+r)/2;
			if(ind<=h) setValue(ind,val,l,h,2*v);
			else setValue(ind,val,h+1,r,2*v+1);
			value[v] = (value[2*v] * value[2*v+1])%MOD;
		}
	}
	long long int getMul(int L, int R, int l=1, int r=1000000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return 1;
		else if(R<l) return 1;
		else
		{
			int h = (l+r)/2;
			long long int s1 = getMul(L,R,l,h,2*v);
			long long int s2 = getMul(L,R,h+1,r,2*v+1);
			return (s1*s2)%MOD;
		}
	}
}T1,T2;

int count1[1000010][3],count2[1000010][3];
int type[3];

void update(int d, int e)
{
	if(count1[d][0]>=1&&count1[d][1]>=1) T1.setValue(d,0);
	else if(count1[d][0]==0&&count1[d][1]==0) T1.setValue(d,2);
	else T1.setValue(d,1);
	
	if(count2[e][0]>=1&&count2[e][1]>=1) T2.setValue(e,0);
	else if(count2[e][0]==0&&count2[e][1]==0) T2.setValue(e,2);
	else T2.setValue(e,1);
}

std::map< std::pair<int,int> , int> M;
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=a;i++) T1.setValue(i,2);
	for(int j=1;j<=b;j++) T2.setValue(j,2);
	
	while(c--)
	{
		int d,e,f;
		scanf("%d%d%d",&d,&e,&f);
		if(M.find(std::make_pair(d,e))!=M.end())
		{
			int val = M[std::make_pair(d,e)];
			count1[d][(e+val)%2]--;
			count2[e][(d+val)%2]--;
			type[(d+e+val)%2]--;
			update(d,e);
			M.erase(std::make_pair(d,e));
		}
		if(f!=-1)
		{
			count1[d][(e+f)%2]++;
			count2[e][(d+f)%2]++;
			update(d,e);
			type[(d+e+f)%2]++;
			M[std::make_pair(d,e)] = f;
		}
		
		long long int ans = T1.getMul(1,a) + T2.getMul(1,b);
		for(int j=0;j<=1;j++) if(type[j]==0) ans += (MOD-1);
		printf("%lld\n",ans%MOD);
	}
}