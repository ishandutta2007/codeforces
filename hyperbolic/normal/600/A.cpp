#include <stdio.h>
#include <vector>
#include <string.h>

char x[100010];
std::vector< std::vector<char> > V1,V2;
std::vector<char> V;

int main()
{
	scanf("%s",x+1);
	int a = strlen(x+1);
	int control = 0;
	for(int i=1;i<=a;i++)
	{
		if(x[i]==',' || x[i]==';')
		{
			if(V.size()==0) V2.push_back(V);
			else if(control==1) V2.push_back(V);
			else
			{
				if(V.size()==1) V1.push_back(V);
				else if(V[0]=='0') V2.push_back(V);
				else V1.push_back(V);
			}
			V.clear();
			control = 0;
		}
		else
		{
			if('0'<=x[i]&&x[i]<='9');
			else control = 1;
			V.push_back(x[i]);
		}
	}
	if(V.size()==0) V2.push_back(V);
	else if(control==1) V2.push_back(V);
	else
	{
		if(V.size()==1) V1.push_back(V);
		else if(V[0]=='0') V2.push_back(V);
		else V1.push_back(V);
	}
			
	if(V1.size()==0) printf("-\n");
	else
	{
		printf("\"");
		for(int i=0;i+1<V1.size();i++)
		{
			for(int j=0;j<V1[i].size();j++) printf("%c",V1[i][j]);
			printf(",");
		}
		for(int j=0;j<V1.back().size();j++) printf("%c",V1.back()[j]);
		
		printf("\"");
		printf("\n");
	}
	
	if(V2.size()==0) printf("-\n");
	else
	{
		printf("\"");
		for(int i=0;i+1<V2.size();i++)
		{
			for(int j=0;j<V2[i].size();j++) printf("%c",V2[i][j]);
			printf(",");
		}
		for(int j=0;j<V2.back().size();j++) printf("%c",V2.back()[j]);
		printf("\"");
	}
}