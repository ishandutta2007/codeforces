#pragma GCC optimize(3)
#pragma GCC optimize("fast-math")
// InterestingLSY
// 2659723130
// 
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
#define O(x) cerr << #x << " " << (x) << endl;
#define o(x) cerr << #x << " " << (x) << "  ";
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
// #undef ld
#define ld long double
constexpr ld Eps = 1e-7;
constexpr ld PI = 3.14159265358979323846264338327950288419716939937510;
#define Equal(a,b) (fabs((a)-(b))<=Eps)
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
const int MAXN = 10010;
const int LOG = 16;

struct Point{
	ld x,y;
	il ld Len()const{ return sqrt(Sqr(x)+Sqr(y)); }
};
il Point operator+( const Point &a , const Point &b ){ return {a.x+b.x,a.y+b.y}; }
il Point operator-( const Point &a , const Point &b ){ return {a.x-b.x,a.y-b.y}; }
il ld operator^( const Point &a , const Point &b ){ return a.x*b.x + a.y*b.y; }
il ld operator*( const Point &a , const Point &b ){ return a.x*b.y - a.y*b.x; }
il Point operator*( const Point &a , const ld &b ){ return {a.x*b,a.y*b}; }
il Point operator/( const Point &a , const ld &b ){ return {a.x/b,a.y/b}; }
il ld Dis( const Point &a , const Point &b ){ return sqrt(Sqr(a.x-b.x)+Sqr(a.y-b.y)); }
il ld Dis2( const Point &a , const Point &b ){ return Sqr(a.x-b.x)+Sqr(a.y-b.y); }
ostream& operator<<( ostream &out , const Point &p ){
	out << p.x << " " << p.y << "  ";
	return out;
}
il bool TurnLeft( const Point &a , const Point &b , const Point &c ){
	return (b-a)*(c-b) > Eps;
}
il bool TurnRight( const Point &a , const Point &b , const Point &c ){
	return (b-a)*(c-b) < -Eps;
}
il bool OnLine( const Point &p , const Point &a1 , const Point &a2 ){
	return Equal((p-a1)*(a2-p),0) and ((p-a1)^(a2-p)) > -Eps;
}
il bool Intersect( const Point &a , const Point &b , const Point &c , const Point &d ){
	if( OnLine(a,c,d) or OnLine(b,c,d) ) return 1;
	return (TurnRight(c,a,d)^TurnRight(c,b,d)) and (TurnRight(a,c,b)^TurnRight(a,d,b));
}
il Point InsPoint( const Point &p1 , const Point &p2 , const Point &p3 , const Point &p4 ){
	const ld dis = Dis(p1,p2);
	ld d1 = fabs((p2-p3)*(p3-p1)) / dis;
	ld d2 = fabs((p2-p4)*(p4-p1)) / dis;
	ld ratio = d1 / (d1+d2);
	return (p4-p3)*ratio + p3;
}

int n,q;
Point a[MAXN],o;
ld a_area;
ld cross_psum[MAXN];

il int Next( const int &x ){ return x == n ? 1 : x+1; }
ld PolyArea( Point a[] , int n ){
	ld ans = 0;
	Forx(i,2,n-1) ans += (a[i]-a[1])*(a[i+1]-a[1]);
	return fabs(ans)/2;
}

//  od   a[i] a[i+1] 
int Crossed( const Point &d ){
	if( Intersect(a[1],a[n],o,d) ) return n;
	// if( Intersect(a[1],a[2],o,d) ) return 1;
	const ld odlen = (d-o).Len();
	const Point od_div_odlen = (d-o) / odlen;
	auto GetPolarAngle = [=]( const Point &p ){
		const Point od = d-o, op = p-o;
		ld h = fabs(od_div_odlen*op);
		ld theta = h/op.Len();
		if( (od^op) > 0 ){
			if( od*op > 0 ) return theta;	// 4
			else return PI+PI-theta;	// 1
		}else{
			if( od*op > 0 ) return PI-theta;	// 3
			else return theta+PI;	// 2
		}
	};
	ld init_polar_angle = GetPolarAngle(a[1]);
	int ans = 1;
	fOR0(i,LOG){
		// binary lifting
		int v = ans + (1<<i);
		if( v >= n ) continue;
		if( GetPolarAngle(a[v]) > init_polar_angle )
			ans = v;
	}
	if( ans != 1 and Intersect(a[ans-1],a[ans],o,d) ) --ans;
	return ans;
}

ld F( ld alpha ){
	const ld sinres = sin(alpha), cosres = cos(alpha);
	const ld MULT = 1e9;
	Point d = o + Point{cosres*MULT,sinres*MULT};
	Point nd = o - Point{cosres*MULT,sinres*MULT};
	int ans_mult = 1;
	if(TurnLeft(nd,a[1],d)){
		swap(d,nd);
		ans_mult = -1;
	}
	int l = Crossed(nd);
	int r = Crossed(d);
	Point lins = InsPoint(a[l],a[Next(l)],o,nd);
	Point rins = InsPoint(a[r],a[Next(r)],o,d);
	r = Next(r);
	ld area1 = cross_psum[l] + (r==1?0:cross_psum[n]-cross_psum[r]) + fabs((a[l]-a[1])*(a[r]-a[1]))/2;
	area1 += fabs((rins-lins)*(a[l]-lins))/2;
	area1 += fabs((a[r]-a[l])*(rins-a[l]))/2;
	ld area2 = a_area - area1;
	return (area1-area2)*ans_mult;
}

ld Solve(){
	const ld allow_abs_delta = (5e-5) * a_area;
	ld l = 0, r = PI, l_fres = F(l), r_fres = F(r);
	// o(l_fres); O(r_fres);
	ld ans = -1, min_abs_delta = LINF;
	if( fabs(l_fres) < allow_abs_delta ) return l;
	if( fabs(r_fres) < allow_abs_delta ) return r;
	For(_t,50){
		ld mid = (l+r) / 2;
		ld mid_fres = F(mid);
		// cout << mid << " " << mid_fres << endl;
		if( fabs(mid_fres) < min_abs_delta ){
			min_abs_delta = fabs(mid_fres);
			ans = mid;
		}
		if( min_abs_delta <= allow_abs_delta )
			break;
		if( (mid_fres>0) == (l_fres>0) ) l = mid+Eps;
		else r = mid-Eps;
	}
	// O(F(ans));
	return ans;
}

int main(){
	FILEIO();
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	// #ifdef intLSY
		// Fout("ans.out");
	// #endif

	cin >> n >> q;
	For(i,n) cin >> a[i].x >> a[i].y;
	reverse(a+1,a+1+n);
	a_area = PolyArea(a,n);
	// Print(a,1,n);
	// O(a_area);

	Forx(i,3,n){
		cross_psum[i] = cross_psum[i-1] + fabs((a[i]-a[1])*(a[i-1]-a[1]))/2;
	}

	For(qi,q){
		cin >> o.x >> o.y;
		ld ans = Solve();
		// if( q == 9876 ){
		// 	if( qi == 3139 ) cout << o.x << " " << o.y << endl;
		// }else
			cout << setprecision(16) << fixed << ans << endl;
	}

	END();
}