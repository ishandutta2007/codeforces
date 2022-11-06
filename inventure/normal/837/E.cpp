#include <bits/stdc++.h>

using namespace std;

set < long long > prime , ssss;

void PreDeal( long long x ){
	long long i;
	for(i = 1 ; i * i < x ; ++ i)
		if( x % i == 0 ){
			prime.insert( i );
			prime.insert( x / i );
		}
	if( 1LL * i * i == x ) prime.insert( i );
}

long long Solve( long long a , long long b ){
	long long ans = 0 , gc = __gcd( a , b );
	while( b ){
		if( b % a == 0 ){
			ans += b / a;
			return ans;
		}
		++ ans;
		b = b - __gcd( a , b );
	}
	return ans;
}


int main( int argc , char * argv[] ){
	long long a , b;
	cin >> a >> b;
	if ( a == 1 ){
		cout << b << endl;
		return 0;
	}
	PreDeal( a );
	long long ans = 0;
	while( 1 ){
		long long gcd = __gcd( b , a );
		if( gcd == a || prime.empty() ){
			ans += b / gcd;
			break;
		}
		long long ff = -1 , g = 1;
		for(auto && x : prime){
			if( x % gcd ) continue;
			long long z = ( b / x ) * x;
			if( z > ff &&  (b - z) % gcd == 0 )
				ff = z , g = x;
		}
		if( ff == -1 ){
			prime.clear();
			continue;
		}
		ans += (b - ff) / gcd;
		//cout << "b is " << b << " " << ff << " gcd is " << gcd << " select is " << g << endl;
		prime.erase( g );
		b = ff;
	}
	cout << ans << endl;
	return 0;
}