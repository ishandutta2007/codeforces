#include<bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define ll long long
#define eb emplace_back
using namespace std;
const int M=1e6+9;
int n;
int dp[M];
char s[M];
int lap[M],lae[M];
int a[M],b[M],p,t;
int pl[M],pr[M];
bool check(int x){
	b[t+1]=1e9;
	for(int i=1,l=1;i<=p;++i){
		while(l<=t&&a[i]-b[l]>x)l++;
		pl[i]=l;
	}
	for(int i=p,r=t;i>=1;--i){
		dp[i]=1e9;
		while(b[r]-a[i]>x)r--;
		pr[i]=r;
	}
	if(pl[1]>1||pr[p]<t)return 0;
	if(b[pr[p]]>a[p])dp[p]=a[p];
	else dp[p]=a[p]-x;
	for(int i=p-1;i>=1;--i){
		if(lae[a[i]]>=dp[i+1]||lae[a[i]]==0)dp[i]=a[i]-x;
		else{
			if(dp[i+1]<=b[pr[i]+1])dp[i]=a[i];
			if(i<p-1&&dp[i+2]<=b[pr[i]+1])dp[i]=min(dp[i],a[i+1]-x);
			else if(i==p-1&&pr[i]==t)dp[i]=min(dp[i],a[i+1]-x);
		}
		if(dp[i]==1e9)return 0;
	}
	return dp[1]<=b[1];
}
int main(){
	cin>>n>>(s+1);
	int id;
	for(int i=1;i<=n;++i){
		if(s[i]=='P')a[++p]=i,id=i;
		if(s[i]=='*')b[++t]=i;
	}
	if(t==0){
		puts("0 0");
		return 0;
	}
	if(p==1){
		int x1=0,x2=0,p1=0,p2=0;
		for(int i=1;i<=id;++i){
			if(s[i]=='*'){
				x1++;
				if(p1==0)p1=id-i;
			}
		}
		for(int i=n;i>=id;--i){
			if(s[i]=='*'){
				x2++;
				if(p2==0)p2=i-id;
			}
		}
		if(x1==x2)cout<<max(x1,x2)<<" "<<min(p1,p2)<<"\n";
		else cout<<max(x1,x2)<<" "<<(x1<x2?p2:p1)<<"\n";
		return 0;
	}
	for(int i=n,lp=0,le=0;i>=1;--i){
		if(s[i]!='.')lap[i]=lp,lae[i]=le;
		if(s[i]=='P')lp=i;
		if(s[i]=='*')le=i;
	}
	int l=1,r=n;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	cout<<t<<" "<<l<<"\n";
	return 0;
}