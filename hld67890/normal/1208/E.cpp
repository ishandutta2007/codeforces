#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

//long long
const long long maxn = 1200000;
struct heap {
	priority_queue < long long > p , q;
	void push ( long long x ) {
		p.push ( x );
	}
	void pop ( long long x ) {
		q.push ( x );
	}
	long long top () {
		while ( q.size () && p.top () == q.top () ) {
			p.pop ();
			q.pop ();
		}
		return p.top ();
	}
	long long size () {
		return p.size() - q.size();
	}
} h;
long long n , w;
long long a[maxn];
long long ans[maxn] , b[maxn];
void work () {
	long long i , j , k , l , pp , tmp;
	scanf ( "%I64d%I64d" , &n , &w );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%I64d" , &l );
		for ( j = 1 ; j <= l ; j++ ) {
			scanf ( "%I64d" , &a[j] );
		}
		if ( l * 2 >= w - 5 ) {
			k = w - l + 2; pp = 1;
			for ( j = 1 ; j <= w ; j++ ) {
				if ( j <= l ) h.push ( a[j] );
				if ( j == k ) {
					h.pop ( a[pp] );
					k++; pp++; 
				}
				//check neg
				tmp = h.top();
				if ( j > l || j <= w - l ) tmp = max ( tmp , 0ll );
				ans[j] += tmp;
			}
		}
		else {
			for ( j = 1 ; j <= l ; j++ ) {
				h.push(a[j]);
				tmp = h.top();
				tmp = max ( tmp , 0ll );
				ans[j] += tmp;
			}
			b[l+1] += max(h.top(),0ll);
			b[w-l+1] -= max(h.top(),0ll);
			for ( j = w-l+1 ; j <= w ; j++ ) {
				ans[j] += max ( h.top() , 0ll );
				h.pop(a[j-(w-l)]);
			}
		}
		while ( h.size () ) h.pop(h.top()); 
	}
	for ( i = 2 ; i <= w ; i++ ) {
		b[i] += b[i-1];
	}
	for ( i = 1 ; i <= w ; i++ ) {
		printf ( "%I64d%c" , ans[i] + b[i] , i==w?'\n':' ' );
	}
}
int main () {
	work ();
	return 0;
}