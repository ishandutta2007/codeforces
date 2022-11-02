// interestingLSY
#include <bits/stdc++.h>
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
	#define bs 1048576
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
		while( !isdigit(c) && !isalpha(c) && c != '*'  &&  c != '.'  &&  c != '='  &&  c != 'B' ) c = C();
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
_tp<_tyn T> void Read( T a[] , int st , int ed ){ Forx(i,st,ed) Read(a[i]); }
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
_tp<_tyn T>void END( T mes ){ cout << mes << endl; END(); }

// Debug
#define B cerr << "BreakPoint" << endl;
#define O(x) cerr << #x << " " << x << endl;
#define o(x) cerr << #x << " " << x << "  ";
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
vc<int> Range( int l , int r ){
	vc<int> ret{};
	Forx(i,l,r) ret.Pb(i);
	return ret;
}
mt19937 Rand(0xe38195e38293);	// 
#undef ld
#define ld long double
#define pdd pair<ld,ld>
const ld Eps = 1e-10;
// orz laofudasuan
// modified

namespace io{
	const int SIZE = (1 << 20) + 1;
	char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55]; int f, qr;
	// print the remaining part
	inline void Flush(){
		fwrite(obuf,1,oS-obuf,stdout);
		oS = obuf;
	}
	// putchar
	inline void Putc(char x) {
		*oS ++ = x;
		if( oS == oT ) Flush();
	}
	// print a signed integer
	template <class I>
	inline void Print(I x) {
		if(!x) Putc('0');
		if( x < 0 ){ Putc('-'); x = -x; }
		while(x){
			qu[++ qr] = x % 10 + '0';
			x /= 10;
		}
		while(qr) Putc(qu[qr --]);
	}
	//no need to call flush at the end manually!
	struct Flusher_{~Flusher_(){Flush();}}io_flusher_;
}

///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
const int MAXN = 262144;

int n,q;
vc<int> e[MAXN];
int inpa[MAXN], inpb[MAXN], inpa_ined[MAXN], inpb_ined[MAXN];

int order[MAXN], in[MAXN], out[MAXN], nowtime = 0;
void Dfs( int pos , int as , int bs ){
	as += inpa[pos]; inpa[pos] = as;
	bs += inpb[pos]; inpb[pos] = bs;
	order[++nowtime] = pos;
	in[pos] = nowtime;
	for( auto v : e[pos] ) Dfs(v,as,bs);
	out[pos] = nowtime;
}

const int MAXB = 2048;

struct Line{ ll k,b; };
il pll Insx( const Line &l1 , const Line &l2 ){
	return l1.k > l2.k ? (pll){l2.b-l1.b,l1.k-l2.k} : (pll){l1.b-l2.b,l2.k-l1.k};
}
il bool operator<( const pll &x , const pll &y ){
	return x.F*y.S < y.F*x.S;
}
il bool operator<=( const pll &x , const pll &y ){
	return x.F*y.S <= y.F*x.S;
}
il bool operator>( const pll &x , const pll &y ){
	return x.F*y.S > y.F*x.S;
}
il bool operator>=( const pll &x , const pll &y ){
	return x.F*y.S >= y.F*x.S;
}

int bsz, bcnt;
int bl[MAXN], br[MAXN], inb[MAXN];
void BlockInfoInit(){
	bsz = 180; Mymax(bsz,1); Mymin(bsz,n);
	For(i,n){
		int u = (i-1)/bsz + 1;
		inb[i] = u;
		if( bsz == 1 or i%bsz == 1 ) bl[u] = i;
		if( i%bsz == 0 ) br[u] = i;
	}
	bcnt = inb[n];
	br[bcnt] = n;
}

