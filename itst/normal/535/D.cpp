#include<bits/stdc++.h>
//this code is written by Itst
using namespace std;

const int _ = 1e6 + 7 , MOD = 1e9 + 7;
int z[_] , vis[_] , N , P;
char s[_];

int main(){
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	//freopen("out","w",stdout);
#endif
	scanf("%d %d %s" , &N , &P , s + 1);
	int l = 1 , r = 1 , L = strlen(s + 1);
	for(int i = 2 ; i <= L ; ++i)
		if(r < i){
			l = r = i;
			while(r <= L && s[r - l + 1] == s[r]) ++r;
			z[i] = (--r) - l + 1;
		}
		else{
			int len = z[i - l + 1];
			if(i + len - 1 < r) z[i] = len;
			else{
				l = i;
				while(r <= L && s[r - l + 1] == s[r]) ++r;
				z[i] = (--r) - l + 1;
			}
		}
	int pre = -1e9 , cur;
	for(int i = 1 ; i <= P ; ++i){
		scanf("%d" , &cur);
		if(cur - pre < L && z[cur - pre + 1] != L - (cur - pre)){
			puts("0"); return 0;
		}
		++vis[cur]; --vis[cur + L]; pre = cur;
	}
	int ans = 1;
	for(int i = 1 ; i <= N ; ++i)
		if(!(vis[i] += vis[i - 1])) ans = ans * 26ll % MOD;
	cout << ans;
	return 0;
}