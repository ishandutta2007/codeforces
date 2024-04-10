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
		fin("B.in");
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
int n,pos,l,r;

int main(){
	FILEIO();

	read(n,pos,l,r);

	if( l == 1  &&  r == n ){
		cout << 0 << endl;
		END();
	}
	if( l == 1 ){
		int ans = abs(r-pos)+1;
		cout << ans << endl;
		END();
	}
	if( r == n ){
		int ans = abs(l-pos)+1;
		cout << ans << endl;
		END();
	}
	if( pos < l ){
		int ans = l-pos+1+r-l+1;
		cout << ans << endl;
	}else
		if( pos > r ){
			int ans = pos-r+1+r-l+1;
			cout << ans << endl;
		}else{
			int ans1 = pos-l+1+r-l+1;
			int ans2 = r-pos+1+r-l+1;
			cout << min(ans1,ans2) << endl;
		}
	END();
}