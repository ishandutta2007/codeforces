// InterestingLSY
// codeforces&github: interestingLSY, qq: 2659723130
// 
#ifdef intLSY
#include <intlsy/stdc++.h>
#else
#include <bits/stdc++.h>
#endif
#include <bits/c++0x_warning.h>
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
#define Eb emplace_back
#define All(x) x.begin(),x.end()
#define AllRev(x) x.rbegin(),x.rend()

// Memory
#define Ms(_data) memset(_data,0,sizeof(_data))
#define Msn(_data,_num) memset(_data,_num,sizeof(_data))

// Pair
#define F first
#define S second
#define pii pair<int,int>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define pll pair<ll,ll>

// Loop
#define For(i,j) for( int (i) = 1 ; (i) <= (j) ; ++(i) )
#define For0(i,j) for( int (i) = 0 ; (i) < (j) ; ++(i) )
#define Forx(i,j,k) for( int (i) = (j) ; (i) <= (k) ; ++(i) )
#define Forstep(i,j,k,st) for( int (i) = (j) ; (i) <= (k) ; (i) += (st) )
#define fOR(i,j) for( int (i) = (j) ; (i) >= 1 ; --(i) )
#define fOR0(i,j) for( int (i) = (j)-1 ; (i) >= 0 ; --(i) )
#define fORx(i,j,k) for( int (i) = (k) ; (i) >= (j) ; --(i) )

// Read
struct InputReader{
	static constexpr int MAXSZ = 1048576;
	char buf[MAXSZ]; int p, ed;
	bool detectedEOF = false;
	il InputReader(){ p = MAXSZ; }
	il void Flush(){ p = 0; ed = fread(buf,1,MAXSZ,stdin); }
	il void GetChar( char &c ){
		if(p >= MAXSZ) Flush();
		if( p == ed ){ detectedEOF = true; }
		c = buf[p++];
	}
	il void ReadNum( char &c ){ GetChar(c); while( !isdigit(c) && c != '-' && !detectedEOF ) GetChar(c); }
	il void ReadAlpha( char &c ){ GetChar(c); while( !isalpha(c) && !detectedEOF ) GetChar(c); }
	il void ReadInt( int &ans ){
		ans = 0; int nega = 1;
		char c; ReadNum(c); if(detectedEOF) return;
		if( c == '-' ){
			nega = -1;
			GetChar(c);
		}
		while( isdigit(c) && !detectedEOF ){
			ans = ans*10 + c-'0';
			GetChar(c);
		}
		ans *= nega;
	}
	il void Readll( ll &ans ){
		ans = 0; int nega = 1;
		char c; ReadNum(c); if(detectedEOF) return;
		if( c == '-' ){
			nega = -1;
			GetChar(c);
		}
		while( isdigit(c) && !detectedEOF ){
			ans = ans*10 + c-'0';
			GetChar(c);
		}
		ans *= nega;
	}
	il void ReadString( string &x ){
		x.clear(); char ch; GetChar(ch);
		while( !isdigit(ch) && !isalpha(ch) && ch != '#' && ch != '.' && !detectedEOF ) GetChar(ch); if(detectedEOF) return;
		while( (isdigit(ch) || isalpha(ch) || ch == '#' || ch == '.') && !detectedEOF ){
			x += ch;
			GetChar(ch);
		}
	}
	il void ReadCString( char s[] ){
		int len = 0; char ch; GetChar(ch);
		while( !isdigit(ch) && !isalpha(ch) && ch != '#' && ch != '.' && !detectedEOF ) GetChar(ch); if(detectedEOF) return;
		while( (isdigit(ch) || isalpha(ch) || ch == '#' || ch == '.') && !detectedEOF ){
			s[len++] = ch;
			GetChar(ch);
		}
		s[len] = '\0';
	}
	il void SpecialRead( char &c ){
		GetChar(c); if(detectedEOF) return;
		while( !isdigit(c) && !isalpha(c) && c != '#' && c != '.' && c != '=' && c != 'B' && !detectedEOF ) GetChar(c);
	}
}In;
il void Read( int &x ){ In.ReadInt(x); }
il void Read( int &x, int &y ){ In.ReadInt(x); In.ReadInt(y); }
il void Read( int &x1 , int &x2 , int &x3 ){ In.ReadInt(x1); In.ReadInt(x2); In.ReadInt(x3); }
il void Read( int &x1 , int &x2 , int &x3 , int &x4 ){ In.ReadInt(x1); In.ReadInt(x2); In.ReadInt(x3); In.ReadInt(x4); }
il void Read( ll &x ){ In.Readll(x); }
il void Read( ll &x, ll &y ){ In.Readll(x); In.Readll(y); }
il void Read( ll &x1 , ll &x2 , ll &x3 ){ In.Readll(x1); In.Readll(x2); In.Readll(x3); }
il void Read( ll &x1 , ll &x2 , ll &x3 , ll &x4 ){ In.Readll(x1); In.Readll(x2); In.Readll(x3); In.Readll(x4); }
template<typename T> void Read( T a[] , int st , int ed ){ Forx(i,st,ed) Read(a[i]); }
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
il void FILEIO_OICONTEST( string pname ){
	Fin((pname+".in").c_str());
	#ifndef intLSY
		Fout((pname+".out").c_str());
	#endif
}
void Printtime(){
	#ifdef intLSY
		double _timeuse = clock()* 1000.0 / CLOCKS_PER_SEC;
		fprintf(stderr,"\n\nTime usage:\n%.0lf ms\n",_timeuse);
	#endif
}
void END(){ Printtime(); exit(0); }
template<typename T>void END( T mes ){ cout << mes << endl; END(); }