struct DS{
	ll c[MAXN];
	ll t[MAXN];
	vc<Line> hull[MAXB];
	ll x_add[MAXB];
	int cur_index[MAXB];
	ll cur_ans[MAXB];
	pii pre_sorted[MAXN];
	void RebuildBlock( int bid , bool is_init = 0 ){
		const ll txadd = x_add[bid];
		const int blbid = bl[bid], brbid = br[bid];
		Forx(i,blbid,brbid){
			c[i] += txadd*t[i];
		}
		x_add[bid] = 0;

		hull[bid].clear();
		if(is_init){
			Forx(i,blbid,brbid){
				pre_sorted[i] = {t[i],i};
			}
			sort(pre_sorted+blbid,pre_sorted+brbid+1);
		}
		// sort(All(lines),[]( const Line &l1 , const Line &l2 ){ return l1.k < l2.k; });
		Forx(i,blbid,brbid){
			Line line = {pre_sorted[i].F,c[pre_sorted[i].S]};
			bool fail = 0;
			while(hull[bid].size()){
				const Line b1 = hull[bid].back();
				if( b1.k == line.k ){
					if( b1.b <= line.b ){ hull[bid].pop_back(); continue; }
					else{
						fail = 1;
						break;
					}
				}
				if( hull[bid].size() == 1 ){
					if( b1.b <= line.b ) hull[bid].pop_back();
					break;
				}
				const Line b2 = hull[bid][hull[bid].size()-2];
				if( Insx(b1,line) <= Insx(b2,b1) ) hull[bid].pop_back();
				else break;
			}
			if(!fail) hull[bid].Eb(line);
		}
		cur_index[bid] = 0;
		cur_ans[bid] = hull[bid][0].b;
	}
	#define QueryBlock(bid) cur_ans[bid]
	il void AddBlock( int bid , ll x ){
		x_add[bid] += x;
		pll x_add_p = {x_add[bid],1};
		int ci = cur_index[bid];
		while( ci != hull[bid].size()-1 and Insx(hull[bid][ci],hull[bid][ci+1]) <= x_add_p ) ++ci;
		cur_ans[bid] = hull[bid][ci].k * x_add[bid] + hull[bid][ci].b;
		cur_index[bid] = ci;
	}
	void Init( bool usenega ){
		For(i,n){
			t[i] = usenega ? -inpb_ined[i] : inpb_ined[i];
			c[i] = inpa_ined[i] * t[i];
		}
		For(i,bcnt) RebuildBlock(i,1);
	}
	void Add( int gl , int gr , ll x ){
		const int u = inb[gl], v = inb[gr];
		if( u == v ){
			Forx(i,gl,gr) c[i] += t[i]*x;
			RebuildBlock(u);
			return;
		}
		Forx(i,gl,br[u]) c[i] += t[i]*x;
		RebuildBlock(u);
		Forx(i,bl[v],gr) c[i] += t[i]*x;
		RebuildBlock(v);
		Forx(i,u+1,v-1) AddBlock(i,x);
	}
	ll Query( int gl , int gr ){
		ll ans = -LINF;
		const int u = inb[gl], v = inb[gr];
		if( u == v ){
			Forx(i,gl,gr) Mymax(ans,c[i]+x_add[u]*t[i]);
			return ans;
		}
		Forx(i,gl,br[u]) Mymax(ans,c[i]+x_add[u]*t[i]);
		Forx(i,bl[v],gr) Mymax(ans,c[i]+x_add[v]*t[i]);
		Forx(i,u+1,v-1){
			ll tans = QueryBlock(i);
			MyMax(ans,tans);
		}
		return ans;
	}
}posi,nega;

int main(){
	FILEIO();
	#ifdef intLSY
		Fout("tmp.out");
	#endif

	Read(n,q);
	Forx(i,2,n){ iRead(x); e[x].Pb(i); }
	Read(inpa,1,n);
	Read(inpb,1,n);
	Dfs(1,0,0);
	For(i,n){
		inpa_ined[in[i]] = inpa[i];
		inpb_ined[in[i]] = inpb[i];
	}

	BlockInfoInit();
	posi.Init(0);
	nega.Init(1);

	For(i,q){
		iRead2(op,pos);
		if( op == 1 ){
			iRead(add);
			posi.Add(in[pos],out[pos],add);
			nega.Add(in[pos],out[pos],add);
		}else{
			ll a1 = posi.Query(in[pos],out[pos]);
			ll a2 = nega.Query(in[pos],out[pos]);
			ll ans = max(a1,a2);
			// cout << a1 << " " << a2 << endl;
			io::Print(ans);
			io::Putc(10);
		}
	}

	END();
}