// Hydro submission #62514f6cbdeecda4a2a43890@1649495917235
#include<bits/stdc++.h>
using namespace std;
int n,k,li[3009];
vector<long long > q[3009];
long long ans=0;
vector<long long > dp(3009,0);
inline int read(){
	int sum=0,fh=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')fh=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		sum*=10;
		sum+=c-'0';
		c=getchar();
	}
	return sum*fh;
}
void solve(int l,int r){
	if(l>r){
		return ;
	}
	if(l==r){
		for(int i=0;i<=min(k,li[l]);i++)ans=max(ans,dp[k-i]+q[l][i]);
		return ;
	}
	int mid=(l+r)/2;
	vector<long long > f=dp;
	for(int i=mid+1;i<=r;i++){
		for(int j=k;j>=li[i];j--){
			dp[j]=max(dp[j],dp[j-li[i]]+q[i][li[i]]);
		}
	}
	solve(l,mid);
	dp=f;
	for(int i=l;i<=mid;i++){
		for(int j=k;j>=li[i];j--){
			dp[j]=max(dp[j],dp[j-li[i]]+q[i][li[i]]);
		}
	}
	solve(mid+1,r);
	return ;
}
int main(){
//    freopen("factory.in","r",stdin);
//    freopen("factory.out","w",stdout);
	n=read();
	k=read();
	for(int i=1;i<=n;i++){
		li[i]=read();
		q[i].reserve(li[i]+10);
		q[i][0]=0;
		for(int j=1;j<=li[i];j++){
			q[i][j]=read();
			q[i][j]+=q[i][j-1];
		}
	}
	solve(1,n);
	cout<<ans;
	  fclose(stdin);
    fclose(stdout);
	return 0;
}