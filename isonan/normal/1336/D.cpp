#include <cstdio>
#define int long long

int n,sum,v[110][2],a[110];
int t[110];
bool vis[110];
int C(int n){
	return (n*(n-1)*(n-2))/6ll;
}
signed main(){
	scanf("%lld",&n);
	scanf("%lld%lld",&v[0][0],&v[0][1]);
	for(int i=1;i<=n;i++)t[i]=C(i+1)-C(i);
	for(int i=1;i<n;i++){
		printf("+ %lld\n",i);
		fflush(stdout);
		scanf("%lld%lld",&v[i][0],&v[i][1]);
		if(v[i][0]>v[i-1][0]){
			for(int j=1;j<=n;j++)
				if(t[j]==v[i][0]-v[i-1][0]){
					a[i]=j;
				}
			continue;
		}
		else{
			a[i]=-1ll;
		}
	}
	if(a[3]==-1){
		if(v[2][1]-v[1][1])a[3]=1ll;
		else a[3]=0ll;
	}
		printf("+ %lld\n",1ll);
		fflush(stdout);
		int tem,tem2;
		scanf("%lld%lld",&tem,&tem2);
		if(a[1]==-1){
			if(tem-v[n-1][0])a[1]=1ll;
			else a[1]=0ll;
		} 
		a[2]=(tem2-v[n-1][1])/(a[3]+1ll)-1ll;
			for(int j=4;j<n;j++){
				if(a[j]==-1){
					int diff=(v[j-1][1]-v[j-2][1]-((j>3)?(a[j-3]+1ll)*(a[j-2]+1ll):0));
					if(diff)a[j]=1;
					else a[j]=0;
				}
			}
	int cnt=0;
	for(int i=2;i<n-1;i++)cnt+=(a[i-1]+1ll)*(a[i]+1ll)*(a[i+1]+1ll);
	a[n]=(v[n-1][1]-cnt)/((a[n-1]+1ll)*(a[n-2]+1ll));
	printf("! ");
	for(int i=1;i<=n;i++)printf("%lld ",a[i]);putchar('\n');
	fflush(stdout);
	return 0;
}