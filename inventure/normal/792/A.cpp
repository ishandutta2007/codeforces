#include <bits/stdc++.h>
using namespace std;
inline int read(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
const int maxn = 2e5 + 50;

int a[maxn] , n ;
vector < pair < int , int > > f;

long long cal( int x ){
	return 1LL * x * (x - 1) / 2LL;
}

int main( int argc , char * argv[] ){
	//freopen( "in.txt" , "r" , stdin );
	long long ans = 0;
	n = read();
	for(int i = 1 ; i <= n ; ++ i)
		a[i] = read();
	sort( a + 1 , a + n + 1 );
	int Mi = 2e9 + 2;
	for(int i = 2 ; i <= n ; ++ i)
		Mi = min( Mi , a[i] - a[i - 1] );
	if( Mi == 0 ){
		for(int i = 1 ; i <= n ; ){
			int j = i;
			while( j <= n && a[j] == a[i] )
				++ j;
			ans += cal( j - i + 1 );
			i = j;
		}
	}else{
		for(int i = 2 ; i <= n ; ++ i)
			if( a[i] - a[i - 1] == Mi )
				++ ans;
	}
	cout << Mi << " " << ans << endl;
	return 0;
}