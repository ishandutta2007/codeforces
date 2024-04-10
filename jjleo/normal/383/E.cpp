#include <bits/stdc++.h>

using namespace std;

int n;
int f[1 << 25];
char s[233];
int ans;

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++){
		scanf("%s", s + 1);
		int x = 0;
		for(int j = 1;j <= 3;j++){
			x |= 1 << (s[j] - 'a');
		}
		for(int j = x;j;j = (j - 1) & x){
			if(__builtin_popcount(j) & 1) f[j]++;
			else f[j]--;
		}
	}
	for(int i=0;i<24;i++)
		for(int j=0;j<(1<<24);j++)
			if(j&(1<<i))f[j]+=f[j^(1<<i)];
	for(int i=0;i<(1<<24);i++)
		ans=ans^(f[i]*f[i]);
	printf("%d", ans);
}