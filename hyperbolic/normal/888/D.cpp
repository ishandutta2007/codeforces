#include <stdio.h>

long long int check[1010][5];
long long int comb(int s, int t)
{
	if(t==0) return 1;
	if(t==s) return 1;
	if(check[s][t]) return check[s][t];
	
	return check[s][t] = comb(s-1,t-1) + comb(s-1,t);
}
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	if(b==1) printf("1");
	else if(b==2) printf("%lld",comb(a,2)+1);
	else if(b==3) printf("%lld",comb(a,2)+comb(a,3)*2+1);
	else if(b==4)
	{
		long long int s = comb(a,2) + comb(a,3)*2;
		s += comb(a,2) * comb(a-2,2) / 2;
		s += comb(a,4) * 6;
		printf("%lld",s+1);
	}
}