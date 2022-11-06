#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstring>

using namespace std;

const int maxn = 5000 + 15;

int n;
char S[maxn];

int main( int argc , char * argv[] ){
	scanf( "%s" , S + 1 );
	n = strlen( S + 1 );
	int ans = 0;
	for(int i = 1 ; i <= n ; ++ i){
		int sum = 0 , s = 0;
		for(int j = i ; j <= n ; ++ j){
			if( S[j] == '(' ) ++ sum;
			else if( S[j] == ')' ){
				if( sum ) -- sum;
				else if( s ) -- s , ++ sum;
				else break;
			}else if( S[j] == '?' ){
				if( sum ) -- sum , ++ s;
				else ++ sum;
			}
			if( sum == 0 )
				++ ans;
		}
	}
	printf( "%d\n" , ans );
	return 0;
}