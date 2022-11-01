#include <unordered_map>
#include <unordered_set>////////////////
#include <functional>
#include <algorithm>
#include <iostream>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <climits>
#include <iomanip>
#include <bitset>
#include <vector>
#include <cstdio>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <ctime>
#include <set>
#include <map>
using namespace std;
#define il inline
#define elif else if

// Type
#define ld double
#define ll long long
#define ull unsigned ll

// Vector
#define vc vector
#define Pb push_back
#define Pf push_front
#define All(x) x.begin(),x.end()

// Memory
#define Ms(_data) memset(_data,0,sizeof(_data))
#define Msn(_data,_num) memset(_data,_num,sizeof(_data))

// Template
#define _cl class
#define _tp template
#define _tyn typename

// Pair
#define Mp make_pair
#define F first
#define S second
#define pii pair<int,int>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define pll pair<ll,ll>

// Read
struct InputReader{
    #define bs 1000001
    char buf[bs]; int p;
    il InputReader(){ p = bs; }
    il void Flush(){ p = 0; fread(buf,1,bs,stdin); }
    il char C(){ if(p >= bs) Flush(); return buf[p++]; }
    il char Readnum(){ char ch = C(); while( !isdigit(ch) && ch != '-' ) ch = C(); return ch; }
    il void Readalpha( char &c ){ c = C(); while( !isalpha(c) ) c = C(); }
    int operator() (){
        int ans = 0, fu = 1; char ch = Readnum();
        if( ch == '-' ) fu = -1, ch = C();
        while( ch >= '0' && ch <= '9' ){
            ans = ans*10 + ch-'0';
            ch = C();
        }
        return ans * fu;
    }
    ll Readll(){
        ll ans = 0LL, fu = 1LL; char ch = Readnum();
        if( ch == '-' ) fu = -1LL, ch = C();
        while( ch >= '0' && ch <= '9' ){
            ans = ans*10LL + ch-'0';
            ch = C();
        }
        return ans * fu;
    }
    il void Readstring( string &x ){
        x.clear(); char ch = C();
        while( !isdigit(ch)  &&  !isalpha(ch)  &&  ch != '#'  &&  ch != '.' ) ch = C();
        while( isdigit(ch)  ||  isalpha(ch)  ||  ch == '#'  ||  ch == '.' ){
            x += ch;
            ch = C();
        }
    }
    il void Readchstring( char s[] ){
        int len = 0; char ch = C();
        while( !isdigit(ch)  &&  !isalpha(ch)  /*&&  ch != '*'  &&  ch != '?'*/ ) ch = C();
        while( isdigit(ch)  ||  isalpha(ch)  /*||  ch == '*'  ||  ch == '?'*/ ){
            s[len++] = ch;
            ch = C();
        }
        s[len] = '\0';
    }
    il void Specialread( char &c ){
        c = C();
        while( !isdigit(c) && !isalpha(c) && c != '#'  &&  c != '.'  &&  c != '='  &&  c != 'B' ) c = C();
    }
    #undef bs
}In;
il void Read( int &x ){ x = In(); }
il void Read( int &x, int &y ){ x = In(); y = In(); }
il void Read( int &x1 , int &x2 , int &x3 ){ x1 = In(); x2 = In(); x3 = In(); }
il void Read( int &x1 , int &x2 , int &x3 , int &x4 ){ x1 = In(); x2 = In(); x3 = In(); x4 = In(); }
il void Read( ll &x ){ x = In.Readll(); }
il void Read( ll &x, ll &y ){ x = In.Readll(); y = In.Readll(); }
il void Read( ll &x1 , ll &x2 , ll &x3 ){ x1 = In.Readll(); x2 = In.Readll(); x3 = In.Readll(); }
il void Read( ll &x1 , ll &x2 , ll &x3 , ll &x4 ){ x1 = In.Readll(); x2 = In.Readll(); x3 = In.Readll(); x4 = In.Readll(); }
#define iRead(k) int k; Read(k);
#define iRead2(a,b) iRead(a); iRead(b);
#define iRead3(a,b,c) iRead2(a,b); iRead(c);
#define iRead4(a,b,c,d) iRead2(a,b); iRead2(c,d);
#define lRead(k) ll k; Read(k);
#define lRead2(a,b) lRead(a); lRead(b);
#define lRead3(a,b,c) lRead2(a,b); lRead(c);
#define lRead4(a,b,c,d) lRead2(a,b); lRead2(c,d);

