#include <bits/stdc++.h>

using namespace std;
inline int read(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
const int maxn = 1e5 + 50;
int n , a[maxn] , vis[maxn];
vector < int > vi;
vector < vector < int > > ans;

int main( int argc , char * argv[] ){
	n = read();
	for(int i = 1 ; i <= n ; ++ i)
		a[i] = read(),vi.emplace_back( a[i] );
	sort( vi.begin() , vi.end() );
	for(int i = 1 ; i <= n ; ++ i)
		a[i] = lower_bound( vi.begin() , vi.end() , a[i] ) - vi.begin() + 1;
	for(int i = 1 ; i <= n ; ++ i)
		if( !vis[i] ){
			vector < int > final;
			for(int j = i ; !vis[j] ; j = a[j]){
				final.emplace_back( j );
				vis[j] = 1;
			}
			ans.emplace_back( final );
		}
	printf( "%d\n" , ans.size() );
	for(auto && x : ans){
		printf( "%d" , x.size() );
		for(auto && y : x) printf( " %d" , y );
		puts( "" );
	}
	return 0;
}