#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
int n,K,A[3100],B[3100];
int bo[3100][3100];
int main(){
	scanf("%d%d",&n,&K);
	int tot=n*(n-1);
	for (int i=1;i<=K;i++){
		scanf("%d",&A[i]); tot-=A[i];
	}
	if (tot<0){
		printf("no\n"); return 0;
	}
	int rem=n-K;
	if (rem){
		int k1=tot/rem,k2=tot%rem;
		if (A[K]<k1+(k2>0)){
			printf("no\n"); return 0;
		}
		for (int i=1;i<=k2;i++) A[++K]=k1+1;
		for (int i=1;i<=rem-k2;i++) A[++K]=k1;
	}
	tot=0; //cout<<"asd"<<endl;
	for (int i=n;i;i--){
		tot+=A[i]; //cout<<tot<<" "<<i*(i-1)<<endl;
		if (tot<(n-i+1)*(n-i)){
			printf("no\n"); return 0;
		}
	}
	memset(bo,0x00,sizeof bo);
	for (int now=1;now<=n;now++){
	//	cout<<"asd "<<now<<endl;
	//	for (int i=1;i<=n;i++) cout<<A[i]<<" "; cout<<endl;
		int rem=-A[now]+(n-now)*2;
		int l=now+1;
		for (int i=1;i<=n;i++) B[i]=2;
		while (rem){
			int r=l;
			while (r<=n&&A[r]==A[l]) r++; r--;
			for (int i=r;i>=l&&rem;i--){
				A[i]--; B[i]--; rem--;
			}
			while (l<=n&&B[l]==0) l++;
		}
		bo[now][now]=-1;
		for (int i=now+1;i<=n;i++){
			bo[i][now]=2-B[i];
			bo[now][i]=B[i];
		}
	}
	printf("yes\n");
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++)
			if (bo[i][j]==-1) putchar('X'); else if (bo[i][j]==0) putchar('L');
			else if (bo[i][j]==1) putchar('D'); else putchar('W');
		putchar('\n');
	}
	return 0;
}