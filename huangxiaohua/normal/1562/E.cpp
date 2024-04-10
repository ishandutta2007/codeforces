#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 600005
int i,j,k,t,n,m,it,siz[5050],cur,res,it2;
char s0[5050];
string sb[5050];
//
struct trie{
	int mp[30];
	int f1,f2,len,fa;
}s[10050];

void build(int id,int dep,int l,int r){
	if(l==r){
		s[id].len+=(siz[l]-dep+2);return;
	}
	int x[30],i,y[30],j,k=0;
	memset(x,1,sizeof(x));
	memset(y,0,sizeof(y));
	s[id].len++;
	memset(s[id].mp,0,sizeof(s[id].mp));
	
	for(j=l;j<=r;j++){
		if(siz[j]>=dep){
			x[sb[j][dep]-'a'+1]=min(x[sb[j][dep]-'a'+1],j);
			y[sb[j][dep]-'a'+1]=max(y[sb[j][dep]-'a'+1],j);
		}
	}
	for(i=1;i<=26;i++){
		k+=(y[i]>0);
	}
	if((dep==1)||k>1){
		for(i=1;i<=26;i++){
			if(y[i]){
				s[id].mp[i]=++it;
				s[it].fa=id;
				build(it,dep+1,x[i],y[i]);
			}
		}
		return;
	}
	if(k==1){
		for(i=1;i<=26;i++){
			if(y[i]){
				build(id,dep+1,x[i],y[i]);return;
			}
		}
	}
}

void dfs(int cur,int dep,int ans){
	int i,j,k,f=s[cur].fa,nmsl=dep+s[cur].len;
	for(i=1;i<s0[dep];i++){
		if(s[f].mp[i]){
			ans=max(ans,s[s[f].mp[i]].f2);
		}
	}
	ans+=min(s[cur].len,n-dep+1);
	ans=max(ans,s[cur].f1);
	s[cur].f1=ans;
	s[cur].f2=max(s[cur].f2,ans);
	if(nmsl<=n){
		dfs(s[cur].mp[s0[nmsl]],nmsl,ans);
		s[cur].f2=max(s[cur].f2,s[s[cur].mp[s0[nmsl]]].f2);
	}
	res=max(res,ans);
}

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		it=0;
		s[0].f1=s[0].f2=0;res=0;
		cin>>n>>s0+1;
		if(n==1){
			cout<<1<<'\n';continue;
		}
		for(i=1;i<=n;i++){
			sb[i].clear();sb[i]+="0";
			for(j=i;j<=n;j++){
				sb[i]+=s0[j];
			}
		}
		sort(sb+1,sb+n+1);
		for(i=1;i<=n;i++){
			siz[i]=sb[i].size()-1;
		}
		build(0,1,1,n);
		for(i=1;i<=n;i++){
			s0[i]-='a'-1;
		}
		for(i=1;i<=n;i++){
			it2=i;
			dfs(s[0].mp[s0[i]],i,0);
		}
		cout<<res<<'\n';
		memset(s,0,sizeof(s[0])*it+500);
	}
}