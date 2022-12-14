#include <stdio.h>
#include <string.h>
#include <vector>

char x[1000010];
std::vector<char> V,V2;
int main()
{
	scanf("%s",x+1);
	int a = strlen(x+1);
	
	int s = 1, t = a;
	while(t>s)
	{
		if(x[s]==x[t])
		{
			V.push_back(x[s]);
			s++,t--;
		}
		else if(t-s>=2)
		{
			if(x[s]==x[t-1])
			{
				V.push_back(x[s]);
				s++,t-=2;
			}
			else if(x[s+1]==x[t])
			{
				V.push_back(x[t]);
				s+=2,t--;
			}
			else if(t-s>=3)
			{
				V.push_back(x[s+1]);
				s+=2,t-=2;
			}
			else
			{
				V2.push_back(x[s]);
				break;
			}
		}
		else
		{
			V2.push_back(x[s]);
			break;
		}
	}
	if(s==t) V2.push_back(x[s]);
	for(int i=0;i<V.size();i++) printf("%c",V[i]);
	for(int i=0;i<V2.size();i++) printf("%c",V2[i]);
	for(int i=V.size()-1;i>=0;i--) printf("%c",V[i]);
}