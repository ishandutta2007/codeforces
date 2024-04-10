#include<bits/stdc++.h>
#define fi first
#define se second
#define LL long long
#define PI std::pair<int,int>
#define MP std::make_pair
const int N=100005;
int n,c[N][26],p[26][N],u[26];
char s[N],t[N];
int chk(int x){
	int y=p[x][u[x]+1],res=0;
	for(int i=0;i<26;i++) if(i!=x){
		res+=std::max(0,c[y][i]-u[i]);
	}
	return res;
}
int main(){
	int T;
	for(scanf("%d",&T);T--;){
		scanf("%d%s%s",&n,s+1,t+1);
		for(int i=1;i<=n;i++)s[i]-=97,t[i]-=97;
		for(int i=1;i<=n;i++){
			for(int j=0;j<26;j++)c[i][j]=c[i-1][j]+(s[i]==j);
			p[s[i]][c[i][s[i]]]=i;
		}
		LL ans=1e18;
		for(int i=0;i<26;i++)u[i]=0;
		LL cur=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<t[i];j++){
				if(u[j]==c[n][j])continue;
				LL v=cur+chk(j);
				ans=std::min(ans,v);
			}
			if(u[t[i]]==c[n][t[i]])break;
			cur+=chk(t[i]);
			u[t[i]]++;
		}
		printf("%lld\n",ans>1e17?-1:ans);
	}
}