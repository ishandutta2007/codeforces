#include <cstdio>
#include <algorithm>
const int Maxn=200000;
int n,m;
int a[Maxn+5],b[Maxn+5];
int find_id(int x,int y){
	return (x-1)*m+y;
}
void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&a[find_id(i,j)]);
			b[find_id(i,j)]=a[find_id(i,j)];
		}
		std::sort(b+find_id(i,1),b+1+find_id(i,m));
	}
	int num=0;
	int pos_1=-1,pos_2=-1;
	for(int j=1;j<=m;j++){
		bool flag=0;
		for(int i=1;i<=n;i++){
			if(a[find_id(i,j)]!=b[find_id(i,j)]){
				flag=1;
				break;
			}
		}
		if(flag){
			num++;
			if(pos_1==-1){
				pos_1=j;
			}
			else if(pos_2==-1){
				pos_2=j;
			}
		}
	}
	if(num>2){
		puts("-1");
		return;
	}
	if(num==0){
		puts("1 1");
		return;
	}
	bool flag=1;
	for(int i=1;i<=n;i++){
		if(a[find_id(i,pos_1)]!=b[find_id(i,pos_2)]){
			flag=0;
			break;
		}
	}
	if(!flag){
		puts("-1");
		return;
	}
	printf("%d %d\n",pos_1,pos_2);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}