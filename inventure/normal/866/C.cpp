#include <bits/stdc++.h>

using namespace std;

const int maxn = 50 + 2;

int N , R , F[maxn] , S[maxn] , P[maxn];
double dp[maxn][maxn * 105];

double Check( double limit ){
	for(int i = 0 ; i <= R ; ++ i) dp[N + 1][i] = 0;
	for(int j = R ; j >= 0 ; -- j)
		for(int i = N ; i >= 1 ; -- i){
			double prob = ( double )P[i] / 100.;
			dp[i][j] = 0;
			if( j + F[i] > R ) dp[i][j] += ( limit + F[i] ) * prob;
			else dp[i][j] += ( min( limit , dp[i + 1][j + F[i]] ) + F[i] ) * prob;
			if( j + S[i] > R ) dp[i][j] += ( limit + S[i] ) * (1. - prob);
			else dp[i][j] += ( min( limit , dp[i + 1][j + S[i]] ) + S[i] ) * (1. - prob);
		}
	return dp[1][0] <= limit;
}

int main( int argc , char * argv[] ){
	scanf( "%d%d" , & N , & R );
	for(int i = 1 ; i <= N ; ++ i) scanf( "%d%d%d" , F + i , S + i , P + i );
	double l = 0 , r = 1e10;
	for(int step = 1 ; step <= 150 ; ++ step){
		double mid = ( l + r ) / 2.;
		if( Check( mid ) ) r = mid;
		else l = mid;
	}
	printf( "%.10f\n" , l );
	return 0;
}