#include<bits/stdc++.h>
using namespace std;
int T,n,a[1100000];
int ans,Ans[1100000];
bool vis[1100000];
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for (int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			vis[i]=false;
		}
		int x=1;
		while (!vis[x]){
			vis[x]=true;
			x=x-a[x];
		}
		ans=0;
		int y=x;
		do{
			Ans[++ans]=y;
			y=y-a[y];
		} while (y!=x);
		
		printf("%d\n",ans);
		for (int i=1;i<=ans;i++) printf("%d ",Ans[i]);
		putchar('\n');
	}
	return 0;
}
/*
	i - n <= a_i <= i - 1
	i - a_i <= n , 1 <= i - a_i

	1 <= i - a_i <= n

	\sum_i a_i = 0
	\sum_i (i - a_i) = \sum_i i

	i_1 - a_{i_1} = i_2
	i_2 - a_{i_2} = i_3
	...
	i_k - a_{i_k} = i_1
*/