#include <bits/stdc++.h>
 
using namespace std;
 
const int maxn = 70000 + 50;
const int inf = 0x3f3f3f3f;
using ull = unsigned long long;
 
template < typename T >
void Read( T & x ){
	x=0;
	char ch;
	for( ch = getchar() ; ch < '0' || ch > '9' ; ch = getchar() );
	for( ; ch <= '9' && ch >= '0' ; ch = getchar() ) x = x * 10 + ch - '0';
}

unordered_map < int , int > f[12];
char s[maxn][12];

int main( int argc , char * argv[] ){
	int n;
	Read( n );
	for(int i = 0 ; i < n ; ++ i){
		scanf( "%s" , s[i] );
		for(int j = 0 ; j < 9 ; ++ j){
			int ret = 0;
			for(int k = j ; k < 9 ; ++ k){
				ret = ret * 10 + s[i][k] - '0';
				++ f[k - j + 1][ret];
			}
		}
	}
	for(int i = 0 ; i < n ; ++ i){
		string w;
		for(int j = 0 ; j < 9 ; ++ j){
			int ret = 0;
			for(int k = j ; k < 9 ; ++ k){
				ret = ret * 10 + s[i][k] - '0';
				-- f[k - j + 1][ret];
			}
		}
		for(int j = 0 ; j < 9 ; ++ j){
			int ret = 0;
			string rr;
			for(int k = j ; k < 9 ; ++ k){
				ret = ret * 10 + s[i][k] - '0';
				rr.push_back( s[i][k] );
				if( f[k - j + 1][ret] == 0 ){
					if( w.size() == 0 || rr.size() < w.size() ) w = rr;
				}
			}
		}
		for(int j = 0 ; j < 9 ; ++ j){
			int ret = 0;
			for(int k = j ; k < 9 ; ++ k){
				ret = ret * 10 + s[i][k] - '0';
				++ f[k - j + 1][ret];
			}
		}
		printf( "%s\n" , w.c_str() );
	}
	return 0;
}