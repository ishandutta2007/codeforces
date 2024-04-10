#include <bits/stdc++.h>
using namespace std;
int R, C;
char grid[200][200];
int main()
{
	//freopen("infile.txt", "r", stdin);
	scanf("%d %d", &R, &C);
	for(int r=0; r<R; r++)
	{
		scanf(" %s ", grid[r]);
	}
	R = R-1;
	int count = 0;
	char prev = '.';
	for(int c=0; c<C; c++)
	{
		if(prev =='.' && grid[R][c]=='B')
		{
			count++;
		}
		prev = grid[R][c];
	}
	printf("%d\n",count);
}