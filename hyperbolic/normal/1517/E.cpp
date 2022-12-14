#include <stdio.h>
#define MOD 998244353
#define MAX (long long int)1e16

struct segTree{
	long long int value[800010];
	void setValue(int ind, long long int val, int l=1, int r=200000, int v=1)
	{
		if(l==r) value[v] = val;
		else
		{
			int h = (l+r)/2;
			if(ind<=h) setValue(ind,val,l,h,2*v);
			else setValue(ind,val,h+1,r,2*v+1);
			value[v] = value[2*v]<value[2*v+1]?value[2*v]:value[2*v+1];
		}
	}
	
	int binary(int L, int R, long long int limit, int l=1, int r=200000, int v=1)
	{
		if(L>R) return -1;
		if(L<=l&&r<=R)
		{
			if(value[v]>limit) return -1;
			else if(l==r) return l;
			else
			{
				int h = (l+r)/2;
				int p = binary(L,R,limit,h+1,r,2*v+1);
				if(p!=-1) return p;
				else return binary(L,R,limit,l,h,2*v); 
			}
		}
		else if(r<L) return -1;
		else if(R<l) return -1;
		else
		{
			int h = (l+r)/2;
			int p = binary(L,R,limit,h+1,r,2*v+1);
			if(p!=-1) return p;
			else return binary(L,R,limit,l,h,2*v);
		}
	}
}T[3];

long long int sum[200010];
long long int x[200010];

int main()
{
	int Case;
	scanf("%d",&Case);
	while(Case--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
		sum[1] = x[1];
		sum[2] = x[2];
		for(int i=3;i<=a;i++) sum[i] = x[i] + sum[i-2];
		
		for(int i=1;i<=a;i++) T[0].setValue(i,MAX),T[1].setValue(i,MAX);
		for(int i=1;i<=a;i++) T[1-i%2].setValue(i,sum[i]);
		
		
		long long int S = 0;
		for(int i=1;i<=a;i++) S += x[i];
		long long int ans = 1;
		
		// PC PC
		if(a>=6)
		{
			long long int S2 = x[2] + x[3] + x[a];
			for(int i=4;i<=a-2;i++)
			{
				if(2*S2>=S) break;
				int min = i+1, max = a-3;
				int p = T[i%2].binary(min,max,(S-2*S2+2*sum[i-1]-1)/2);
				if(p==-1) ans++;
				else ans += (p-i+3)/2;
				S2 += x[i];
			}
		}
		//printf("%lld??\n",ans);
		// PC -
		if(a>=2)
		{
			long long int S2 = x[2];
			for(int i=3;i<=a+1;i++)
			{
				if(2*S2>=S) break;
				int min = i+1, max = a;
				int p = T[i%2].binary(min,max,(S-2*S2+2*sum[i-1]-1)/2);
				if(p==-1) ans++;
				else ans += (p-i+3)/2;
				S2 += x[i];
			}
		}
		//printf("%lld??\n",ans);
		// - PC
		if(a>=2)
		{
			long long int S2 = x[a];
			for(int i=1;i<=a-1;i++)
			{
				if(2*S2>=S) break;
				int min = i+1, max = a-2;
				int p = T[i%2].binary(min,max,(S-2*S2+2*sum[i-1]-1)/2);
				if(p==-1) ans++;
				else ans += (p-i+3)/2;
				S2 += x[i];
			}
		}
		//printf("%lld??\n",ans);
		// - -
		if(a>=2)
		{
			long long int S2 = x[1];
			for(int i=2;i<=a;i++)
			{
				if(2*S2>=S) break;
				int min = i+1, max = a-1;
				int p = T[i%2].binary(min,max,(S-2*S2+2*sum[i-1]-1)/2);
				if(p==-1) ans++;
				else ans += (p-i+3)/2;
				S2 += x[i];
			}
		}
		if(a%2==0)
		{
			long long int S2 = 0;
			for(int i=2;i<=a;i+=2) S2 += x[i];
			if(2*S2<S) ans--;
		}
		//printf("%lld??\n",ans);
		// P / C
		
		if(a>=4)
		{
			long long int S2 = x[a];
			for(int i=a-1;i>=3;i--)
			{
				S2 += x[i];
				if(2*S2<S) ans++;
				else break;
			}
		}
		printf("%lld\n",ans%MOD);
	}
}