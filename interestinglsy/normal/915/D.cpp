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
#define mymax(a,b) if(a<b) a = b;
#define mymin(a,b) if(a>b) a = b;
void print(int _x){printf("%d\n",_x);}
void print(ll _x){printf("%lld\n",_x);}
_tp<_tyn T>void print( T _a[] , int _s , int _t ){
	for( int i = _s ; i <= _t ; i++ )
		cout << _a[i] << " ";
   	cout << endl;
}
#define il inline
#define rg register
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
		while( ch < 'F'  ||  ch > 'R' ) ch = c();
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
clock_t _starttime , _endtime;
il void FILEIO(){
	#ifdef WIN32
		_starttime = clock();
	#endif
	#ifdef WIN32
		fin("d.in");
	#endif
}
il void END(){
	#ifdef WIN32
		_endtime = clock();
		double _timeuse = (_endtime-_starttime)* 1000.0 / CLOCKS_PER_SEC;
		printf("\n\nTime usage:\n%lf ms\n",_timeuse);
	#endif
	exit(0);
}
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
#define MAXN 510

int n,m;
bool e[MAXN][MAXN];

int vis[MAXN];
int cyc = 0;
vc<int> sta;
bool incycle[MAXN][MAXN];
bool nocyc[MAXN];
void dfs( int pos , int lim , int t ){
	for( int to = 1 ; to <= n  &&  cyc < lim ; to++ ){
		if( !e[pos][to] ) continue;
		if( nocyc[to] ) continue;
		if( vis[to] == t ){
			int tp = 0;
			int p = sta.size()-1;
			sta.pb(to);
			while( tp != to ){
				tp = sta.at(p);
				incycle[tp][sta.at(p+1)] = 1;
				p--;
			}
			cyc++;
			return;
		}
		vis[to] = t;
		sta.pb(to);
		dfs(to,lim,t);
		sta.pop_back();
		vis[to] = 0;
	}
	if( cyc < lim ){
		nocyc[pos] = 1;
	}
}

void dfs2( int pos , int lim , int t ){
	for( int to = 1 ; to <= n  &&  cyc < lim ; to++ ){
		if( !e[pos][to] ) continue;
		if( nocyc[to] ) continue;
		if( vis[to] == t ){
			cyc++;
			return;
		}
		vis[to] = t;
		dfs2(to,lim,t);
		vis[to] = 0;
	}
	if( cyc < lim ){
		nocyc[pos] = 1;
	}
}

int main(){
	FILEIO();
	ms(e);

	read(n,m);
	for( int i = 1 ; i <= m ; i++ ){
		int a,b;
		read(a,b);
		e[a][b] = 1;
	}

	ms(vis);
	ms(nocyc);
	for( int i = 1 ; i <= n  &&  !cyc ; i++ ){
		//ms(vis);
		vis[i] = i;
		sta.clear();
		sta.pb(i);
		dfs(i,1,i);
	}
	if( !cyc ){
		cout << "YES" << endl;
		END();
	}

	for( int i = 1 ; i <= n ; i++ ){
		for( int j = 1 ; j <= n ; j++ ){
			if( !incycle[i][j] ) continue;
			//cout << i << " " << j << endl;
			//if( i != 2  ||  j != 3 ) continue;
			e[i][j] = 0;

			cyc = 1;
			bool f = 0;
			ms(vis);
			ms(nocyc);
			for( int k = 1 ; k <= n ; k++ ){
				if( !vis[k] ){
					//ms(vis);
					vis[k] = k;
					dfs2(k,2,k);
					//cout << k << "  |  " << cyc << endl;
					if( cyc >= 2 ){
						f = 1;
						break;
					}
				}
			}
			if( !f ){
				cout << "YES" << endl;
				END();
			}

			e[i][j] = 1;
		}
	}

	cout << "NO" << endl;
	END();
}