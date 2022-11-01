#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,f[2005][2005];
string s;

int dfs(int l,int r,char c){
	int res,k;
	if(l>r)return 0;
	if(f[l][r]!=-1)return f[l][r];
	if(!c){
		res=0;
		res=max(dfs(l+1,r,s[l]),dfs(l,r-1,s[r]));
	}
	else{
		res=1;
		if(s[l]==c)res=min(res,dfs(l+1,r,0));
		if(s[r]==c)res=min(res,dfs(l,r-1,0));
	}
	return f[l][r]=res;
}

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>s;
		n=s.size();s=" "+s;
		for(i=1;i<=n;i++)memset(f[i],-1,sizeof(f[i]));
		k=dfs(1,n,0);
		if(k==0)cout<<"Draw\n";
		if(k==1)cout<<"Alice\n";
	}
}