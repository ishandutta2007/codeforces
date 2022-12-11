#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
char A[1001000],B[1001000];
int n,m,l[1001000],r[1001000],x[1001000],y[1001000],w[1001000][3][3];
int get(char ch){
	if (ch=='R') return 0; else if (ch=='G') return 1; else if (ch=='B') return 2;
}
int main(){
	scanf("%s",A+1); scanf("%s",B+1); 
	n=strlen(A+1); m=strlen(B+1);
	for (int i=1;i<=n;i++) x[i]=get(A[i]);
	for (int i=1;i<=m;i++) y[i]=get(B[i]);
	int now=1;
	for (int i=1;i<=n;i++){
		while (now<=m&&B[now]!=A[i]) now++; r[i]=min(now,m); now++;
	}
	now=1; l[1]=1;
	for (int i=2;i<=n;i++){
		if (now<=m&&A[i-1]==B[now]) now++; l[i]=now;
	}
	long long ans=0; for (int i=1;i<=n;i++) ans+=r[i]-l[i]+1; 
//	for (int i=1;i<=n;i++) cout<<l[i]<<" "<<r[i]<<endl;
	memset(w,0x00,sizeof w);
	for (int i=2;i<=m;i++){
		memcpy(w[i],w[i-1],sizeof w[i-1]);
		if (y[i]!=y[i-1]) w[i][y[i]][y[i-1]]++;
	}
	for (int i=2;i<=n;i++) ans-=w[r[i]][x[i-1]][x[i]]-w[l[i]-1][x[i-1]][x[i]];
	cout<<ans<<endl;
	return 0;
}