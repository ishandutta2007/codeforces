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
		if( _a[i] != INF ) cout << _a[i] << "\t";
		else cout << "--\t";
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
string s;
int n;
bool isv( char c ){
	return (c=='a')||(c=='e')||(c=='i')||(c=='o')||(c=='u');
}
bool ise( char c ){
	return (c=='0')||(c=='2')||(c=='4')||(c=='6')||(c=='8');
}

int main(){
	cin >> s;
	n = s.length();

	int ans = 0;
	for( int i = 0  ; i < n ; i++ ){
		char c = s[i];
		if( isdigit(c) ){
			if(!ise(c)){
				ans++;
				
			}
		}else{
			if(!isv(c)){
				//ans1 = 0;
				//break;
			}else{
				ans++;
			}
		}
	}

	cout << ans << endl;
	return 0;
}