#include <bits/stdc++.h>

using namespace std;

namespace SuffixArray{
	const static int maxn = 2e5 + 50;
	int sa[maxn],c[maxn],sq[maxn],sw[maxn],rank[maxn],height[maxn],dp[maxn][20],Len[maxn];
	void Build(char *s,int n,int m){
		++ n;
		int * x = sq , *y = sw , p = 1 ;
		for(int i = 0 ; i < m ; ++ i) c[i] = 0;
		for(int i = 0 ; i < n ; ++ i) c[x[i]=s[i]]++;
		for(int i = 1 ; i < m ; ++ i) c[i] += c[i - 1];
		for(int i = n - 1 ; i >= 0 ; -- i) sa[--c[x[i]]] = i;
		for(int k = 1 ; p < n ; k <<= 1){
			p = 0;
			for(int i = n - k ; i < n ; ++ i) y[p ++] = i;
			for(int i = 0 ; i < n ; ++ i) if( sa[i] >= k ) y[p ++] = sa[i] - k;
			for(int i = 0 ; i < m ; ++ i) c[i] = 0;
			for(int i = 0 ; i < n ; ++ i) c[x[y[i]]]++;
			for(int i = 1 ; i < m ; ++ i) c[i] += c[i-1];
			for(int i = n - 1 ; i >= 0 ; -- i) sa[--c[x[y[i]]]]=y[i];
			swap( x , y ) ; p = 1 , x[sa[0]] = 0;
	        for(int i = 1 ; i < n ; ++ i) x[sa[i]] = y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k] ? p - 1 : p++;
			m = p;
		}
		-- n;
		for(int i = 0 ; i < n ; ++ i) sa[i] = sa[i + 1] , rank[sa[i]] = i;
		for(int i = 0 , k = 0 ; i < n ; ++ i ){
			if( !rank[i] ) continue;
			int j = sa[rank[i] - 1];
			if( k ) -- k;
			while( s[i + k] == s[j + k] ) ++ k;
			height[rank[i]] = k;
		}
		Len[0] = -1;
		for(int i = 0 ; i < n ; ++ i){
			dp[i][0] = height[i];
			Len[i + 1] = Len[(i + 1) >> 1] + 1;
		}
		for(int j = 1 ; j < 20 ; ++ j)
			for(int i = 0 ; i + (1 << j) - 1 < n ; ++ i)
				dp[i][j] = min( dp[i][j - 1] , dp[i + (1 << j - 1)][j - 1] );
	}

	int query( int l , int r ){
		l = rank[l] , r = rank[r];
		if( l > r )
			swap( l , r );
		++ l;
		int z = Len[r - l + 1];
		return min( dp[l][z] , dp[r - (1 << z) + 1][z] );
	}
};

const int maxn = 1e5 + 50;
char s[maxn] , t[maxn] , base[maxn << 1];
int n , m , X , dp[maxn][32];


int main( int argc , char * argv[] ){
	scanf( "%d%s%d%s%d" , & n , s , & m , t , & X );
	for(int i = 0 ; i < n ; ++ i) base[i] = s[i];
	base[n]='#';
	for(int i = 0 ; i < m ; ++ i) base[i + n + 1] = t[i];
	SuffixArray::Build( base , n + m + 1 , 300 );
	int ok = 0;
	for(int i = 0 ; i < n ; ++ i)
		for(int j = 0 ; j <= X ; ++ j){
			if( dp[i][j] == m ){
				ok = 1;
				break;
			}
			dp[i + 1][j] = max( dp[i + 1][j] , dp[i][j] );
			int z = SuffixArray::query( i , dp[i][j] + n + 1 );
			if( z )
				dp[i + z][j + 1] = max( dp[i + z][j + 1] , dp[i][j] + z );
		}
	for(int j = 0 ; j <= X ; ++ j)
		ok |= (dp[n][j] == m);
	if( ok )
		puts( "YES" );
	else
		puts( "NO" );
	return 0;
}