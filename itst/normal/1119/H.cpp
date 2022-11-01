#include<bits/stdc++.h>
//This code is written by Itst
using namespace std;

inline int read(){
	int a = 0;
	char c = getchar();
	while(!isdigit(c))
		c = getchar();
	if(c == EOF)
		exit(0);
	while(isdigit(c)){
		a = a * 10 + c - 48;
		c = getchar();
	}
	return a;
}

#define int long long
#define ll long long
const int MAXN = (1 << 17) + 7 , MOD = 998244353;
int num[MAXN][3] , arr[3][MAXN] , ans[MAXN] , tmp[MAXN];
int N , K;
ll A , B , C;

void FWT(int *arr , int tp){
	for(int i = 0 ; i < K ; ++i)
		for(int j = 0 ; j < 1 << K ; j += 1 << (i + 1))
			for(int k = 0 ; k < 1 << i ; ++k){
				int x = arr[j + k] , y = arr[(1 << i) + j + k];
				arr[j + k] = x + y >= MOD ? x + y - MOD : x + y;
				arr[(1 << i) + j + k] = x - y < 0 ? x - y + MOD : x - y;
				if(tp == -1){
					if(arr[j + k] & 1) arr[j + k] += MOD;
					arr[j + k] >>= 1;
					if(arr[(1 << i) + j + k] & 1) arr[(1 << i) + j + k] += MOD;
					arr[(1 << i) + j + k] >>= 1;
				}
			}
}

ll poww(ll a , ll b){
	a = a % MOD + MOD;
	b = (b % MOD + MOD) % MOD;
	int times = 1;
	while(b){
		if(b & 1) times = times * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return times;
}

int now[4];
ll inv4;
int get(){
	return poww(A + B + C , (now[0] + now[1] + now[2] + now[3]) % MOD * inv4) * poww(A + B - C , (now[0] + now[1] - now[2] - now[3]) % MOD * inv4) % MOD * poww(A - B + C , (now[0] - now[1] + now[2] - now[3]) % MOD * inv4) % MOD * poww(A - B - C , (now[0] - now[1] - now[2] + now[3]) % MOD * inv4) % MOD;
}

signed main(){
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	//freopen("out","w",stdout);
#endif
	N = read(); K = read(); A = read(); B = read(); C = read();
	int all = 0;
	inv4 = poww(4 , MOD - 2);
	for(int i = 1 ; i <= N ; ++i){
		num[i][0] = read();
		num[i][1] = read() ^ num[i][0];
		num[i][2] = read() ^ num[i][0];
		all ^= num[i][0];
		++arr[0][num[i][1]];
		++arr[1][num[i][2]];
		++arr[2][num[i][1] ^ num[i][2]];
		num[i][0] = 0;
	}
	FWT(arr[0] , 1); FWT(arr[1] , 1); FWT(arr[2] , 1);
	now[0] = N;
	for(int i = 0 ; i < 1 << K ; ++i){
		for(int j = 1 ; j <= 3 ; ++j)
			now[j] = arr[j - 1][i];
		ans[i] = get();
	}
	FWT(ans , -1);
	for(int i = 0 ; i < 1 << K ; ++i)
		printf("%d " , ans[i ^ all]);
	return 0;
}