#include <stdio.h>
#include <vector>

std::vector<char> V[100010];
char x[1010];
int main()
{
	for(int i=1;i<=26;i++) V[i].push_back('a'+i-1);
	for(int i=0;i<26;i++)
	{
		for(int j=0;j<26;j++)
		{
			V[26*i+j+27].push_back('a'+i);
			V[26*i+j+27].push_back('a'+j);
		}
	}
	for(int i=0;i<26;i++)
	{
		for(int j=0;j<26;j++)
		{
			for(int k=0;k<26;k++)
			{
				V[26*26*i+26*j+k+26*26+27].push_back('a'+i);
				V[26*26*i+26*j+k+26*26+27].push_back('a'+j);
				V[26*26*i+26*j+k+26*26+27].push_back('a'+k);
			}
		}
	}
	
	int N = 26*26*26+26*26+26+1;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		scanf("%s",x+1);
		for(int i=1;i<=N;i++)
		{
			int control = 0;
			for(int j=1;j+V[i].size()-1<=a;j++)
			{
				for(int k=0;k<V[i].size();k++) if(x[j+k]!=V[i][k]) goto u;
				control = 1;
				u:;
			}
			if(control==0)
			{
				for(int j=0;j<V[i].size();j++) printf("%c",V[i][j]);
				printf("\n");
				break;
			}
		}
	}
}