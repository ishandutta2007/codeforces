#include <bits/stdc++.h>
using namespace std;

int n,k;
char str[210][210];

int main()
{
    scanf("%d%d",&n,&k);
    for(int i = 1; i <= 4; i ++) for(int j = 1; j <= n; j ++) str[i][j] = '.';
    if(k%2==0)
	{
        int c=2;
        while(k)
		{
            str[2][c] = str[3][c] = '#';
            c ++; k -= 2;
        }
    }
    else
	{
        str[2][n/2+1] = '#'; k --;
        int c1=n/2,c2=(n+1)/2+1;
        while(k)
		{
            str[2][c1] = str[2][c2] = '#';
            c1 --; c2 ++; k -= 2;
            if(c1 == 1) break;
        }
        c1=n/2,c2=(n+1)/2+1;
        while(k)
		{
            str[3][c1] = str[3][c2] = '#';
            c1 --; c2 ++; k -= 2;
            if(c1 == 1) break;
        }
    }
    puts("YES");
    for(int i = 1; i <= 4; i ++)
	{
        for(int j = 1; j <= n; j ++) printf("%c",str[i][j]);
        puts("");
    }
    return 0;
}