#include <cstdio>

int prime[2001],top,n;
bool pri[2001];
int main(){
	scanf("%d",&n);
	for(int i=2;i<=(n<<1);i++){
		if(!pri[i])prime[++top]=i;
		for(int j=1;j<=top&&i*prime[j]<=(n<<1);j++){
			pri[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		}
	}
	int tem=n;
	while(pri[tem])++tem;
	if(n==2){
		puts("-1");
	}
	printf("%d\n",tem);
	for(int i=1;i<=n;i++)printf("%d %d\n",i,(i%n)+1);
	for(int i=n+1;i<=tem;i++){
		printf("%d %d\n",i-n,(i-n+(n>>1)-1)%n+1);
	}
}