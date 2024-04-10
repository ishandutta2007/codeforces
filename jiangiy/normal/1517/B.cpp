#include<bits/stdc++.h>
#define fi first
#define se second
#define ULL unsigned long long
#define LL long long
#define PI std::pair<int,int>
#define MP std::make_pair
int n,m,s[101][101],l[101],r[101],ans[101][101];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)scanf("%d",&s[i][j]);
		for(int i=1;i<=n;i++)std::sort(s[i]+1,s[i]+m+1),l[i]=1,r[i]=m;
		for(int i=1;i<=m;i++){
			int t=1e9+10,p=0;
			for(int j=1;j<=n;j++) if(s[j][l[j]]<t)t=s[j][l[j]],p=j;
			for(int j=1;j<=n;j++){
				if(p==j)ans[i][j]=s[j][l[j]++];
				else ans[i][j]=s[j][r[j]--];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)printf("%d ",ans[j][i]);
			puts("");
		}
	}
}