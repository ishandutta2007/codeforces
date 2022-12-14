#include <stdio.h>
#include <vector>

std::vector<int> V[30];
char x[100010];
int count1[100010],count2[100010];
int index[100010],hash[100010];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		for(int j=0;j<26;j++) V[j].clear();
		
		int a;
		scanf("%d",&a);
		scanf("%s",x+1);
		
		for(int i=1;i<=a;i++) V[x[i]-'a'].push_back(i);
		
		int ans = 12345678;
		for(int j=0;j<26;j++)
		{
			for(int i=1;i<=a;i++) count1[i] = count2[i] = hash[i] = 0;
			
			int C = 1;
			for(int i=1;i<=a;i++)
			{
				if(x[i]!='a'+j)
				{
					index[i] = C++;
					hash[index[i]] = i;
				}
				else index[i] = 0;
			}
			
			int s = (a-V[j].size());
			if(s==0)
			{
				printf("0\n");
				goto u;
			}
			
			for(int i=s;i>=1;i--) if(x[hash[i]] != x[hash[s+1-i]]) goto v;
			
			if(s%2==1)
			{
				int p = 0,last;
				for(int i=1;i<=a;i++) if(index[i]==(s+1)/2) p = i;
				
				last = p;
				for(int i=p;i>=1;i--)
				{
					if(x[i]=='a'+j) count1[index[p] - index[last]+1]++;
					else last = i;
				}
				
				last = p;
				for(int i=p;i<=a;i++)
				{
					if(x[i]=='a'+j) count2[index[last] - index[p]+1]++;
					else last = i;
				}
				
				int t = 0;
				for(int i=1;i<=a;i++) t += (count1[i]<count2[i]?count1[i]:count2[i]);
				ans = ans<(V[j].size()-2*t)?ans:(V[j].size()-2*t);
			}
			else
			{
				int p1 = 0, p2 = 0, last;
				for(int i=1;i<=a;i++) if(index[i]==s/2) p1 = i;
				for(int i=1;i<=a;i++) if(index[i]==s/2 + 1) p2 = i;
				
				last = p1;
				for(int i=p1;i>=1;i--)
				{
					if(x[i]=='a'+j) count1[index[p1] - index[last]+1]++;
					else last = i;
				}
				
				last = p2;
				for(int i=p2;i<=a;i++)
				{
					if(x[i]=='a'+j) count2[index[last] - index[p2]+1]++;
					else last = i;
				}
				
				int t = 0;
				for(int i=1;i<=a;i++) t += (count1[i]<count2[i]?count1[i]:count2[i]);
				
				//printf("%d : %d %d %d %d!!\n",j,t,p1,p2,(V[j].size()-2*t - (p2-p1-1)));
				ans = ans<(V[j].size()-2*t - (p2-p1-1))?ans:(V[j].size()-2*t - (p2-p1-1) );
			}
			
			v:;
		}
		
		if(ans==12345678) printf("-1\n");
		else printf("%d\n",ans);
		u:;
	}
}