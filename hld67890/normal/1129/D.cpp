#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxn = 120000;
const int block = 360;
const int mod = 998244353;
struct node {
	int s , ex , i;
} s[400][400] , t[400][400] , t1[400] , t2[400];
int n , k;
int a[maxn];
int pre[maxn] , ext[maxn];
int inb[maxn] , le[400] , ri[400] , siz[400] , inbl[maxn] , inbr[maxn];
int del[400] , nowp[400] , num[maxn] , ans[maxn];
int dp[maxn];
bool cmp ( node x1 , node x2 ) {
	return x1.ex < x2.ex;
}
void rebuild1 ( int b ) {
	int i , j;
	j = 0;
	for ( i = 1 ; i <= siz[b] ; i++ ) {
		s[b][i].ex = 0;
		s[b][i].s = 0;
	}
	for ( i = 1 ; i <= siz[b] ; i++ ) {
		if ( i == 1 || t[b][i].ex != t[b][i-1].ex ) j++;
		s[b][j].ex = t[b][i].ex;
		s[b][j].s = (s[b][j].s + t[b][i].s) % mod;
	}
	s[b][j+1].ex = 9999999;
	nowp[b] = 0;
	ans[b] = 0;
	for ( i = 1 ; i <= j ; i++ ) {
		if ( s[b][i].ex + del[b] <= k ) {
			nowp[b] = i;
			ans[b] = (ans[b] + s[b][i].s) % mod;
		}
	}
}
void solve ( int b ) {
	int i , j;
	for ( i = le[b] ; i <= ri[b] ; i++ ) {
		t[b][i-le[b]+1].s = dp[i-1];
		t[b][i-le[b]+1].ex = num[i];
		t[b][i-le[b]+1].i = i;
	}
	sort ( t[b] + 1 , t[b] + siz[b] + 1 , cmp );
	rebuild1 ( b );
}
void rebuild ( int b , int l , int r , int x ) {
	int i , j1 , j2 , k1 , k2;
	j1 = j2 = 0;
	for ( i = 1 ; i <= siz[b] ; i++ ) {
		if ( l <= t[b][i].i && t[b][i].i <= r ) {
			t1[++j1] = t[b][i];
			t1[j1].ex += x;
		}
		else {
			t2[++j2] = t[b][i];
		}
	}
	k1 = k2 = 1;
	for ( i = 1 ; i <= siz[b] ; i++ ) {
		if ( k1 == j1 + 1 ) t[b][i] = t2[k2++];
		else {
			if ( k2 == j2 + 1 ) t[b][i] = t1[k1++];
			else {
				if ( t1[k1].ex < t2[k2].ex ) t[b][i] = t1[k1++];
				else t[b][i] = t2[k2++];
			}
		}
	}
	rebuild1 ( b );
}
void changeblock ( int i , int x ) {
	del[i] += x;
	if ( x == 1 ) {
		if ( nowp[i] > 0 && s[i][nowp[i]].ex + del[i] > k ) {
			ans[i] = (ans[i] - s[i][nowp[i]].s + mod) % mod;
			nowp[i]--;
		}
	}
	if ( x == -1 ) {
		if ( s[i][nowp[i]+1].ex + del[i] <= k ) {
			ans[i] = (ans[i] + s[i][nowp[i]+1].s) % mod;
			nowp[i]++;
		}
	}
}
void add ( int l , int r , int nowpos , int x ) {
	int i , j , lb = inb[l] , rb = inb[r];
	if ( lb == rb ) {
		if ( lb == inb[nowpos] ) {
			for ( i = l ; i <= r ; i++ ) num[i] += x;
		}
		else
			rebuild ( lb , l , r , x );
		return ;
	}
	if ( inb[l] != inb[l-1] ) {
		changeblock ( lb , x );
	}
	else {
		rebuild ( lb , l , lb * block , x );
	}
	for ( i = lb + 1 ; i <= rb - 1 ; i++ ) {
		changeblock ( i , x );
	}
	if ( rb == inb[nowpos] ) {
		for ( i = le[rb] ; i <= r ; i++ ) {
			num[i] += x;
		}
	}
	else {
		if ( inb[r] != inb[r+1] ) {
			changeblock ( rb , x );
		}
		else {
			rebuild ( rb , le[rb] , r , x );
		}
	}
}
void work () {
	int i , j;
	scanf ( "%d%d" , &n , &k );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%d" , &a[i] );
		pre[i] = ext[a[i]];
		ext[a[i]] = i;
		inb[i] = (i-1) / block + 1;
		if ( inb[i] != inb[i-1] ) le[inb[i]] = i;
		ri[inb[i]] = i;
	}
	for ( i = 1 ; i <= inb[n] ; i++ ) siz[i] = ri[i] - le[i] + 1;
	for ( i = 1 ; i <= n ; i++ ) {
		inbl[i] = le[inb[i]];
		inbr[i] = ri[inb[i]];
	}
	dp[0] = 1;
	for ( i = 1 ; i <= n ; i++ ) {
		add ( pre[i] + 1 , i , i , 1 );
		if ( pre[i] != 0 ) {
			add ( pre[pre[i]] + 1 , pre[i] , i , -1 );
		}
		//printf ( "###%d %d\n" , i , pre[i] );
		for ( j = 1 ; j < inb[i] ; j++ ) {
			//printf ( "%d %d\n" , j , ans[j] );
			/*for ( int l = 1 ; l <= siz[j] ; l++ ) {
				printf ( " %d %d %d\n" , t[j][l].ex , t[j][l].s , t[j][l].i );
			}
			printf ( "\n" );
			for ( int l = 1 ; l <= siz[j] ; l++ ) {
				printf ( " %d %d\n" , s[j][l].ex , s[j][l].s );
			}*/
			dp[i] = (dp[i] + ans[j]) % mod;
		}
		//for ( j = 1 ; j <= inb[n] ; j++ ) printf ( "%d " , del[j] );
		//printf ( "\n" );
		//for ( j = 1 ; j <= n ; j++ ) printf ( "%d " , num[j] );
		//printf ( "\n" );
		for ( j = inbl[i] ; j <= i ; j++ ) {
			if ( num[j] <= k ) dp[i] = (dp[i] + dp[j-1]) % mod;
		}
		if ( inb[i] != inb[i+1] ) {
			solve ( inb[i] );
		}
	}
	//for ( i = 1 ; i <= n ; i++ ) printf ( "%d %d\n" , a[i] , dp[i] );
	printf ( "%d\n" , dp[n] );
}
int main () {
	//freopen ( "d.in" , "r" , stdin );
	work ();
	return 0;
}