#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,num[11000000];
long long w[11000000];
const int N=10000000;
long long m;
pair<int,long long> dfs(long long m){
	if (m==0) return make_pair(0,0);
	if (m<=N&&num[m]) return make_pair(num[m],w[m]); 
	int n=trunc(pow(m,1/3.0));
	while (1ll*n*n*n<=m) n++;
	while (1ll*n*n*n>m) n--;
	long long k1=m-1ll*n*n*n,k2=1ll*n*n*n-1-1ll*(n-1)*(n-1)*(n-1);
	pair<int,long long>ans=dfs(k1); ans.second+=1ll*n*n*n; ans.first++;
	if (k1<1ll*n*n*n&&n>1){
		k1++; pair<int,long long>ans2=dfs(k2); ans2.first++; ans2.second+=1ll*(n-1)*(n-1)*(n-1);
		if (ans2.first>ans.first) ans=ans2;
	}
	if (m<=N){
		num[m]=ans.first; w[m]=ans.second;
	}
	return ans;
}
int main(){
	scanf("%I64d",&m);
	pair<int,long long>ans=dfs(m);
	printf("%d %I64d\n",ans.first,ans.second);
/*	n=1; int ans=0; long long num=0;
	while (1ll*n*n*n<=m) n++; n--;
	while (n){
		if (m<1ll*n*n*n) {n--; continue;}
		ans++;
		long long k1=m-1ll*n*n*n,k2=1ll*n*n*n-1-1ll*(n-1)*(n-1)*(n-1);
		if (k1<k2){
			num+=1ll*(n-1)*(n-1)*(n-1); m=k2;
		} else num+=1ll*n*n*n,m=k1;
	}
	printf("%d %I64d\n",ans,num);*/
	return 0;
}