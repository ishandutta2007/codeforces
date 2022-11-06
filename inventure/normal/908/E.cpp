#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
const int maxn = 1000 + 5;

int Power( int x , int y ){
	int ret = 1;
	while( y ){
		if( y & 1 ) ret = 1ll * ret * x % mod;
		y >>= 1;
		x = 1ll * x * x % mod;
	}
	return ret;
}

inline void ins( int & x , int y ){
	if( ( x += y ) >= mod ) x -= mod;
}

int Bell[maxn + 1] , C[maxn + 1][maxn + 1] , n , m;
char s[maxn];
string w[maxn];
map < string , int > ff;

void Init(){
	C[0][0] = 1;
	for(int i = 1 ; i <= maxn ; ++ i){
		C[i][0] = 1;
		for(int j = 1 ; j <= i ; ++ j)
			ins( C[i][j] , C[i - 1][j - 1] + C[i - 1][j] );
	}
}

int main( int argc , char * argv[] ){
	Init();
	scanf( "%d%d" , & m , & n );
	Bell[0] = 1;
	for(int i = 1 ; i <= 1000 ; ++ i)
		for(int j = 0 ; j < i ; ++ j)
			ins( Bell[i] , 1ll * C[i - 1][j] * Bell[j] % mod );
	for(int i = 0 ; i < n ; ++ i){
		scanf( "%s" , s );
		for(int j = 0 ; j < m ; ++ j)
			w[j].push_back( s[j] );
	}
	for(int i = 0 ; i < m ; ++ i)
		++ ff[w[i]];
	int ans = 1;
	for(auto && it : ff)
		ans = 1ll * ans * Bell[it.second] % mod;
	cout << ans << endl;
	return 0;
}