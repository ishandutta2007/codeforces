#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>

int b;
int x[300010];
std::vector<int> ans;

std::pair<int,int> func2(int L1, int R1, int L2, int R2, int digit)
{
	if((R1-L1+1)==0) return std::make_pair(-1,-1);
	if((R2-L2+1)==0) return std::make_pair(-1,-1);
	if(digit<0) return std::make_pair(L1,L2);
	
	int p1 = L1-1, p2 = L2-1;
	for(int i=L1;i<=R1;i++) if(((x[i]>>digit)&1)==0) p1 = i;
	for(int i=L2;i<=R2;i++) if(((x[i]>>digit)&1)==0) p2 = i;
	
	if(((b>>digit)&1)==0)
	{
		if((R1-p1)>0 && (p2-L2+1)>0) return std::make_pair(p1+1,p2);
		else if((R2-p2)>0 && (p1-L1+1)>0) return std::make_pair(p2+1,p1);
		else if((R1-p1)>0 && (R2-p2)>0) return func2(p1+1,R1,p2+1,R2,digit-1);
		else return func2(L1,p1,L2,p2,digit-1);
	}
	else
	{
		std::pair<int,int> s1 = func2(p1+1,R1,L2,p2,digit-1);
		if(s1.first!=-1) return s1;
		std::pair<int,int> s2 = func2(L1,p1,p2+1,R2,digit-1);
		if(s2.first!=-1) return s2;
		else return std::make_pair(-1,-1);
	}
}

void func(int L, int R, int digit)
{
	if(L>R) return;
	if(digit<0)
	{
		for(int i=L;i<=R;i++) ans.push_back(i);
		return;
	}
	
	int p = L-1;
	for(int i=L;i<=R;i++) if(((x[i]>>digit)&1)==0) p = i;
	
	if(((b>>digit)&1)==0)
	{
		func(L,p,digit-1);
		func(p+1,R,digit-1);
	}
	else
	{
		std::pair<int,int> t = func2(L,p,p+1,R,digit-1);
		if(t.first!=-1)
		{
			ans.push_back(t.first);
			ans.push_back(t.second);
		}
		else ans.push_back(L);
	}
}

int y[300010],hash[300010];
std::vector< std::pair<int,int> > index;
int main()
{
	int a;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&y[i]);
	for(int i=1;i<=a;i++) index.push_back(std::make_pair(y[i],i));
	std::sort(index.begin(),index.end());
	for(int i=0;i<index.size();i++) x[i+1] = index[i].first;
	for(int i=0;i<index.size();i++) hash[i+1] = index[i].second;
	
	func(1,a,30);
	if(ans.size()<=1) printf("-1");
	else
	{
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();i++) printf("%d ",hash[ans[i]]);
	}
}