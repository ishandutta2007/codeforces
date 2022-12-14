#include <stdio.h>
#include <vector>

int ans = 0;
std::vector<int> temp,temp1,temp2;
std::vector< std::vector<int> > V1,V2,W1,W2;
void func(int k)
{
	if(k<0) return;
	int control = 0;
	for(int i=0;i<V1.size();i++)
	{
		int C1 = 0, C2 = 0;
		for(int j=0;j<V1[i].size();j++) if(((V1[i][j]>>k)&1)==0) C1++;
		for(int j=0;j<V2[i].size();j++) if(((V2[i][j]>>k)&1)!=0) C2++;
		if(C1!=C2) control = 1;
	}
	
	if(control==0)
	{
		ans += (1<<k);
		W1.clear();
		W2.clear();
		for(int i=0;i<V1.size();i++)
		{
			temp1.clear(), temp2.clear();
			for(int j=0;j<V1[i].size();j++) if(((V1[i][j]>>k)&1)==0) temp1.push_back(V1[i][j]);
			for(int j=0;j<V2[i].size();j++) if(((V2[i][j]>>k)&1)!=0) temp2.push_back(V2[i][j]);
			if(temp1.size()>0) W1.push_back(temp1), W2.push_back(temp2);
			
			temp1.clear(), temp2.clear();
			for(int j=0;j<V1[i].size();j++) if(((V1[i][j]>>k)&1)!=0) temp1.push_back(V1[i][j]);
			for(int j=0;j<V2[i].size();j++) if(((V2[i][j]>>k)&1)==0) temp2.push_back(V2[i][j]);
			if(temp1.size()>0) W1.push_back(temp1), W2.push_back(temp2);
		}
		V1.clear();
		V2.clear();
		for(int j=0;j<W1.size();j++) V1.push_back(W1[j]);
		for(int j=0;j<W2.size();j++) V2.push_back(W2[j]);
	}
	func(k-1);
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ans = 0;
		V1.clear();
		V2.clear();
		
		int a;
		scanf("%d",&a);
		temp.clear();
		for(int i=1;i<=a;i++)
		{
			int b;
			scanf("%d",&b);
			temp.push_back(b);
		}
		V1.push_back(temp);
		temp.clear();
		for(int i=1;i<=a;i++)
		{
			int b;
			scanf("%d",&b);
			temp.push_back(b);
		}
		V2.push_back(temp);
		
		func(30);
		printf("%d\n",ans);
	}
}