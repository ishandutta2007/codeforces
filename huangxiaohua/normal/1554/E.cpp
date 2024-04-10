#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353
int i,j,k,n,m,t,x,y,cur,res[200500],yes;bool f[200500];
ll ksm(ll a,int p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}
vector<int> v[200500];
void dfs(int x,int fa){
	int k=0;f[x]=0;
	for(auto i:v[x]){
		if(i==fa){continue;}
		dfs(i,x);k+=f[i];
	}
	k%=cur;
	if(!k){f[x]=1;return;}
	if(k!=(cur-1)){yes=0;}
}
int main() {
    scanf("%d",&t);
    while(t--){
    	scanf("%d",&n);
    	for(i=1;i<=n;i++){v[i].clear();}
		for(i=1;i<n;i++){
			scanf("%d%d",&x,&y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		memset(res,0,4*n+50);
		res[1]=ksm(2,n-1);
		for(i=2;i<n;i++){
			if((n-1)%i){continue;}
			cur=i;yes=1;
			dfs(1,0);res[i]=yes;
		}
		for(i=n;i>=1;i--){
			for(j=i+i;j<=n;j+=i){res[i]-=res[j];}
		}
		for(i=1;i<=n;i++){printf("%lld ",res[i]%M);}puts("");
	}
}