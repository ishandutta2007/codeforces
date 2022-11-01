#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <stack>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#define pb push_back
#define mp make_pair
#define INF 9999999
#define LINF 9999999999999999
#define uint unsigned int
#define msn(a,v) memset(a,v,sizeof(a))
#define ms(a) msn(a,0)
#define NONE -1
#define ll long long
#define ull unsigned ll
#define uchar unsigned char
#define sint short int
#define usint unsigned sint
#define lb lower_bound
#define ub upper_bound
using namespace std;
#define MAXN 400100

/*

d = 6
   012345678901
#1 aabaabbaabaa		3,8  2,7  2,8
#2 aabaabaabaa      3,8  2,7  2,8

*/

char s[MAXN];
int d , n;

bool findsol = 0;
char nows[MAXN];

#define HASH 123
ull quan[MAXN] , hash1[MAXN] , hash2[MAXN] ;	//hash1: <=		hash2:	=>
/*       !hash+1         */
void init(){
	quan[0] = 1;
	for( int i = 1; i <= n ; i++ )
		quan[i] = quan[i-1] * HASH;
	ms(hash1); ms(hash2);
}
bool ok( int pos , int dis ){
	pos++;
	int begin = pos - dis + 1;
	if( begin < 1 ) return 1;
	if( ( hash2[pos] - hash2[begin-1] * quan[dis] ) * quan[begin-1] 
		==
		hash1[pos] - hash1[begin-1] )
		return 0;
	return 1;
}

void dfs( int pos , bool chg ){
	//if( pos == 3 ){
	//	for( int i = 0; i < 3 ; i++ )
	//		putchar( nows[i] );
	//	putchar('\n');
	//}
	if( pos == n ){
		findsol = 1;
		for( int i = 0; i < n ; i++ )
			putchar( nows[i] );
		putchar('\n');
		return;
	}
	if( chg ){
		for( char i = 'a' ; i <= 'z' ; i++ ){
			if( findsol ) return;
			hash1[pos+1] = hash1[pos] + (i-'a') * quan[pos];
        	hash2[pos+1] = hash2[pos] * HASH + (i-'a');
        	if( ok( pos , d )  &&  ok( pos , d+1 ) ){
        		nows[pos] = i;
				dfs( pos+1 , 1 );
				nows[pos] = s[pos];
			}
		}
	}else{
		for( char i = s[pos] ; i <= 'z' ; i++ ){
			if( findsol ) return;
			hash1[pos+1] = hash1[pos] + (i-'a') * quan[pos];
        	hash2[pos+1] = hash2[pos] * HASH + (i-'a');
        	if( ok( pos , d )  &&  ok( pos , d+1 ) ){
				nows[pos] = i;
				dfs( pos+1 , !(i==s[pos]) );
				nows[pos] = s[pos];
			}
		}
	}
}

int main(){
//	freopen("1.txt","r",stdin);
	
	scanf("%d",&d);
	scanf("%s",&s);
	n = strlen(s);
	
	int i;
	for( i = n-1 ; i >= 0 ; i-- ){
		if( s[i] == 'z' ){
			s[i] = 'a';
		}else{
			break;
		}
	}
	
	if( i < 0 ){
		printf("Impossible\n");
		return 0;
	}
	
	s[i]++; init();
	dfs( 0 , 0 );
	if( !findsol )
		printf("Impossible\n");
	return 0;
}