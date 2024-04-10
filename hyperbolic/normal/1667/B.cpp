#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#define MIN -12345678

struct segTree{
	int value[2000010];
	void setValue(int ind, int val, int l=1, int r=500001, int v=1)
	{
		if(l==r) value[v] = val;
		else
		{
			int h = (l+r)/2;
			if(ind<=h) setValue(ind,val,l,h,2*v);
			else setValue(ind,val,h+1,r,2*v+1);
			value[v] = value[2*v]>value[2*v+1]?value[2*v]:value[2*v+1];
		}
	}
	int getMax(int L, int R, int l=1, int r=500001, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return MIN;
		else if(R<l) return MIN;
		else
		{
			int h = (l+r)/2;
			int s1 = getMax(L,R,l,h,2*v);
			int s2 = getMax(L,R,h+1,r,2*v+1);
			return s1>s2?s1:s2;
		}
	}
}T;

int DP[500010];
int x[500010];
long long int sum[500010];
std::map<long long int,int> last,hash;
std::vector<long long int> index;
int main()
{
	int Case;
	scanf("%d",&Case);
	for(int i=1;i<=500001;i++) T.setValue(i,MIN);
	
	while(Case--)
	{
		index.clear();
		hash.clear();
		last.clear();
		
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) sum[i] = sum[i-1] + x[i];
		for(int i=0;i<=a;i++) index.push_back(sum[i]);
		std::sort(index.begin(),index.end());
		for(int i=0;i<index.size();i++) hash[index[i]] = i+1;
		
		DP[a+1] = 0;
		for(int i=a;i>=1;i--)
		{
			int s1 = DP[i+1], s2 = MIN, s3 = MIN;
			if(x[i]<0) s1--;
			if(x[i]>0) s1++;
			
			int k = T.getMax(hash[sum[i-1]]+1,a+1);
			if(k!=MIN) s2 = k - i + 1;
			if(last.find(sum[i-1])!=last.end()) s3 = last[sum[i-1]];
			int max = s1>s2?s1:s2;
			max = max>s3?max:s3;
			DP[i] = max;
			
			int t = T.getMax(hash[sum[i]],hash[sum[i]]);
			T.setValue(hash[sum[i]],(t>DP[i+1]+i?t:DP[i+1]+i));
			if(last.find(sum[i])==last.end()) last[sum[i]] = DP[i+1];
			else
			{
				int val = last[sum[i]];
				last[sum[i]] = (DP[i+1]>val?DP[i+1]:val);
			}
		}
		printf("%d\n",DP[1]);
		
		for(int i=1;i<=a+1;i++) T.setValue(i,MIN);
	}
}