#include<bits/stdc++.h>
typedef long long ll;
const int MAXN=200000;
ll ans;
int n;
int p[MAXN+5],pos[MAXN+5];
int st[20][MAXN+5],log_2[MAXN+5],pow_2[20];
std::set<int>s[MAXN+5];
int query_max(int l,int r){
	int k=log_2[r-l+1],len=pow_2[k];
	return p[st[k][l]]>p[st[k][r-len+1]]?st[k][l]:st[k][r-len+1];
}
void solve(int l,int r){
	if(l>r){
		return;
	}
	int m=query_max(l,r);
	solve(l,m-1);
	solve(m+1,r);
	if(m-l<r-m){
		for(int i=l;i<m;++i){
			if(p[i]<p[m]&&pos[p[m]-p[i]]>m&&pos[p[m]-p[i]]<=r){
				++ans;
			}
		}
	}else{
		for(int i=m+1;i<=r;++i){
			if(p[i]<p[m]&&pos[p[m]-p[i]]<m&&pos[p[m]-p[i]]>=l){
				++ans;
			}
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&p[i]);
		st[0][i]=i;
		pos[p[i]]=i;
	}
	pow_2[0]=1;
	for(int i=1;i<20;++i){
		pow_2[i]=pow_2[i-1]<<1;
	}
	for(int i=2;i<=n;++i){
		log_2[i]=log_2[i>>1]+1;
	}
	for(int i=1;i<=log_2[n];++i){
		for(int j=1;j<=n-pow_2[i]+1;++j){
			st[i][j]=p[st[i-1][j]]>p[st[i-1][j+pow_2[i-1]]]?st[i-1][j]:st[i-1][j+pow_2[i-1]];
		}
	}
	solve(1,n);
	printf("%I64d\n",ans);
	return 0;
}