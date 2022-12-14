#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <map>

struct str{
	long long int count;
	long long int length;
	std::vector<char> up;
	std::vector<char> down;
};
std::map<int,str> M;

char x[110],y[110],z[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		M.clear();
		int a;
		scanf("%d",&a);
		long long int last = 0;
		for(int i=1;i<=a;i++)
		{
			scanf("%s%s",x+1,y+1);
			int b = strlen(x+1);
			int s1 = 0;
			for(int j=1;j<=b;j++) s1 *= 26, s1 += x[j]-'a';
			
			if(y[1]==':')
			{
				scanf("%s",z+1);
				int c = strlen(z+1);
				long long int count = 0;
				for(int j=1;j+3<=c;j++) if(z[j]=='h' && z[j+1]=='a' && z[j+2] =='h' && z[j+3]=='a') count++;
				
				std::vector<char> temp1, temp2;
				for(int j=1;j<=3&&j<=c;j++) temp1.push_back(z[j]);
				for(int j=c-2>1?c-2:1;j<=c;j++) temp2.push_back(z[j]);
				
				M[s1] = {count,c,temp1,temp2};
				last = count;
			}
			else
			{
				int s2 = 0, s3 = 0;
				scanf("%s",z+1);
				int c = strlen(z+1);
				for(int j=1;j<=c;j++) s2 *= 26, s2 += z[j]-'a';
				scanf("%s",z+1);
				scanf("%s",z+1);
				c = strlen(z+1);
				for(int j=1;j<=c;j++) s3 *= 26, s3 += z[j]-'a';
				
				long long int count = M[s2].count + M[s3].count;
				
				std::vector<char> temp;
				for(int j=0;j<M[s2].down.size();j++) temp.push_back(M[s2].down[j]);
				for(int j=0;j<M[s3].up.size();j++) temp.push_back(M[s3].up[j]);
				
				for(int j=0;j+3<temp.size();j++)
				{
					if(temp[j]=='h'&&temp[j+1]=='a'&&temp[j+2]=='h'&&temp[j+3]=='a') count++;
				}
				
				std::vector<char> up,down;
				for(int j=0;j<M[s2].up.size();j++) up.push_back(M[s2].up[j]);
				for(int j=0;j<M[s3].down.size();j++) down.push_back(M[s3].down[j]);
				if(up.size()==M[s2].length)
				{
					for(int j=0;j<M[s3].up.size();j++) if(up.size()<3) up.push_back(M[s3].up[j]);
				}
				if(down.size()==M[s3].length)
				{
					std::reverse(down.begin(),down.end());
					for(int j=M[s2].down.size()-1;j>=0;j--) if(down.size()<3) down.push_back(M[s2].down[j]);
					std::reverse(down.begin(),down.end());
				}
				
				M[s1] = {count,M[s2].length+M[s3].length,up,down};
				
				last = count;
			}
			//printf("%lld??\n",last);
		}
		printf("%lld\n",last);
	}
}