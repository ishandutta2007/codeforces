#include <unordered_map>
#include <unordered_set>
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
#define rg register
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
		while( !isdigit(ch)  &&  !isalpha(ch)  &&  ch != '-'  &&  ch != '.' ) ch = C();
		while( isdigit(ch)  ||  isalpha(ch)  ||  ch == '-'  ||  ch == '.' ){
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
	Fin((pname+".in").c_str());
	#ifndef intLSY
		Fout((pname+".out").c_str());
	#endif
}
void Printtime(){
	#ifdef intLSY
		double _timeuse = clock()* 1000.0 / CLOCKS_PER_SEC;
		printf("\n\nTime usage:\n%.0lf ms\n",_timeuse);
	#endif
}
void END(){ Printtime(); exit(0); }
_tp<_tyn T>void END( T mes ){ cout << mes << endl; END(); }


// Loop
#define For(i,j) for( rg int (i) = 1 ; (i) <= (j) ; ++(i) )
#define For0(i,j) for( rg int (i) = 0 ; (i) < (j) ; ++(i) )
#define Forx(i,j,k) for( rg int (i) = (j) ; (i) <= (k) ; ++(i) )
#define Forstep(i,j,k,st) for( rg int (i) = (j) ; (i) <= (k) ; (i) += (st) )
#define fOR(i,j) for( rg int (i) = (j) ; (i) >= 1 ; --(i) )
#define fOR0(i,j) for( rg int (i) = (j)-1 ; (i) >= 0 ; --(i) )
#define fORx(i,j,k) for( rg int (i) = (k) ; (i) >= (j) ; --(i) )