// Debug
#define B cerr << "BreakPoint" << endl;
#define O(x) cerr << #x << " " << (x) << endl;
#define o(x) cerr << #x << " " << (x) << "  ";
template<typename T0>
void P( T0 t0 ){
	cerr << t0 << endl;
}
template<typename T0, typename... Ts>
void P( T0 t0 , Ts... ts ){
	cerr << t0 << " ";
	P(ts...);
}
#define Msz(x) cerr << "Sizeof " << #x << " " << sizeof(x)/1024/1024 << " MB" << endl;
template<typename T>void Print( T a[] , int s , int t , char sp = ' ' , char ed = '\n' ){
	if( s > t ) return;
	for( int i = s ; i < t ; i++ )
		cout << a[i] << sp;
	cout << a[t] << ed;
	cout.flush();
}
template<typename T>void Print( T a , int s = 0 , int t = -1 , char sp = ' ' , char ed = '\n' ){
	if( t == -1 ) t = a.size()-1;
	for( int i = s ; i <= t ; i++ )
		cout << a[i] << sp;
	cout << ed;
	cout.flush();
}

// Optimize
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define Mymax(a,b) (a) = max((a),(b))
#define Mymin(a,b) (a) = min((a),(b))
#define MyMax(a,b) (a) = Max((a),(b))
#define MyMin(a,b) (a) = Min((a),(b))
#define INF (0x3f3f3f3f)
#define LINF ((long long)(0x3f3f3f3f3f3f3f3f))
#define Sqr(x) ((x)*(x))
#define Lowbit(a) ((a)&(-(a)))
#include <chrono>
mt19937 Rand(chrono::steady_clock::now().time_since_epoch().count());
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
constexpr int MAXN = 262144;

constexpr ll MOD0 = 998244353;
const ll MOD1 = uniform_int_distribution<>(100000000,1000000000)(Rand);
struct HashNum{
	int len;
	ll h0, h1;
};

ll p0[MAXN], p1[MAXN];
void InitPs(){
	p0[0] = p1[0] = 1;
	For(i,MAXN-1){
		p0[i] = p0[i-1]*2 % MOD0;
		p1[i] = p1[i-1]*2 % MOD1;
	}
}

HashNum PushFront( const HashNum &a , int b ){
	return {
		a.len+1,
		( a.h0 + b*p0[a.len] ) % MOD0,
		( a.h1 + b*p1[a.len] ) % MOD1
	};
}
HashNum PushBack( const HashNum &a , int b ){
	return {
		a.len+1,
		( a.h0*2 + b ) % MOD0,
		( a.h1*2 + b ) % MOD1
	};
}
HashNum operator+( const HashNum &a , const HashNum &b ){
	return {
		a.len + b.len,
		( a.h0*p0[b.len] + b.h0 ) % MOD0,
		( a.h1*p1[b.len] + b.h1 ) % MOD1
	};
}
il bool operator==( const HashNum &a , const HashNum &b ){
	return a.len == b.len and a.h0 == b.h0 and a.h1 == b.h1;
}

struct Node{
	int len;
	HashNum x;
	int f1, b1;
};

#define IsF(x) (x.f1==x.len)
Node operator+( const Node &a , const Node &b ){
	Node res;
	res.len = a.len + b.len;
	if( IsF(a) and IsF(b) ){
		res.x = {0,0,0};
		res.f1 = res.b1 = res.len;
	}
	else if( IsF(a) ){
		res.x = b.x;
		res.f1 = a.len + b.f1;
		res.b1 = b.b1;
	}
	else if( IsF(b) ){
		res.x = a.x;
		res.f1 = a.f1;
		res.b1 = a.b1 + b.len;
	}else{
		res.f1 = a.f1; res.b1 = b.b1;
		if((a.b1+b.f1)&1) res.x = PushBack(a.x,1) + b.x;
		else res.x = a.x + b.x;
	}
	return res;
}

int n;
int a[MAXN];

Node t[524288];
#define LSON l,l+r>>1,pos<<1
#define RSON (l+r>>1)+1,r,pos<<1|1
#define ROOT 1,n,1
#define ARG int l , int r , int pos
void Build(ARG){
	if( l == r ){
		t[pos] = {
			1,
			{a[l]==0,0,0},
			a[l] == 1,
			a[l] == 1
		};
		return;
	}
	Build(LSON);
	Build(RSON);
	t[pos] = t[pos<<1] + t[pos<<1|1];
}

Node Query( int gl , int gr , ARG ){
	if( gl <= l and r <= gr ) return t[pos];
	int mid = l+r >> 1;
	if( gr <= mid ) return Query(gl,gr,LSON);
	if( gl >  mid ) return Query(gl,gr,RSON);
	return Query(gl,gr,LSON) + Query(gl,gr,RSON);
}

HashNum GetHsh( int l , int r ){
	Node res = Query(l,r,ROOT);
	HashNum ans = res.x;
	if(res.f1&1) ans = PushFront(ans,1);
	if( !IsF(res) and (res.b1&1) ) ans = PushBack(ans,1);
	// P(res.f1,res.b1);
	// P(l,r,ans.h0);
	return ans;
}

int main(){
	FILEIO();
	InitPs();

	Read(n);
	For(i,n){
		char c; In.ReadNum(c);
		a[i] = c == '1';
	}

	Build(ROOT);

	iRead(q);
	For(qwq,q){
		iRead3(l1,l2,len);
		if( l1 > l2 ) swap(l1,l2);
		HashNum h1 = GetHsh(l1,l1+len-1);
		HashNum h2 = GetHsh(l2,l2+len-1);
		printf( h1 == h2 ? "Yes\n" : "No\n" );
	}

	END();
}