// File
#define Fin(a) freopen(a,"r",stdin)
#define Fout(a) freopen(a,"w",stdout)
il void FILEIO(){
    #ifdef intLSY
        Fin("in.in");
    #endif
}
il void FILEIO( string pname ){
    #ifndef intLSY
        Fin((pname+".in").c_str());
        Fout((pname+".out").c_str());
    #else
        Fin("in.in");
    #endif
}
void Printtime(){
    #ifdef intLSY
        double _timeuse = clock()* 1000.0 / CLOCKS_PER_SEC;
        fprintf(stderr,"\n\nTime usage:\n%.0lf ms\n",_timeuse);
    #endif
}
void END(){ Printtime(); exit(0); }
_tp<_tyn T>void END( T mes ){ cout << mes << endl; END(); }


// Loop
#define For(i,j) for( int (i) = 1 ; (i) <= (j) ; ++(i) )
#define For0(i,j) for( int (i) = 0 ; (i) < (j) ; ++(i) )
#define Forx(i,j,k) for( int (i) = (j) ; (i) <= (k) ; ++(i) )
#define Forstep(i,j,k,st) for( int (i) = (j) ; (i) <= (k) ; (i) += (st) )
#define fOR(i,j) for( int (i) = (j) ; (i) >= 1 ; --(i) )
#define fOR0(i,j) for( int (i) = (j)-1 ; (i) >= 0 ; --(i) )
#define fORx(i,j,k) for( int (i) = (k) ; (i) >= (j) ; --(i) )


// Debug
#define B cerr << "BreakPoint" << endl;
#define O(x) cerr << #x << " " << x << endl;
#define O_(x) cerr << #x << " " << x << "  ";
#define ERR(x) cerr << "ERR! #" << x << endl;
#define Msz(x) cerr << "Sizeof " << #x << " " << sizeof(x)/1024/1024 << " MB" << endl;
_tp<_tyn T>void Print( T a[] , int s , int t , char sp = ' ' , char ed = '\n' ){
    if( s > t ) return;
    for( int i = s ; i < t ; i++ )
        cout << a[i] << sp;
    cout << a[t] << ed;
    cout.flush();
}
_tp<_tyn T>void Print( T a , int s = 0 , int t = -1 , char sp = ' ' , char ed = '\n' ){
    if( t == -1 ) t = a.size()-1;
    for( int i = s ; i <= t ; i++ )
        cout << a[i] << sp;
    cout << ed;
    cout.flush();
}


// Optimize
#define abs(a) ((a)<0?(~(a)+1):(a))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
//#define swap(a,b) {a=a^b;b=a^b;a=a^b;}
#define Mymax(a,b) (a) = max((a),(b))
#define Mymin(a,b) (a) = min((a),(b))
#define INF (0x3f3f3f3f)
#define LINF ((long long)(0x3f3f3f3f3f3f3f3f))
#define MOD (1000000007LL)
#define Rmoi(a,b) ((a)%b+b)%b
#define Rmo(a) ((a)%MOD+MOD)%MOD
#define Rmod(a) a = (a%MOD+MOD)%MOD
#define Rmodi(a,b) a = (a%(b)+(b))%(b)
#define Mymoi(a,b) ((a)>=b?((a)-b):(a))
#define Mymo(a) ((a)>=MOD?((a)-MOD):(a))
#define Mymod(a) a = (a)>=MOD?((a)-MOD):(a)
#define Mymodi(a,b) a = ((a)>=(b))?((a)-(b)):(a)
ll Pow( ll a , ll b , ll p = MOD ){
    ll ret = 1;
    for( ; b ; a = a*a%p, b >>= 1LL )
        if(b&1LL) ret = ret*a%p;
    return ret;
}
ll Inv( ll a , ll p = MOD ){ return Pow(a,p-2LL,p); }
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
ll n,k;
ll a,b;

ll gcd( ll a , ll b ){ return b ? gcd(b,a%b) : a; }
ll Needstep( ll st ){
    // lcm(n*k,st) / st
    // = n*k*st / g / st
    // O(st);
    ll g = gcd(n*k,st);
    // if( n*k == st ) B
    return n*k / g;
}

int main(){
    FILEIO();

    Read(n,k);
    Read(a,b);

    ll mi = Needstep(k-a-b), mx = Needstep(k-a-b);
    Forx(i,0,n){
        ll ust = Needstep(k+i*k-a-b);
        Mymin(mi,ust);
        Mymax(mx,ust);
        ust = Needstep(k+i*k+a+b);
        Mymin(mi,ust);
        Mymax(mx,ust);
        ust = Needstep(k+i*k-a+b);
        Mymin(mi,ust);
        Mymax(mx,ust);
        ust = Needstep(k+i*k+a-b);
        Mymin(mi,ust);
        Mymax(mx,ust);
    }

    cout << mi << " " << mx << endl;

    END();
}///