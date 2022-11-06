#include <bits/stdc++.h>

inline int read(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
using namespace std;

const int maxn = 1e5 + 50;

int k , ans;
char s[maxn];
vector < int > sr;

int main( int argc , char * argv[] ){
	scanf( "%d%s" , & k , s );
	int n = strlen( s );
	int sum = 0;
	for(int i = 0 ; i < n ; ++ i){
		sum += s[i] - '0';
		sr.push_back( s[i] - '0' );
	}
	sort( sr.begin() , sr.end() , greater < int > () );
	while( sum < k ){
		int x = sr.back();sr.pop_back();
		sum -= x;
		sum += 9;
		++ ans;
	}
	printf( "%d\n" , ans );
	return 0;
}