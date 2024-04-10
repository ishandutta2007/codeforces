#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int size=450;
int where[210000],L[500],R[500],n,x[210000],A[210000],B[500],num[210000],m;
void insert(int k1){
	num[k1]++; int k=where[k1],pre=-1; B[k]=-1;
	for (int i=L[k];i<=R[k];i++){
		A[i]=pre; 
		if (num[i]) B[k]=i,pre=i; 
	}
}
void del(int k1){
	num[k1]--; int k=where[k1],pre=-1; B[k]=-1;
	for (int i=L[k];i<=R[k];i++){
		A[i]=pre; 
		if (num[i]) B[k]=i,pre=i; 
	}
}
int getpre(int k){
	if (A[k]>0) return A[k];
	for (int i=where[k]-1;i;i--) if (B[i]>0) return B[i];
	return -1;
}
int check(int n){
	int k1=getpre(n+1); 
	while (k1>0){
		if (1ll*num[k1]*k1>n) n%=k1; else n-=num[k1]*k1;
		k1=getpre(min(k1,n+1)); 
	}
	return n;
}
int main(){
	scanf("%d%d",&n,&m);
	memset(A,0xff,sizeof A);
	memset(B,0xff,sizeof B);
	for (int i=1;i<=n+1;i++) where[i]=i/size+1;
	for (int i=1;i<=n+1;i++) R[where[i]]=i;
	for (int i=n+1;i;i--) L[where[i]]=i;
	for (int i=1;i<=m;i++){
		int k1; scanf("%d",&k1); insert(k1);
	}
	int ans=0;
	for (int i=1;i<=n;i++){
		insert(i);
		if (check(n)){
			printf("%d\n",i); return 0;
		}
		del(i);
	}
	printf("Greed is good\n");
}