#include <cstdio>
#include <vector>
#define int long long

int L,R,n=32;
int stk[1000001][3],top;
long long map[40][40];
long long F[40];
signed main(){
	scanf("%lld%lld",&L,&R);
	R-=L-1;
	for(int i=31;i>1;--i){
		map[i][32]=1;
		int now=1;
		for(int j=i+1;j<32;j++){
			map[i][j]=now;
			now+=F[j];
		}
		F[i]=now;
//		printf("%lld\n",F[i]);
	}
	int now=L-1;
	if(!now){
		map[1][32]=1;
		++now;
		--R;
	}
	for(int i=30;~i;--i)
		if(R&(1<<i))map[1][31-i]=now,now+=F[31-i];
	for(int i=1;i<=32;i++)
		for(int j=i+1;j<=32;j++)
			if(map[i][j]>=1&&map[i][j]<=1000000){
				++top;
			}
	printf("YES\n32 %lld\n",top);
	for(int i=1;i<=32;i++)
		for(int j=i+1;j<=32;j++)
			if(map[i][j]>=1&&map[i][j]<=1000000){
				printf("%lld %lld %lld\n",i,j,map[i][j]);
			}
}