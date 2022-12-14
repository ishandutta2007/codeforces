#include <stdio.h>
#include <vector>
std::vector< std::pair<int,int> > V;

char x[110][110];
int main()
{
	V.push_back( std::make_pair(1,1));
	V.push_back( std::make_pair(2,4));
	V.push_back( std::make_pair(3,7));
	V.push_back( std::make_pair(4,2));
	V.push_back( std::make_pair(5,5));
	V.push_back( std::make_pair(6,8));
	V.push_back( std::make_pair(7,3));
	V.push_back( std::make_pair(8,6));
	V.push_back( std::make_pair(9,9));
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		for(int i=1;i<=9;i++) scanf("%s",x[i]+1);
		for(int i=0;i<V.size();i++) x[V[i].first][V[i].second] = (x[V[i].first][V[i].second]-'0')%9+1+'0';
		for(int i=1;i<=9;i++)
		{
			for(int j=1;j<=9;j++) printf("%c",x[i][j]);
			printf("\n");
		}
	}
}