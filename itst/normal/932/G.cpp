#include<bits/stdc++.h>
//This code is written by Itst
using namespace std;

const int MAXN = 1e6 + 7 , MOD = 1e9 + 7;
char s[MAXN] , t[MAXN];
int N , dp[MAXN] , ans[MAXN];
namespace PAM{
	int trans[MAXN][26] , fa[MAXN] , Len[MAXN] , diff[MAXN] , anc[MAXN];
	int cnt , lst;
	
	void init(){
		Len[++cnt] = -1;
		fa[0] = fa[1] = 1;
	}
	
	void insert(int l , int x){
		int p = lst;
		while(s[l - Len[p] - 1] != s[l]) p = fa[p];
		if(trans[p][x]){lst = trans[p][x]; return;}
		int k = ++cnt , tmp = fa[p];
		Len[k] = Len[p] + 2;
		while(s[l - Len[tmp] - 1] != s[l]) tmp = fa[tmp];
		tmp = trans[tmp][x];
		fa[k] = tmp; trans[p][x] = k;
		diff[k] = Len[k] - Len[tmp];
		anc[k] = diff[k] == diff[tmp] ? anc[tmp] : tmp;
		lst = k;
	}
}
using namespace PAM;

int main(){
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	//freopen("out","w",stdout);
#endif
	scanf("%s" , t + 1);
	N = strlen(t + 1);
	if(N & 1) return puts("0") , 0;
	for(int i = 1 ; i <= N ; ++i)
		if(i <= N / 2)
			s[2 * i - 1] = t[i];
		else
			s[N - 2 * (i - N / 2 - 1)] = t[i];
	dp[0] = 1;
	init();
	for(int i = 1 ; i <= N ; ++i){
		insert(i , s[i] - 'a');
		for(int k = lst ; k ; k = anc[k]){
			ans[k] = dp[i - (Len[anc[k]] + diff[k])];
			if(anc[k] != fa[k])
				ans[k] = (ans[k] + ans[fa[k]]) % MOD;
			if(!(i & 1))
				dp[i] = (dp[i] + ans[k]) % MOD;
		}
	}
	cout << dp[N];
	return 0;
}