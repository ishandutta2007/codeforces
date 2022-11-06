#include<bits/stdc++.h>
using namespace std;
int a[100005],n;
void work(int n){
	for (int i=20,x;i;i--)
		if (n&(1<<i)){
			x=((1<<(i+1))-1)^n;
			if (x>1) work(x-1);
			for (;n>=x;printf("%d ",n--));
			return;
		}
}
int main(){
	scanf("%d",&n);
	if (n&1) puts("NO");
	else{
		puts("YES");
		work(n);
		puts("");
	}
	if (n<6||n==(n&(-n))) puts("NO");
	else{
		puts("YES");
		a[1]=3; a[2]=6; a[3]=2;
		a[4]=5; a[5]=1; a[6]=4;
		for (int i=7;i<=n;i++)
			if (i==(i&(-i))) a[i]=i+1,a[i+1]=i,i++;
			else a[i]=a[i&(-i)],a[i&(-i)]=i;
		for (int i=1;i<=n;i++) printf("%d ",a[i]);
	}
}