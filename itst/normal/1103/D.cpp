#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#include<map>
//This code is written by Itst
using namespace std;

#define int long long
inline int read(){
	int a = 0;
	char c = getchar();
	while(!isdigit(c))
		c = getchar();
	while(isdigit(c)){
		a = a * 10 + c - 48;
		c = getchar();
	}
	return a;
}

inline int gcd(int a , int b){
	int r = a % b;
	while(r){a = b; b = r; r = a % b;}
	return b;
}

#define st first
#define nd second
const int MAXN = 1e6 + 7;
struct zt{
	int num , w;
	bool operator <(const zt a)const{return w < a.w;}
}now[MAXN];
vector < int > in;
int N , K , allGcd , dp[12][1 << 11] , calc[1 << 11];
map < int , vector < int > > lsh;

signed main(){
	N = read(); K = read();
	for(int i = 1 ; i <= N ; ++i){
		now[i].num = read();
		allGcd = gcd(allGcd , now[i].num);
	}
	for(int i = 1 ; i <= N ; ++i) now[i].w = read();
	if(allGcd == 1) return puts("0") , 0;
	for(int i = 2 ; i <= 1e6 && 1ll * i * i <= allGcd ; ++i)
		if(allGcd % i == 0){
			in.push_back(i);
			while(allGcd % i == 0) allGcd /= i;
		}
	if(allGcd - 1) in.push_back(allGcd);
	int M = in.size();
	for(int i = 1 ; i <= N ; ++i){
		int z = 1;
		for(auto j : in)
			while(now[i].num % j == 0){
				now[i].num /= j;
				z *= j;
			}
		lsh[z].push_back(now[i].w);
	}
	memset(dp , 2 , sizeof(dp));
	dp[0][0] = 0;
	for(auto t : lsh){
		int x = t.st;
		sort(t.nd.begin() , t.nd.end());
		if(t.nd.size() > M) t.nd.resize(M);
		vector < int > num;
		for(int i = 0 ; i < 1 << M ; ++i){
			int times = 1 , p = x;
			for(int j = 0 ; j < M ; ++j)
				if(i & (1 << j))
					while(p % in[j] == 0){
						p /= in[j];
						times *= in[j];
					}
			num.push_back(times);
		}
		for(auto p : t.nd){
			bool flg = 0;
			for(int i = M - 1 ; i >= 0 ; --i)
				for(int j = 0 ; j < 1 << M ; ++j)
					if(dp[i][j] <= 1e12){
						int all = (1 << M) - 1 - j;
						for(int k = all ; k ; k = (k - 1) & all)
							if(num[k] <= K)
								if(dp[i + 1][j | k] > dp[i][j] + p){
									dp[i + 1][j | k] = dp[i][j] + p;
									flg = 1;
								}
					}
			if(!flg) break;
		}
	}
	int minN = 1e18;
	for(int i = 1 ; i <= M ; ++i)
		minN = min(minN , dp[i][(1 << M) - 1] * i);
	if(minN > 1e12) cout << -1;
	else cout << minN;
	return 0;
}