#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000005
#define pb push_back
#define mod 998244353
#define pn cout<<"No\n"
#define py cout<<"Yes\n"

vector<int>son[N];
int T,n,a[N],l,cnt,i,j,x,y,z,k,c[N],dp[N];
char s[N],t[N];
bool u[2];
int main(){
	cin>>T;
	while(T--){
		scanf("%d%s%s",&l,s+1,t+1);
		u[0]=u[1]=0;
		u[s[1]-'0']=1;u[t[1]-'0']=1;
		dp[1]=u[0]+(u[0]&&u[1]);
		for(i=2;i<=l;++i){
			u[0]=u[1]=0;
			u[s[i]-'0']=1;
			u[t[i]-'0']=1;
			dp[i]=dp[i-1]+u[0]+(u[0]&&u[1]);
			u[s[i-1]-'0']=1;
			u[t[i-1]-'0']=1;
			dp[i]=max(dp[i],dp[i-2]+u[0]+(u[0]&&u[1]));
	//		cout<<dp[i]<<"\n";
		}
		cout<<dp[l]<<'\n';
	}
}