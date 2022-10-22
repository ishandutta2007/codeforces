#include <cstdio>
const int Maxn=10000;
int query(int x){
	printf("? %d\n",x);
	fflush(stdout);
	int ans;
	scanf("%d",&ans);
	return ans;
}
int p[Maxn+5];
void solve(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		p[i]=0;
	}
	for(int i=1;i<=n;i++){
		if(p[i]){
			continue;
		}
		static int lis[Maxn+5];
		int len=0;
		lis[++len]=query(i);
		int x;
		while((x=query(i))!=lis[1]){
			lis[++len]=x;
		}
		for(int j=2;j<=len;j++){
			p[lis[j-1]]=lis[j];
		}
		p[lis[len]]=lis[1];
	}
	printf("!");
	for(int i=1;i<=n;i++){
		printf(" %d",p[i]);
	}
	puts("");
	fflush(stdout);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}