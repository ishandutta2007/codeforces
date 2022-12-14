#include <stdio.h>

/*
The main idea of this code is not mine - It's Yuu's Idea
*/

long long int check[110][3][3][3];
int x[110],y[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int a,b;
		scanf("%lld%lld",&a,&b);
		
		for(int i=0;i<=60;i++) x[i] = (a>>i)&1;
		for(int i=0;i<=60;i++) y[i] = (b>>i)&1;
		
		for(int i=0;i<=61;i++) for(int j=0;j<=1;j++) for(int k=0;k<=1;k++) for(int l=0;l<=1;l++) check[i][j][k][l] = 0;
		check[0][0][0][0] = 1;
		for(int i=0;i<=60;i++)
		{
			for(int carry = 0; carry <= 1; carry++)
			{
				for(int less = 0; less <= 1; less++)
				{
					for(int parity = 0; parity <= 1; parity++)
					{
						for(int choose = 0; choose <= 1; choose++)
						{
							int added = (choose + carry + x[i])%2;
							int newCarry = (choose + carry + x[i])/2;
							int newLess = (choose<y[i]) || ((choose==y[i])&&less);
							int newParity = (parity+added+choose)%2;
							check[i+1][newCarry][newLess][newParity] += check[i][carry][less][parity];
						}
					}
				}
			}
		}
		printf("%lld\n",check[61][0][1][1]);
	}
}