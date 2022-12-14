#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#define MIN -12345
 
int x[5010];
std::vector<int> index;
std::map<int,int> hash;
short max2[8][5010];
short M2[5010][5010];

int check[5010],next[5010],prev[5010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) index.push_back(x[i]);
	std::sort(index.begin(),index.end());
	index.erase(std::unique(index.begin(),index.end()),index.end());
	for(int i=0;i<index.size();i++) hash[index[i]] = i+1;
	
	for(int i=1;i<=a;i++) check[i] = hash[x[i]];
	for(int i=1;i<=a;i++) next[i] = hash[x[i]+1];
	for(int i=1;i<=a;i++) prev[i] = hash[x[i]-1];
	
	for(int i=0;i<7;i++) for(int j=0;j<=a;j++) max2[i][j] = MIN;
	for(int i=0;i<=a;i++) for(int j=0;j<=a;j++) M2[i][j] = MIN;
	
	int ans = 0;
	for(int j=a;j>=1;j--)
	{
		for(int i=a;i>j;i--)
		{
			short s1 = max2[x[i]%7][j] + 1;
			short s3 = max2[x[j]%7][i] + 1;
			
			int t1 = next[i];
			int t2 = prev[i];
			short s4 = M2[next[i]][j] + 1;
			short s5 = M2[prev[i]][j] + 1;
			short s8 = M2[next[j]][i] + 1;
			short s9 = M2[prev[j]][i] + 1;
			short S = 0;
			S = S>s1?S:s1;
			S = S>s3?S:s3;
			S = S>s4?S:s4;
			S = S>s5?S:s5;
			S = S>s8?S:s8;
			S = S>s9?S:s9;
			ans = ans>S+2?ans:S+2;
			
			
			max2[x[i]%7][j] = max2[x[i]%7][j] > S?max2[x[i]%7][j] : S;
			M2[check[i]][j] = M2[check[i]][j] > S ? M2[check[i]][j] : S;
			
		}
	}
	
	for(int i=a;i>0;i--)
	{
		short s1 = max2[x[i]%7][0] + 1;
		short s3 = MIN;
		for(int j=0;j<7;j++) s3 = s3>max2[j][i]+1?s3:max2[j][i]+1;
		short s4 = M2[prev[i]][0] + 1;
		short s5 = M2[next[i]][0] + 1;
		short S = 0;
		S = S>s1?S:s1;
		S = S>s3?S:s3;
		S = S>s4?S:s4;
		S = S>s5?S:s5;
		ans = ans>S+1?ans:S+1;
		
		max2[x[i]%7][0] = max2[x[i]%7][0] > S?max2[x[i]%7][0] : S;
		M2[check[i]][0] = M2[check[i]][0] > S ? M2[check[i]][0] : S;
		
	}
	
	printf("%d",ans);
}