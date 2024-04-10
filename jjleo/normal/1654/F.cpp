#include <bits/stdc++.h>
#define maxn 300086

using namespace std;

int n;
char s[maxn];
int rk[maxn], sa[maxn], j, Rk[maxn];

inline bool cmp(int x, int y){
	return make_pair(rk[x], rk[x ^ (1 << (j - 1))]) < make_pair(rk[y], rk[y ^ (1 << (j - 1))]);
}

int main(){
	scanf("%d%s", &n, s);
	for(int i = 0;i < (1 << n);i++) rk[i] = s[i];
	for(j = 1;j <= n;j++){
		for(int i = 0;i < (1 << n);i++) sa[i] = i;
		sort(sa, sa + (1 << n), cmp);
		int cnt = 0;
		for(int i = 0;i < (1 << n);i++){
			if(i && !cmp(sa[i - 1], sa[i])) Rk[sa[i]] = Rk[sa[i - 1]];
			else Rk[sa[i]] = ++cnt;
		}
		for(int i = 0;i < (1 << n);i++) rk[i] = Rk[i];
	}
	for(int i = 0;i < (1 << n);i++) printf("%c", s[i ^ sa[0]]);
}