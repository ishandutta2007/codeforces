#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<unordered_map>
using namespace std;
unordered_map<int,int>M;
int A[11000000],n,l[400],c[400],len,pre;
long long dp[11000000];
int gcd(int k1,int k2){
	if (k2==0) return k1; return gcd(k2,k1%k2);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&l[i]);
	for (int i=1;i<=n;i++) scanf("%d",&c[i]);
	len=1; M[0]=1;
	for (int now=1;now<=n;now++){
		int pre=len;
		for (int i=1;i<=pre;i++){
			int k1=gcd(A[i],l[now]),k2=M[k1];
			if (k2)
				dp[k2]=min(dp[k2],dp[i]+c[now]);
			else{
				len++; dp[len]=dp[i]+c[now]; M[k1]=len; A[len]=k1;
			}
		}
		
	}
	if (M[1]==0) cout<<-1<<endl; else cout<<dp[M[1]]<<endl;
	return 0;
}