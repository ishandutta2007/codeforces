#include<bits/stdc++.h>
using namespace std;
int T,n,a[2100];
int ans,Ans[11000];
void rev(int x){
	assert(x>0&&(x&1));
	Ans[++ans]=x;
	for (int i=1;i<x-i+1;i++) swap(a[i],a[x-i+1]);
}
int getpos(int x){
	for (int i=1;i<=n;i++)
		if (a[i]==x) return i;
	return 0;
}
void work(){
	scanf("%d",&n); bool flag=false;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if ((i&1)!=(a[i]&1)) flag=true;
	}
	if (flag){
		puts("-1");
		return;
	}
	ans=0;
	for (int i=n;i>1;i-=2){
		rev(getpos(i)); rev(getpos(i-1)-1); rev(getpos(i-1)+1);
		rev(getpos(i)); rev(i);
	}
	for (int i=1;i<=n;i++) assert(a[i]==i);
	printf("%d\n",ans);
	for (int i=1;i<=ans;i++) printf("%d ",Ans[i]); putchar('\n');
}
int main(){
	scanf("%d",&T);
	while (T--) work();
	return 0;
}