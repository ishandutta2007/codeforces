#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define Gett(x,y) scanf("%d%d",&x,&y);
#define gett(x) scanf("%d",&x);																																														
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
#define mp make_pair
const int N=15,n2=(1<<14)+0;
ll t,n,c,ans,o;
vector<ll> dp[n2];
vector<ll> s[n2];
string g[N];
int p(int x){
	if(x%2) return x-1;
	return x+1;
}

ll dfs(int x,int y,int t,int sz){
	if(sz==1) return 1;
	if(dp[x][y*sz+t]>=0) return dp[x][y*sz+t];
	dp[x][y*sz+t]=0;
	dp[x][p(y)*sz+t]=0;
	f(i,0,s[x].size()){
		if(i!=t){
			if(g[s[x][i]][s[x][t]]==char('0'+y%2))
				dp[x][y*sz+t]+=dfs(x-(1<<s[x][t]),y/2,i-(i>t),sz-1);
			else
				dp[x][p(y)*sz+t]+=dfs(x-(1<<s[x][t]),y/2,i-(i>t),sz-1);;
		}
	}
	return dp[x][y*sz+t];
}

int main(){
	f(i,0,n2){
		t=0;c=i,o=0;
		while(c){
			if(c%2) t++,s[i].pb(o);
			c/=2;
			o++;
		}
		f(j,0,(1<<(t-1))*t)
			dp[i].pb(-1); 
	}
	cin>>n;
	f(i,0,n)
		cin>>g[i];
	f(i,0,(1<<(n-1))){
		ans=0;
		f(j,0,n)
			ans+=dfs((1<<n)-1,i,j,n);
		cout<<ans<<" ";
	}
}