#include <bits/stdc++.h>
using namespace std;
inline int read(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
const int maxn = 2e5 + 50;

long long n;
int q , deep = 0;
string s;

long long trans( long long u ){
	long long id = 1;
	for(int i = deep - 1 ; i >= 0 ; -- i){
		long long lft = 1LL << i;
		if( u == lft )
			return id;
		if( u > lft )
			u -= lft , id = (id << 1LL) | 1;
		else
			id <<= 1LL;
	}
}

vector < long long > seq;
long long utrans( long long u ){
	seq.clear();
	while( u )
		seq.emplace_back( u ),
		u >>= 1LL;
	reverse( seq.begin() , seq.end() );
	long long f = 0;
	for(int i = 0 ; i < seq.size() ; ++ i)
		if( i == seq.size() - 1 || seq[i] * 2LL + 1 == seq[i + 1] )
			f += 1LL << deep - i - 1;
	return f;
}

int main( int argc , char * argv[] ){
	cin >> n >> q;
	for(deep = 0 ; (1LL << deep) < n + 1 ; ++ deep);
	while( q -- ){
		long long u ;
		cin >> u >> s;
		u = trans( u );
		for(auto travel : s){
			long long nxt = u;
			if( travel == 'L' ){
				nxt = nxt * 2LL;
			}else if( travel == 'U' )
				nxt = nxt / 2LL;
			else
				nxt = nxt * 2LL + 1;
			if( nxt <= n && nxt >= 1 )
				u = nxt;
		}
		cout << utrans( u ) << endl;
	}
	return 0;
}