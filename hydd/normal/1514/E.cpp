#include<bits/stdc++.h>
int T,n,p[110],a[110];
bool query1(int x,int y){
	printf("1 %d %d\n",x-1,y-1); fflush(stdout);
	scanf("%d",&x); return x;
}
bool query2(int x,int y){
	printf("2 %d %d",p[x]-1,n-y+1);
	for (int i=y;i<=n;i++) printf(" %d",p[i]-1);
	putchar('\n'); fflush(stdout);
	scanf("%d",&x); return x;
}
void print(){
	puts("3");
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++)
			putchar((a[i]>=a[j])+'0');
		putchar('\n');
	}
	fflush(stdout);
	int x; scanf("%d",&x);
}
bool cmp(int x,int y){ return query1(y,x);}
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for (int i=1;i<=n;i++) p[i]=i;
		std::stable_sort(p+1,p+n+1,cmp);
		int cnt=0;
		for (int i=1,j=1;i<=n;i=j){
			cnt++; a[p[j++]]=cnt;
			for (int k=i;k<j;k++)
				while (j<=n&&query2(k,j)) a[p[j++]]=cnt;
		}
		print();
	}
	return 0;
}