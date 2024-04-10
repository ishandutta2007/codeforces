#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int N=1e5+10;
const int E=320; 

int n,m;

int a[1050],b[1050];
int c[1050];
int nxt[510][1050];
int f[510][510];
pair<int,int> re[510][510];
map<int,int> mp;
void find(int L,int R){
	if(L==0&&R==0) return;
	find(re[L][R].first,re[L][R].second);
	printf("%d ",c[a[L]]);
	return;
}
void MAIN(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) {
		scanf("%d",&a[i]);
		c[i]=a[i];
	}
	scanf("%d",&m);
	for(int i=1;i<=m;++i) {
		scanf("%d",&b[i]);
		c[i+n]=b[i];
	}
	sort(c+1,c+1+n+m);
	int cnt=1;
	for(int i=2;i<=n+m;++i){
		if(c[i]!=c[i-1]) c[++cnt]=c[i];
	}
	for(int i=1;i<=cnt;++i){
		mp[c[i]]=i;
	}
	for(int i=1;i<=n;++i) a[i]=mp[a[i]];
	for(int i=1;i<=m;++i) b[i]=mp[b[i]];
	for(int i=1;i<=cnt;++i) nxt[m+1][i]=m+1;
	for(int j=m;j>=1;--j){
		for(int i=1;i<=cnt;++i) nxt[j][i]=nxt[j+1][i];
		nxt[j][b[j]]=j;
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(a[i]==b[j]){
				f[i][j]=1;
				re[i][j].first=0;
				re[i][j].second=0;
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(!f[i][j]) continue;
			for(int k=i+1;k<=n;++k){
				if(a[k]<=a[i]) continue;
				int o=nxt[j+1][a[k]];
				if(o>m) continue;
				if(f[i][j]+1>f[k][o]){
					f[k][o]=f[i][j]+1;
					re[k][o].first=i;
					re[k][o].second=j;
				}
			}
		}
	}
	int L=0,R=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(f[i][j]>f[L][R]){
				L=i;R=j;
			}
		}
	}
	printf("%d\n",f[L][R]);
	find(L,R);
	puts("");
	return;
}
int main(){
	int ttt=1;
	while(ttt--) MAIN();
    return 0;
}