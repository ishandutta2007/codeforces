#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 2010 , MAXM = 200010 , MOD = 1e9 + 7;
struct node{
	int x , y;
}now[MAXN];
int H , W , N;
long long dp[2010] , jc[MAXM] = {1} , jcny[MAXM] = {1};

inline int poww(long long a , int b){
	int times = 1;
	while(b){
		if(b & 1)
			times = times * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return times;
}

inline bool cmp(node a , node b){
	return a.x < b.x || a.x == b.x && a.y < b.y;
}

int main(){
	cin >> H >> W >> N;
	for(int i = 1 ; i <= N ; i++)
		cin >> now[i].x >> now[i].y;
	sort(now + 1 , now + N + 1 , cmp);
	for(int i = 1 ; i <= 2e5 ; i++){
		jc[i] = jc[i - 1] * i % MOD;
		jcny[i] = poww(jc[i] , MOD - 2);
	}
	now[0].x = now[0].y = 1;
	now[N + 1].x = H;
	now[N + 1].y = W;
	dp[0] = -1;
	for(int i = 1 ; i <= N + 1 ; i++)
		for(int j = i - 1 ; j >= 0 ; j--)
			if(now[i].y >= now[j].y)
				dp[i] = ((dp[i] - dp[j] * jc[now[i].y - now[j].y + now[i].x - now[j].x] % MOD * jcny[now[i].y - now[j].y] % MOD * jcny[now[i].x - now[j].x]) % MOD + MOD) % MOD;
	cout << dp[N + 1];
	return 0;
}