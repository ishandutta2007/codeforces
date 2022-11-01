#include <bits/stdc++.h>
using namespace std;
int T;
int main()
{
	//freopen("infile.txt", "r", stdin);
	scanf("%d", &T);
	for(int t=0; t<T; t++)
	{
		int N, R, sum=0;;
		scanf("%d %d", &N, &R);
		for(int n=1; n<N; n++)
		{
			int inp;
			scanf("%d", &inp);
			sum+= inp;
		}
		for(int n=1; n<=N; n++)
		{
			if((sum+n)%N == R-1)
			{
				printf("%d\n",n);
			}
		}
	}	
}