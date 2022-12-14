#include <stdio.h>
#include <algorithm>

char x[110][110];
char p[5];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
	p[1] = 'R', p[2] = 'G', p[3] = 'B';
	
	if(a%3==0)
	{
		std::sort(p+1,p+4);
		do{
			int c = a/3;;
			for(int i=1;i<=c;i++) for(int j=1;j<=b;j++) if(x[i][j]!=p[1]) goto u;
			for(int i=c+1;i<=2*c;i++) for(int j=1;j<=b;j++) if(x[i][j]!=p[2]) goto u;
			for(int i=2*c+1;i<=3*c;i++) for(int j=1;j<=b;j++) if(x[i][j]!=p[3]) goto u;
			
			printf("YES");
			return 0;
			u:;
		}while(std::next_permutation(p+1,p+4));
	}
	
	if(b%3==0)
	{
		std::sort(p+1,p+4);
		do{
			int c = b/3;;
			for(int j=1;j<=c;j++) for(int i=1;i<=a;i++) if(x[i][j]!=p[1]) goto u2;
			for(int j=c+1;j<=2*c;j++) for(int i=1;i<=a;i++) if(x[i][j]!=p[2]) goto u2;
			for(int j=2*c+1;j<=3*c;j++) for(int i=1;i<=a;i++) if(x[i][j]!=p[3]) goto u2;
			
			printf("YES");
			return 0;
			u2:;
		}while(std::next_permutation(p+1,p+4));
	}
	printf("NO");
}