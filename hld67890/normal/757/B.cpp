#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxn = 120000;
int n;
int num[maxn];
int ans;
void work () {
	int i , j , a , sum;
	scanf ( "%d" , &n );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%d" , &a );
		num[a]++;
	}
	ans = 1;
	for ( i = 2 ; i <= 100000 ; i++ ) {
		sum = 0;
		for ( j = i ; j <= 100000 ; j += i ) sum += num[j];
		ans = max ( ans , sum );
	}
	printf ( "%d\n" , ans );
}
int main () {
	work ();
	return 0;
}