#include<bits/stdc++.h>
//This code is written by Itst
using namespace std;

const int MAXN = 1e6 + 7;
char s[MAXN] , t[MAXN] , S[MAXN];
int dp[MAXN] , ans[MAXN] , pre1[MAXN] , pre[MAXN];
int N;
namespace PAM{
	int trans[MAXN][26] , fa[MAXN] , Len[MAXN] , anc[MAXN] , diff[MAXN];
	int cnt , lst;

	void init(){Len[++cnt] = -1; fa[0] = fa[1] = 1;}

	void insert(int pos , int x){
		int p = lst;
		while(S[pos - Len[p] - 1] != S[pos]) p = fa[p];
		if(trans[p][x]){lst = trans[p][x]; return;}
		int k = ++cnt , tmp = fa[p];
		while(S[pos - Len[tmp] - 1] != S[pos]) tmp = fa[tmp];
		tmp = trans[tmp][x];
		trans[p][x] = k; Len[k] = Len[p] + 2;
		fa[k] = tmp; diff[k] = Len[k] - Len[tmp];
		anc[k] = diff[k] == diff[tmp] ? anc[tmp] : tmp;
		lst = k;
	}
}
using namespace PAM;

void output(int x){
	if(!x) return;
	output(pre[x]);
	if(pre[x] + 1 != x - 1)
		printf("%d %d\n" , pre[x] / 2 + 1 , x / 2);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	//freopen("out","w",stdout);
#endif
	memset(dp , 0x3f , sizeof(dp));
	dp[0] = 0;
	scanf("%s %s" , s + 1 , t + 1);
	N = strlen(s + 1);
	for(int i = 1 ; i <= N ; ++i)
		S[2 * i - 1] = s[i];
	for(int i = 1 ; i <= N ; ++i)
		S[2 * i] = t[i];
	init();
	for(int i = 1 ; i <= 2 * N ; ++i){
		insert(i , S[i] - 'a');
		for(int k = lst ; k ; k = anc[k]){
			ans[k] = dp[i - (Len[anc[k]] + diff[k])] + 1;
			pre1[k] = i - (Len[anc[k]] + diff[k]);
			if(anc[k] != fa[k])
				if(ans[k] > ans[fa[k]]){
					ans[k] = ans[fa[k]];
					pre1[k] = pre1[fa[k]];
				}
			if(!(i & 1))
				if(dp[i] > ans[k]){
					dp[i] = ans[k];
					pre[i] = pre1[k];
				}
		}
		if(!(i & 1) && S[i] == S[i - 1] && dp[i] > dp[i - 2]){
			dp[i] = dp[i - 2];
			pre[i] = i - 2;
		}
	}
	if(dp[N * 2] == 0x3f3f3f3f)
		puts("-1");
	else{
		printf("%d\n" , dp[N * 2]);
		output(N * 2);
	}
	return 0;
}