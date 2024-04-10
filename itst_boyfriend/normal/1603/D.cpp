#include<bits/stdc++.h>
using namespace std;

int read(){
    int a = 0; char c = getchar(); while(!isdigit(c)) c = getchar();
    while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return a;
}

#define int long long
const int _ = 1e5 + 7; int dp[_][20] , T , N , K , prm[_] , phi[_] , cprm; bool nprm[_]; vector < int > pot[_];
struct segt{
#define mid ((l + r) >> 1)
#define lch (x << 1)
#define rch (x << 1 | 1)
	int mrk[_ << 2] , mn[_ << 2];
	void upd(int x){mn[x] = min(mn[lch] , mn[rch]) + mrk[x];}
	void init(int x , int l , int r){mn[x] = 1e12; mrk[x] = 0; if(l != r){init(lch , l , mid); init(rch , mid + 1 , r);}}
	void mdf(int x , int l , int r , int t , int v){
		mn[x] = min(mn[x] , v); if(l == r) return;
		mid >= t ? mdf(lch , l , mid , t , v) : mdf(rch , mid + 1 , r , t , v);
	}
	void mdf(int x , int l , int r , int L , int R , int v){
		if(l >= L && r <= R){mrk[x] += v; mn[x] += v; return;}
		if(mid >= L) mdf(lch , l , mid , L , R , v);
		if(mid < R) mdf(rch , mid + 1 , r , L , R , v);
		upd(x);
	}
}mn;

signed main(){
	phi[1] = 1;
	for(int i = 2 ; i <= 1e5 ; ++i){
		if(!nprm[i]){prm[++cprm] = i; phi[i] = i - 1;}
		for(int j = 1 ; prm[j] * i <= 1e5 ; ++j){
			nprm[prm[j] * i] = 1; if(i % prm[j] == 0){phi[i * prm[j]] = phi[i] * prm[j]; break;}
			phi[i * prm[j]] = phi[i] * (prm[j] - 1);
		}
	}
	for(int i = 1 ; i <= 1e5 ; ++i){dp[i][0] = 1e12; for(int j = 2 * i ; j <= 1e5 ; j += i) pot[j].push_back(i);}
	for(int j = 0 ; j < 17 ; ++j){
		mn.init(1 , 0 , 1e5);
		for(int i = 1 ; i <= 1e5 ; ++i){
			mn.mdf(1 , 0 , 1e5 , i - 1 , dp[i - 1][j]);
			for(auto t : pot[i]) mn.mdf(1 , 0 , 1e5 , 0 , t - 1 , phi[i / t]);
			dp[i][j + 1] = mn.mn[1]; 
		}
	}
	for(T = read() ; T ; --T){N = read(); K = read(); printf("%lld\n" , dp[N][min(K , 17ll)] + N);}
	return 0;
}