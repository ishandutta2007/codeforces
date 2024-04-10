#include<bits/stdc++.h>
using namespace std;
int n,a[1100]; char Ans[1100][1100];
int main(){
	scanf("%d",&n); int pos=0;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if (a[i]!=i) pos=i;
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			Ans[i][j]='.';
	if (pos){
		printf("%d\n",n-1); int op=0;
		for (int i=n;i>=1;i--){
			int tmp=pos; char ch;
			op^=1;
			if (op){
				for (int j=n;j>=1;j--)
					if (a[j]!=j) tmp=j;
				ch='/';
			} else{
				for (int j=1;j<=n;j++)
					if (a[j]!=j) tmp=j;
				ch='\\';				
			}
			if (tmp==pos) break;
			Ans[i][tmp]=Ans[i][a[tmp]]=Ans[i][pos]=ch;
			a[pos]=a[a[tmp]]; a[a[tmp]]=a[tmp]; pos=tmp;
		}
	} else printf("%d\n",n);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++)
			putchar(Ans[i][j]);
		putchar('\n');
	}
	return 0;
}