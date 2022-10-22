/*
 * Author: Kewth

 * Date:
  2020.07.22

 * Solution:
 *  DP PAM border

   T = S[1] S[n] S[2] S[n - 2] ...  T  T 


   DP f[i]  i  PAM 
fail  border 

   g[u]  u  fail  f  g


  blablabla  g 
 g 

  -----UPDATE: -----

   i  link  S(i)  S(i) 
u != top[u]  u S(i - dt[u])  fail[u] 

   i - dt[u]  fail  fail[u]  fail[u] 
 fail[u]  fail[u]  v  top[v] = v 
 dt[v] != dt[fail[u]]  i - dt[u] 

   dt[fail[u]] = dt[v]  v = u  i  u 
 x  dt[x] = dt[u]  u  S(i) 

 * Digression:

 * CopyRight:
          
            
          
              
             
          
            
  
        
 */

#include <cstdio>
#include <cstring>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

const int maxn = 1000005, maxc = 26, mod = 1000000007;
char s[maxn], t[maxn];
int ch[maxn][maxc], fail[maxn], len[maxn], dt[maxn], top[maxn], cp = 2;
int pos[maxn];
ll f[maxn], g[maxn];

int main () {
	scanf("%s", s + 1);
	int n = int(strlen(s + 1));
	for (int i = 1; i <= n / 2; i ++) {
		t[i * 2 - 1] = s[i];
		t[n - i * 2 + 2] = s[n / 2 + i];
	}

	len[1] = -1;
	len[2] = 0;
	fail[2] = 1;
	/* dt[2] = 1; */
	dt[2] = -1; //  2 
	top[2] = 2;

	pos[0] = 1;
	for (int i = 1; i <= n; i ++) {
		int pre = pos[i - 1], c = t[i] - 'a';
		while (t[i - len[pre] - 1] != t[i]) pre = fail[pre];
		int &now = ch[pre][c];
		if (!now) {
			now = ++ cp;
			len[now] = len[pre] + 2;
			if (pre == 1) fail[now] = 2;
			else {
				pre = fail[pre];
				while (t[i - len[pre] - 1] != t[i]) pre = fail[pre];
				fail[now] = ch[pre][c];
			}
			dt[now] = len[now] - len[fail[now]];
			top[now] = dt[now] == dt[fail[now]] ? top[fail[now]] : now;
		}
		pos[i] = now;
	}

	f[0] = 1;
	for (int i = 1; i <= n; i ++) {
		ll sum = 0;
		for (int x = pos[i], y; x > 2; x = fail[y]) {
			y = top[x];
			g[x] = f[i - len[y]];
			//  g[fail[x]]  i - dt[x] 
			if (y != x) g[x] += g[fail[x]];
			sum += g[x];
		}
		if (!(i & 1)) f[i] = sum % mod;
		/* for (int j = 3; j <= cp; j ++) debug(" %lld", g[j]); debug("\n"); */
	}

	printf("%lld\n", f[n]);
	/* debug("%s\n", t + 1); */
}