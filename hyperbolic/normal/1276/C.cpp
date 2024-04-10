#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>

std::vector<long long int> index;
std::map<long long int,long long int> hash;

long long int x[400010],size[400010],count[400010];
std::vector<long long int> check[400010];
std::vector<long long int> temp;
std::vector<long long int> V[400010];

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	for(int i=1;i<=a;i++) index.push_back(x[i]);
	std::sort(index.begin(),index.end());
	index.erase(std::unique(index.begin(),index.end()),index.end());
	for(int i=0;i<index.size();i++) hash[index[i]] = i+1;
	
	//num : 1 ~ index.size()
	for(int i=1;i<=a;i++) count[hash[x[i]]]++;
	for(int i=1;i<=index.size();i++) V[count[i]].push_back(i);
	
	for(int i=1;i<=a;i++) size[i] = V[i].size();
	for(int i=a;i>=1;i--) size[i] += size[i+1];
	
	long long int sum = 0;
	long long int ans = 0;
	long long int ind = -1;
	for(long long int i=1;i<=a;i++)
	{
		long long int S = sum+ (long long int)size[i]*i;
		if(S>=(long long int)i*i)
		{
			long long int T = (S/i)*i;
			if(ans<T)
			{
				ans = T;
				ind = i;
			}
		}
		
		for(int j=0;j<V[i].size();j++) sum += i;
	}
	
	for(int i=ind;i<=a;i++) for(int j=0;j<V[i].size();j++) for(int k=1;k<=ind;k++) temp.push_back(V[i][j]);
	for(int i=1;i<ind;i++) for(int j=0;j<V[i].size();j++) for(int k=1;k<=i;k++) temp.push_back(V[i][j]);
	
	long long int s = 0, t = 0;
	long long int L = ind, R = ans/ind;
	for(int i=0;i<L;i++) for(int j=0;j<R;j++) check[i].push_back(-1);
	for(int i=0;i<temp.size();i++)
	{
		check[s][t] = temp[i];
		s++,t++;
		//printf("%d %d!!\n",s,t);
		if(s==L)
		{
			s = 0;
			t = (t+R-L+1)%R;
		}
		if(t==R) t = 0;
		if(s==0&&t==0) break;
	}
	
	printf("%lld\n",ans);
	printf("%d %d\n",L,R);
	for(int i=0;i<L;i++)
	{
		for(int j=0;j<R;j++) printf("%d ",index[check[i][j]-1]);
		printf("\n");
	}
}