#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>

struct segTree{
	int left[4800010];
	int right[4800010];
	int type1[4800010];
	int type2[4800010];
	int control[4800010];
	void setValue(int ind, int val, int l=1, int r=1200000, int v=1)
	{
		if(l==r)
		{
			left[v] = val;
			right[v] = val;
			type1[v] = type2[v] = 0;
			control[v] = 0;
			return;
		}
		
		int h = (l+r)/2;
		if(ind<=h) setValue(ind,val,l,h,2*v);
		else setValue(ind,val,h+1,r,2*v+1);
		left[v] = left[2*v];
		right[v] = right[2*v+1];
		type1[v] = type1[2*v] + type1[2*v+1];
		type2[v] = type2[2*v] + type2[2*v+1];
		control[v] = 0;
		if(right[2*v]>0 && left[2*v+1]==0) type1[v]++;
		if(right[2*v]>1 && left[2*v+1]==1) type2[v]++;
	}
	void mode(int L, int R, int l=1, int r=1200000, int v=1)
	{
		if(L<=l&&r<=R)
		{
			int temp = type1[v];
			type1[v] = type2[v];
			type2[v] = temp;
			if(control[v]==0) left[v]--,right[v]--;
			else left[v]++,right[v]++;
			control[v] = (1-control[v]);
		}
		else if(r<L) return;
		else if(R<l) return;
		else
		{
			int h = (l+r)/2;
			mode(L,R,l,h,2*v);
			mode(L,R,h+1,r,2*v+1);
			left[v] = left[2*v];
			right[v] = right[2*v+1];
			type1[v] = type1[2*v] + type1[2*v+1];
			type2[v] = type2[2*v] + type2[2*v+1];
			if(right[2*v]>0 && left[2*v+1]==0) type1[v]++;
			if(right[2*v]>1 && left[2*v+1]==1) type2[v]++;
		}
	}
	
	int getAns(int L, int R, int l=1,int r=1200000, int v=1)
	{
		if(L<=l&&r<=R) return type1[v];
		else if(r<L) return 0;
		else if(R<l) return 0;
		else
		{
			int h = (l+r)/2;
			int s = getAns(L,R,l,h,2*v) + getAns(L,R,h+1,r,2*v+1);
			if(L<=h && h+1<=R) if(right[2*v]>0 && left[2*v+1]==0) s++;
			return s;
		}
	}
}T;


std::vector<int> index;
std::map<int,int> hash;
std::pair<int,int> P[200010];
int sum[1200010];

int main()
{
	int C;
	scanf("%d",&C);
	while(C--)
	{
		index.clear();
		hash.clear();
		
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++)
		{
			int b,c;
			scanf("%d%d",&b,&c);
			P[i] = std::make_pair(2*b,2*c);
			index.push_back(2*b);
			index.push_back(2*b-1);
			index.push_back(2*b+1);
			index.push_back(2*c);
			index.push_back(2*c-1);
			index.push_back(2*c+1);
		}
		std::sort(index.begin(),index.end());
		index.erase(std::unique(index.begin(),index.end()),index.end());
		for(int i=0;i<index.size();i++) hash[index[i]] = i+1;
		
		for(int i=1;i<=a;i++)
		{
			sum[hash[P[i].first]]++;
			sum[hash[P[i].second]+1]--;
		}
		
		for(int i=1;i<=index.size()+1;i++) sum[i] += sum[i-1];
		for(int i=1;i<=index.size()+1;i++) T.setValue(i,sum[i]);
		int ans = 0;
		for(int i=1;i<=a;i++)
		{
			T.mode(hash[P[i].first],hash[P[i].second]);
			int S = T.getAns(1,index.size()+1);
			ans = ans>S?ans:S;
			T.mode(hash[P[i].first],hash[P[i].second]);
		}
		
		for(int i=0;i<=index.size()+1;i++) sum[i] = 0;
		printf("%d\n",ans);
	}
}