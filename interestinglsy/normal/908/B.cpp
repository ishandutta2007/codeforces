#include <bits/stdc++.h>
#define F first
#define S second
#define dq deque
#define vc vector
#define INF (0x3f3f3f3f)
#define LINF ((long long)(1e18))
#define pb push_back
#define mp make_pair
#define ll long long
#define _tp template
#define _tyn typename
#define pf push_front
#define itor iterator
#define sint short int
#define ull unsigned ll
#define pii pair<int,int>
#define uint unsigned int
#define B cout << "BreakPoint" << endl;
#define ms(_data) memset(_data,0,sizeof(_data))
#define fin(_filename) freopen(_filename,"r",stdin)
#define fout(_filename) freopen(_filename,"w",stdout)
#define msn(_data,_num) memset(_data,_num,sizeof(_data))
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
using namespace std;
_tp<_tyn T>void mymax( T &_a , T _b ){ if( _a < _b ) _a = _b; }
_tp<_tyn T>void mymin( T &_a , T _b ){ if( _a > _b ) _a = _b; }
void print(int _x){printf("%d\n",_x);}
void print(ll _x){printf("%I64d ",_x);}
_tp<_tyn T>void print( T _a[] , int _s , int _t ){
	for( int i = _s ; i <= _t ; i++ )
		cout << _a[i] << " ";
   	cout << endl;
}
#define il inline
struct InputReader{
    static const int bs = 100000;
    char buf[bs];
    int p;
    il InputReader():p(bs) {}
    il void flush(){
        p = 0;
        fread(buf, 1, bs, stdin);
    }
    il char c(){
        if(p >= bs) flush();
        return buf[p++];
    }
	int getnum(){
		char ch = c();
        while( ch < '0'  ||  ch > '9' ) ch = c();
		return (int)(ch-'0');
	}
    il int operator() (){
        int ans = 0;
        char ch = c();
		int fu = 1;
		while( ch < '0'  ||  ch > '9' ){
			if( ch == '-' ) fu = -1;
			ch = c();
		}
        while( ch >= '0'  &&  ch <= '9' ){
            ans *= 10;
            ans += ch-'0';
            ch = c();
        }
        return ans * fu;
    }
	ll readll(){
		ll ans = 0LL;
		char ch = getnum()+'0';
        while( ch >= '0'  &&  ch <= '9' ){
            ans *= 10LL;
            ans += ch-'0';
            ch = c();
        }
        return ans;
	}
	char specialread(){
		char ch = c();
		while( ch < 'a'  ||  ch > 'z' ) ch = c();
		return ch;
	}
}in;
il void read( int &x ){
	x = in();
}
il void read( int &x, int &y ){
	x = in(); y = in();
}
il void read( int &x1 , int &x2 , int &x3 ){
	x1 = in(); x2 = in(); x3 = in();
}
il void read( int &x1 , int &x2 , int &x3 , int &x4 ){
	x1 = in(); x2 = in(); x3 = in(); x4 = in();
}
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
#define MAXN 52

int n,m;
string s;
bool cango[MAXN][MAXN];
int stx , sty;
bool ised[MAXN][MAXN];

int ans = 0;
bool hasmap[6];
int mapp[6];

int dx[] = {0,-1,0,1};
int dy[] = {1,0,-1,0};
bool judge(){
	int x = stx , y = sty;
	int pos = 0;
	while(1){
		if( ised[y][x] ) return 1;
		if( !cango[y][x] ) return 0;
		if( pos == s.length() ) break;
		int cmd = s[pos]-'0';
		pos++;
		x += dx[mapp[cmd]];
		y += dy[mapp[cmd]];
	}
	return 0;
}
void dfs( int pos ){
	if( pos == 4 ){
		//print(mapp,0,3);
		int a = judge();
		ans += a;
		return;
	}
	for( int i = 0 ; i <= 3 ; i++ ){
		if( hasmap[i] ) continue;
		hasmap[i] = 1;
		mapp[pos] = i;
		dfs(pos+1);
		hasmap[i] = 0;
	}
}
int main(){
	ms(ised);
	ms(hasmap);

	cin >> n >> m;
	for( int i = 1 ; i <= n ; i++ )
		for( int j = 1 ; j <= m ; j++ ){
			char c;
			cin >> c;
			if( c == '#' ) cango[i][j] = 0;
			else cango[i][j] = 1;
			if( c == 'S' ){
				stx = j;
				sty = i;
			}
			if( c == 'E' ){
				ised[i][j] = 1;
			}
		}
	cin >> s;

	dfs(0);

	cout << ans << endl;

	return 0;
}