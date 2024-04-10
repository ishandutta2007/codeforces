#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define LL long long
using namespace std;
const int N=4e5+10;
const LL inf=1e18;
int n;
int a[N];
LL x;
LL mp[30][30];
int hed[30],nxt[30];
int b[2000000];
LL dp[2000000],t[(1<<20)+10][21];
int main(){
	//cout<<(4&-4)<<endl;
	scanf("%d",&n);
	for(int i=1;i<=n;++i) {
		scanf("%d",&a[i]);
		--a[i];
		//cout<<a[i]<<endl;
	}
	for(int i=0;i<20;++i){
		for(int j=0;j<20;++j){
			if(i==j) continue;
			x=0;
			for(int k=1;k<=n;++k){
				if(a[k]==j) ++x;
				else if(a[k]==i)mp[i][j]+=x;
			}
		}
	}
	//cout<<mp[2][3]<<endl;
	dp[0]=0;
	for(int i=1;i<(1<<20);++i) dp[i]=inf;
	int cc;
	for(int i=0;i<20;++i) b[1<<i]=i;
	for(int j=0;j<20;++j)
	for(int i=1;i<(1<<20);++i){
		cc=i&-i;
		t[i][j]=t[i-cc][j]+mp[b[cc]][j];
	}
	for(int i=1;i<(1<<20);++i){
		for(int j=0;j<20;++j){
			if(i&(1<<j)){
				dp[i]=min(dp[i],dp[i-(1<<j)]+t[i-(1<<j)][j]);
			}
		}
	}
	cout<<dp[(1<<20)-1]<<endl;
}