#include <cstdio>
#include <algorithm>

int n,r[1001],c[1001];
int ans[4][1000001],top;
void add(int x1,int y1,int x2,int y2){
	++top;
	ans[0][top]=x1;
	ans[1][top]=y1;
	ans[2][top]=x2;
	ans[3][top]=y2;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",r+i);
	for(int i=1;i<=n;i++)scanf("%d",c+i);
	for(int i=n;i;i--){
		int pr,pc;
		for(int j=1;j<=i;j++){
			if(r[j]==i)pr=j;
			if(c[j]==i)pc=j;
		}
		if(pr==i&&pc==i)continue;
		else{
			add(i,c[i],r[i],i);
			std::swap(r[pr],r[i]);
			std::swap(c[pc],c[i]);
		}
	}
	printf("%d\n",top);
	for(int i=1;i<=top;i++,putchar('\n'))
		for(int j=0;j<4;j++)
			printf("%d ",ans[j][i]);
}