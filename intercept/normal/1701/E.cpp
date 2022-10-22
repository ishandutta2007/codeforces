#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
using namespace std;
const int mod=998244353;
const int M=5009;
int kpow(int x,int y,int rex=1){
	for(;y;y>>=1,x=1ll*x*x%mod)rex=1ll*rex*x%mod;
	return rex;
}
int n,m;
int f[M],pre[M],suf[M];
char s[M],t[M];
void work(){
	cin>>m>>n;
	cin>>(t+1)>>(s+1);
	for(int i=1,j=1;i<=n;++i){
		if(s[i]==t[j])j++;
		else {
			while(j<=m&&s[i]!=t[j])j++;
			if(j>m){
				puts("-1");
				return;
			}
			j++;
		}
		pre[i]=j-1;
		
	}
	for(int i=n,j=m;i>=1;--i){
		if(s[i]==t[j])j--;
		else {
			while(j&&s[i]!=t[j])j--;
			j--;
		}
		suf[i]=j+1;
	}
	suf[n+1]=m+1;
	int ans=m;
	for(int x=1;x<=m;++x){
		for(int i=1,j=0;i<=m-x+1;f[++i]=++j)while(j&&t[j+x-1]!=t[i+x-1])j=f[j];
		for(int i=1,j=1;i<=n;++i,++j){
			while(j&&s[i]!=t[j+x-1])j=f[j];
			int L=x-1,R=x+j;
			int r=i+1,l=i-j;
			if(pre[l]<=L&&suf[r]>=R)ans=min(ans,m-(x+j-1)+x-1+(x-1-(i-j))+(x>1));
 
		}
	}
	cout<<ans<<endl;
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}