#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
vector<int>A[210000],B[210000];
int L[210000],n,m,pd[20][40],bo[50],ask[210000][30],x[50],len,num[40],tot,g[50][50];
void add(int k1,int k2){
	pd[k1][k2]++;
	if (pd[k1][k2]==1){
		num[k1]++;
		if (num[k1]==x[k1]) tot++;
	}
}
void dele(int k1,int k2){
	pd[k1][k2]--;
	if (pd[k1][k2]==0){
		num[k1]--;
		if (num[k1]==x[k1]-1) tot--;
	}
}
void insert(int k1,int k2){
	for (int i=1;i<=len;i++){
		int k3=g[x[i]][L[k1]];
		int k4=k2%k3;
		for (int j=0;j<x[i];j++) if (j%k3!=k4){
			add(i,j);// cout<<i<<" "<<j<<endl;
		}
	}
}
void del(int k1,int k2){
	for (int i=1;i<=len;i++){
		int k3=g[x[i]][L[k1]];
		int k4=k2%k3;
		for (int j=0;j<x[i];j++) if (j%k3!=k4) dele(i,j);
	}
}
int check(){
	return tot==0;
}
int solve(int K){
//	memset(pd,0x00,sizeof pd);
//	memset(bo,0x00,sizeof bo);
//	tot=0;
	int l=0; int ans=0;
	for (int i=0;i<A[K].size();i++){
		int k1=A[K][i];
		insert(k1,B[K][i]-1);
		while (check()==0){
			del(A[K][l],B[K][l]-1); l++;
		}
		ans=max(ans,i-l+1);
		//cout<<"fa "<<A[K][i]<<" "<<A[K][l]<<" "<<tot<<endl;
		if (i+1==A[K].size()||A[K][i+1]!=A[K][i]+1)
			while (l<=i){
				del(A[K][l],B[K][l]-1); l++;
			}
	}
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=2;i<=40;i++)
		if (bo[i]==0){
			x[++len]=i;
			while (x[len]*i<=40) x[len]*=i;
			for (int j=i+i;j<=50;j+=i) bo[j]=1;
		}
	for (int i=1;i<=40;i++)
		for (int j=1;j<=40;j++) g[i][j]=__gcd(i,j);
	for (int i=1;i<=n;i++){
		scanf("%d",&L[i]);
		for (int j=1;j<=L[i];j++){
			int k1; scanf("%d",&k1); A[k1].push_back(i); B[k1].push_back(j);
		}
	}
//	cout<<solve(3)<<endl;
	for (int i=1;i<=m;i++) printf("%d\n",solve(i));
	return 0;
}