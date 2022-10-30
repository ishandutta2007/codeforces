#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int n;
ll m;
char s[maxn];
int a[maxn];

int main(){
	scanf("%d%lld%s", &n, &m, s + 1);
	m -= (1 << (s[n] - 'a')) - (1 << (s[n - 1] - 'a'));
	for(int i = 1;i <= n - 2;i++){
		a[s[i] - 'a']++;
		m -= 1 << (s[i] - 'a');
	}
	if((m & 1) || m > 0) return printf("No"), 0;
	m = -m / 2;
	for(int i = 25;~i;i--){
		m -= min(m / (1 << i), 1ll * a[i]) * (1 << i);
	}
	printf(m ? "No" : "Yes");
}