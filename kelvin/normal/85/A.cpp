#include <stdio.h>
#include <string.h>
#define MAXL 105

int n;
char s[4][MAXL];

int main(void)
{
	int i;
	scanf("%d",&n);
	if(n&1) {
		for(i=1;i<n;i++)
			s[0][i]=((i-1)/2)&1?'b':'c';
		for(i=1;i<n;i++)
			s[1][i]=((i-1)/2)&1?'d':'e';
		for(i=0;i<n-1;i++)
			s[2][i]=(i/2)&1?'f':'g';
		for(i=0;i<n-1;i++)
			s[3][i]=(i/2)&1?'h':'i';
		s[0][0]=s[1][0]='a';
		s[2][n-1]=s[3][n-1]='j';
	} else {
		for(i=0;i<n;i++)
			s[0][i]=(i/2)&1?'b':'c';
		for(i=0;i<n;i++)
			s[3][i]=(i/2)&1?'d':'e';
		for(i=1;i<n-1;i++)
			s[1][i]=((i-1)/2)&1?'f':'g';
		for(i=1;i<n-1;i++)
			s[2][i]=((i-1)/2)&1?'h':'i';
		s[1][0]=s[2][0]='a';
		s[1][n-1]=s[2][n-1]='j';
	}
	s[0][n]=s[1][n]=s[2][n]=s[3][n]='\0';
	puts(s[0]);
	puts(s[1]);
	puts(s[2]);
	puts(s[3]);
}