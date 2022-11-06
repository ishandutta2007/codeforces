#include <bits/stdc++.h>

inline int read(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
using namespace std;

long long n , m ;

bool check( long long time ){
	long long d = time - m;
	long double v = ((long double)(d) * (d-1)) / 2 + time;
	return v >= n;
}

int main( int argc , char * argv[] ){
	cin >> n >> m;
	if( m >= n ){
		cout << n << endl;
		return 0;
	}
	long long l = m , r = n;
	while( l < r ){
		long long mid = l + r >> 1;
		if( check( mid ) )
			r = mid;
		else
			l = mid + 1;
	}
	cout << l << endl;
	return 0;
}