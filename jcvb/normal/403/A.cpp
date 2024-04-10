#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
using namespace std;


int main()
{
	int tes;
	int n,p;
	scanf("%d",&tes);
	while(tes--){
		int m;
		scanf("%d%d",&n,&p);m=2*n+p;
		for (int i=1;i<=n;i++){
			for (int j=i+1;j<=n;j++){
				if(m){
					printf("%d %d\n",i,j);
					m--;
				}
			}
		}
	}
	return 0;
}