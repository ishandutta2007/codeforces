#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
const int N=500010;
struct bian{
	int next,point;
}b[N<<1];
const int mo=998244353;
int n;
int way[N][2],ans[N][2],p[N],len;
void ade(int k1,int k2){
	b[++len]=(bian){p[k1],k2}; p[k1]=len;
}
void add(int k1,int k2){
	ade(k1,k2); ade(k2,k1);
}
void dfs(int k1,int k2){
	way[k1][0]=1;
	ans[k1][0]=0;
	for (int i=p[k1];i;i=b[i].next){
		int j=b[i].point;
		if (j==k2) continue;
		static int tmp1[10],tmp2[10];
		dfs(j,k1);
		for (int k=0;k<2;k++){
			tmp1[k]=way[k1][k],tmp2[k]=ans[k1][k];
			way[k1][k]=ans[k1][k]=0;
		}
		for (int a=0;a<2;a++)
			for (int c=0;c<2;c++){
				way[k1][c]=(way[k1][c]+1ll*tmp1[c]*way[j][a])%mo;
				ans[k1][c]=(ans[k1][c]+1ll*tmp1[c]*ans[j][a]+1ll*tmp2[c]*way[j][a])%mo;
			}
		for (int a=0;a<2;a++)
			for (int c=0;c<2;c++){
				if (a!=0||c!=0){
					way[k1][c]=(way[k1][c]+1ll*tmp1[c]*way[j][a])%mo;
					ans[k1][c]=(ans[k1][c]+1ll*tmp1[c]*ans[j][a]+1ll*tmp2[c]*way[j][a])%mo;
				} else {
					way[k1][1]=(way[k1][1]+1ll*tmp1[c]*way[j][a])%mo;
					ans[k1][1]=(ans[k1][1]+1ll*tmp1[c]*ans[j][a]+1ll*tmp2[c]*way[j][a]+2ll*tmp1[c]*way[j][a])%mo;
				}
			}
	}
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		int k1,k2; scanf("%d%d",&k1,&k2); add(k1,k2);
	}
	dfs(1,0);
	printf("%d\n",(ans[1][0]+ans[1][1])%mo);
}