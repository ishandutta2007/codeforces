#include <stdio.h>
#include <algorithm>

using namespace std;

//long long
const long long maxn = 310000;
long long tot , m;
long long del[maxn] , num[maxn] , sum[maxn];
long long top;
long long gb , gs;
long long get ( long long i , long long kth ) {
	return del[i] + kth * gs + gb;
}
long long getx ( long long i , long long j ) {
	return (long long)(del[i]-del[j]-1) / (sum[j]-num[j]+1-(sum[i]-num[i]+1)) + 1;
}
bool check () {
	if ( getx ( top - 2 , top - 1 ) <= getx ( top - 2 , top ) ) return true;
	return false;
}
void work () {
	long long i , k , op , b , s;
	scanf ( "%I64d%I64d" , &tot , &m );
	top = 1;
	del[1] = 0;
	num[1] = tot;
	sum[1] = tot;
	for ( i = 1 ; i <= m ; i++ ) {
		scanf ( "%I64d" , &op );
		if ( op == 1 ) {
			scanf ( "%I64d" , &k );
			top = 1;
			del[1] = 0;
			tot += k;
			num[1] = tot;
			sum[1] = tot;
			gb = gs = 0;
		}
		if ( op == 2 ) {
			scanf ( "%I64d" , &k );
			top++;
			del[top] = -gb - (tot+1) * gs;
			tot += k;
			num[top] = k;
			sum[top] = sum[top-1] + k;
			// printf ( "@%I64d %I64d %I64d %I64d %I64d %I64d %I64d\n" , top , del[1] , num[1] , del[2] , num[2] , del[3] , num[3] );
			//printf ( "%I64d\n" , getx ( top-1 , top) );
			if ( get ( top - 1 , sum[top-1]-num[top-1]+1 ) == 0 ) {
				top--;
				num[top] += k;
				sum[top] += k;
			}
			//printf ( "%I64d %I64d %I64d %I64d\n" , gb , gs , del[top] , get ( top-1 , tot - num[top]-num[top-1]+ 1) );
		}
		if ( op == 3 ) {
			scanf ( "%I64d%I64d" , &b , &s );
			gb += b - s;
			gs += s;
		}
		while ( top > 2 && check () ) {
			num[top-2] += num[top-1];
			sum[top-2] += num[top-1];
			num[top-1] = num[top];
			sum[top-1] = sum[top];
			del[top-1] = del[top];
			top--;
		}
		while ( top > 1 && getx ( top - 1 , top ) <= gs ) {
			num[top-1] += num[top];
			sum[top-1] += num[top];
			top--;
		}
		//printf ( "gs%I64d gb%I64d\n" , gs , gb );
		//printf ( "%I64d\n" , get ( 1 , 2 ) );
		//printf ( "@%I64d d%I64d n%I64d d%I64d n%I64d d%I64d n%I64d\n" , top , del[1] , num[1] , del[2] , num[2] , del[3] , num[3] );
		printf ( "%I64d %I64d\n" , sum[top] - num[top] + 1 , get ( top , sum[top] - num[top] + 1 ) );
	}
}
int main () {
	work ();
	return 0;
}