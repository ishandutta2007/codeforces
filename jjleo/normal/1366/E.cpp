#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

const int p = 998244353;

int n, m;
int a[maxn], b[maxn], c[maxn];
int l[maxn], r[maxn], cnt;

inline bool cmp(int x, int y){
	return a[x] ^ a[y] ? a[x] < a[y] : x > y;
}

int main(){
	scanf("%d%d", &n, &m);
	if(n < m) return printf("0"), 0;
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]), c[i] = i;
	for(int i = 1;i <= m;i++) scanf("%d", &b[i]);
	sort(c + 1, c + 1 + n, cmp);
	for(int i = 1;i <= n;i++){
		if(cnt == m) break;
		if(a[c[i]] ^ a[c[i - 1]]){
			if(a[c[i]] == b[cnt + 1]){
				if(c[i] <= r[cnt]) return printf("0"), 0;
				++cnt;
				l[cnt] = r[cnt] = c[i];
			}else if(a[c[i]] > b[cnt + 1]){
				return printf("0"), 0;
			}else{
				if(!cnt) return printf("0"), 0;
				//printf("%d %d %d %d--\n", cnt, c[i], l[cnt], r[cnt]);
				r[cnt] = max(r[cnt], c[i]);
			}
		}
	}
	if(cnt < m) return printf("0"), 0;
	int ans = 1;
	for(int i = 2;i <= m;i++) ans = 1ll * ans * (l[i] - r[i - 1]) % p;
	printf("%d", ans);
	
}