// Debug
#define B cerr << "BreakPoint" << endl;
#define O(x) cerr << #x << " " << x << endl;
#define O_(x) cerr << #x << " " << x << "  ";
#define ERR(x) cerr << "ERR! #" << x << endl;
#define Msz(x) cerr << "Sizeof " << #x << " " << sizeof(x)/1024/1024 << " MB" << endl;
_tp<_tyn T>void Print( T a[] , int s , int t , char sp = ' ' , char ed = '\n' ){
	for( int i = s ; i <= t ; i++ )
		cout << a[i] << sp;
	cout << ed;
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
ll Pow( rg ll a , rg ll b , rg ll p = MOD ){
	rg ll ret = 1;
	for( ; b ; a = a*a%p, b >>= 1LL )
		if(b&1LL) ret = ret*a%p;
	return ret;
}
ll Inv( ll a , ll p = MOD ){ return Pow(a,p-2LL,p); }
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
#define MAXN 400010
#define MAXP 62
const int primes[64] = {
	2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97,
	101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199,
	211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293
};
const int invprime[64] = {
	500000004, 333333336, 400000003, 142857144, 818181824, 153846155, 352941179, 157894738, 739130440, 758620695,
	129032259, 621621626, 658536590, 395348840, 404255322, 56603774, 50847458, 688524595, 686567169, 98591550, 410958907,
	202531647, 84337350, 415730340, 268041239, 940594066, 572815538, 224299067, 9174312, 893805316, 480314964, 190839696,
	58394161, 604316551, 530201346, 483443712, 343949047, 116564418, 5988024, 791907520, 435754193, 933701664, 439790579,
	694300523, 969543154, 507537692, 90047394, 125560539, 35242291, 711790398, 90128756, 280334730, 406639007, 912350604,
	70038911, 836501907, 743494429, 450184505, 252707583, 718861215, 650176683, 522184304
};

int n,qu;
int inpa[MAXN];

#define TREE 1048579
#define LSON l,l+r>>1,pos<<1
#define RSON (l+r>>1)+1,r,pos<<1|1
#define ARG int l , int r , int pos
#define ROOT 1,n,1
namespace Multitree{
	int tree[TREE];
	int lazy[TREE];
	void Build(ARG){
		lazy[pos] = 1;
		if( l == r ){
			tree[pos] = inpa[l];
			return;
		}
		Build(LSON);
		Build(RSON);
		tree[pos] = 1LL*tree[pos<<1]*tree[pos<<1|1] % MOD;
	}
	#define Pushr(l,r,pos,x) \
		tree[pos] = 1LL*tree[pos]*Pow(x,(r)-(l)+1)%MOD; \
		lazy[pos] = 1LL*lazy[pos]*x%MOD;
	void Push(ARG){
		if( lazy[pos] == 1 ) return;
		if( l != r ){
			Pushr(l,l+r>>1,pos<<1,lazy[pos]);
			Pushr((l+r>>1)+1,r,pos<<1|1,lazy[pos]);
		}
		lazy[pos] = 1;
	}
	void Multi( int gl , int gr , int x , ARG ){
		Push(l,r,pos);
		if( gl <= l && r <= gr ){
			Pushr(l,r,pos,x);
			return;
		}
		if( gr < l || r < gl ) return;
		Multi(gl,gr,x,LSON);
		Multi(gl,gr,x,RSON);
		tree[pos] = 1LL*tree[pos<<1]*tree[pos<<1|1] % MOD;
	}
	il void Multi( int l , int r , int x ){
		Multi(l,r,x,ROOT);
	}
	int Query( int gl , int gr , ARG ){
		Push(l,r,pos);
		if( gl <= l && r <= gr ) return tree[pos];
		if( gr < l || r < gl ) return 1;
		return 1LL*Query(gl,gr,LSON)*Query(gl,gr,RSON) % MOD;
	}
	il int Query( int l , int r ){
		return Query(l,r,ROOT);
	}
};
namespace Primetree{
	bitset<64> tree[TREE], lazy[TREE];
	bool havelazy[TREE];
	void Build(ARG){
		if( l == r ){
			For0(i,MAXP){
				tree[pos][i] = ( inpa[l]%primes[i] == 0 );
			}
			return;
		}
		Build(LSON);
		Build(RSON);
		tree[pos] = tree[pos<<1] | tree[pos<<1|1];
	}
	#define Pushr(pos,x) \
		tree[pos] |= x; \
		lazy[pos] |= x; \
		havelazy[pos] = 1;
	void Push(ARG){
		if(!havelazy[pos]) return;
		if( l != r ){
			Pushr(pos<<1,lazy[pos]);
			Pushr(pos<<1|1,lazy[pos]);
		}
		havelazy[pos] = 0;
	}
	void Multi( int gl , int gr , bitset<64> x , ARG ){
		Push(l,r,pos);
		if( gl <= l && r <= gr ){
			Pushr(pos,x);
			return;
		}
		if( gr < l || r < gl ) return;
		Multi(gl,gr,x,LSON);
		Multi(gl,gr,x,RSON);
		tree[pos] = tree[pos<<1] | tree[pos<<1|1];
	}
	il void Multi( int l , int r , int x ){
		bitset<64> b;
		For0(i,MAXP)
			b[i] = ( x%primes[i] == 0 );
		Multi(l,r,b,ROOT);
	}
	bitset<64> Query( int gl , int gr , ARG ){
		Push(l,r,pos);
		if( gl <= l && r <= gr ) return tree[pos];
		int mid = l+r >> 1;
		if( gr <= mid ) return Query(gl,gr,LSON);
		if( gl > mid ) return Query(gl,gr,RSON);
		return Query(gl,gr,LSON) | Query(gl,gr,RSON);
	}
	il bitset<64> Query( int l , int r ){
		return Query(l,r,ROOT);
	}
}

int main(){
	FILEIO();

	Read(n,qu);
	For(i,n) Read(inpa[i]);

	Multitree::Build(ROOT);
	Primetree::Build(ROOT);

	For(qwq,qu){
		char c;
		In.Readalpha(c);
		if( c == 'T' ){
			iRead2(l,r);
			int mult = Multitree::Query(l,r);//O(mult);
			bitset<64> have = Primetree::Query(l,r);
			int ans = mult;
			For0(i,MAXP)
				if(have[i])
					ans = 1LL*ans*(primes[i]-1)%MOD * invprime[i] % MOD;
			printf("%d\n",ans);
		}else{
			iRead3(l,r,x);
			// cout << l << " " << r << " " << x << endl;
			Multitree::Multi(l,r,x);
			Primetree::Multi(l,r,x);
		}
		// O(Multitree::Query(2,5));
	}

	END();
}