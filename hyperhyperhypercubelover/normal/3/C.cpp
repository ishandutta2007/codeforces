#include<cstdio>

char s[3][4];

int main()
{
	int xw,yw;
	int i,j,x,y;
    scanf("%s%s%s",s[0],s[1],s[2]);
    x=y=0;
	for(i=0;i<3;i++)for(j=0;j<3;j++)
	{
		if(s[i][j]=='X')x++;
		if(s[i][j]=='0')y++;
	}
	if(x-y>1||x-y<0)
	{
		printf("illegal");
		return 0;
	}
	xw=yw=0;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)if(s[i][j]!='X')break;
		if(j==3)xw=1;
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)if(s[i][j]!='0')break;
		if(j==3)yw=1;
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)if(s[j][i]!='X')break;
		if(j==3)xw=1;
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)if(s[j][i]!='0')break;
		if(j==3)yw=1;
	}
	for(j=0;j<3;j++)if(s[j][j]!='X')break;
    if(j==3)xw=1;
	for(j=0;j<3;j++)if(s[j][j]!='0')break;
    if(j==3)yw=1;
	for(j=0;j<3;j++)if(s[j][2-j]!='X')break;
    if(j==3)xw=1;
	for(j=0;j<3;j++)if(s[j][2-j]!='0')break;
    if(j==3)yw=1;
    if(xw&&yw)
	{
		puts("illegal");
		return 0;
	}
    if(xw&&x==y)
	{
		puts("illegal");
		return 0;
	}
    if(yw&&x!=y)
	{
		puts("illegal");
		return 0;
	}
    if(xw)
	{
		puts("the first player won");
		return 0;
	}
    if(yw)
	{
		puts("the second player won");
		return 0;
	}
	if(x+y==9)
	{
		puts("draw");
		return 0;
	}
	if(x>y)
	{
		puts("second");
		return 0;
	}
	puts("first");
	return 0;
}