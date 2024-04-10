#include<bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;

inline int read(){
	int a = 0;
	char c = getchar();
	bool f = 0;
	while(!isdigit(c)){
		if(c == '-')
			f = 1;
		c = getchar();
	}
	while(isdigit(c)){
		a = (a << 3) + (a << 1) + (c ^ '0');
		c = getchar();
	}
	return f ? -a : a;
}

int dp[32][65][1850] , pre[32][65][1850] , M , a[35] , num[61] , ind[61] , now;
bool vis[80][80];

bool cmp(int a , int b){
	return num[a] > num[b];
}

void solve(int x){
	memset(vis , 0 , sizeof(vis));
	int i = M , j = x , k = x * (x - 1) >> 1 , cnt = 0;
	while(i){
		int t = pre[i][j][k];
		j -= t;
		k -= t * a[i];
		while(t--)
			num[++cnt] = a[i];
		--i;
	}
	for(int i = 1 ; i <= cnt ; ++i)
		ind[i] = i;
	for(now = cnt ; now ; --now){
		sort(ind + 1 , ind + now + 1 , cmp);
		for(int i = now - 1 ; now - i <= num[ind[now]] ; --i)
			vis[ind[now]][ind[i]] = 1;
		for(int i = 1 ; i < now - num[ind[now]] ; ++i){
			vis[ind[i]][ind[now]] = 1;
			--num[ind[i]];
		}
		num[ind[now]] = 0;
	}
	printf("%d\n" , x);
	for(int i = 1 ; i <= x ; ++i){
		for(int j = 1 ; j <= x ; ++j)
			putchar(vis[i][j] + '0');
		putchar('\n');
	}
	exit(0);
}

int main(){
	dp[0][0][0] = 1;
	M = read();
	srand((unsigned)time(0));
	int maxN = 0;
	for(int i = 1 ; i <= M ; ++i){
		a[i] = read();
		maxN = max(maxN , a[i]);
	}
	sort(a + 1 , a + M + 1);
	for(int i = 1 ; i <= M ; ++i)
		for(int j = 1 ; j <= 61 ; ++j)
			for(int k = max(a[i] , j * (j - 1) / 2) ; k <= 30 * j ; ++k)
				if(dp[i - 1][j - 1][k - a[i]]){
					dp[i][j][k] = 1;
					pre[i][j][k] = 1;
				}
				else
					if(dp[i][j - 1][k - a[i]]){
						dp[i][j][k] = 1;
						pre[i][j][k] = pre[i][j - 1][k - a[i]] + 1;
					}
	for(int i = maxN + 1 ; i <= 61 ; ++i)
		if(dp[M][i][i * (i - 1) >> 1])
			solve(i);
	puts("=(");
	return 0;
}