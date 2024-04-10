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
	char buf[MAXSZ]; int p;
	il InputReader(){ p = MAXSZ; }
	il void Flush(){ p = 0; fread(buf,1,MAXSZ,stdin); }
	il void GetChar( char &c ){ if(p >= MAXSZ) Flush(); c = buf[p++]; }
	il void ReadNum( char &c ){ GetChar(c); while( !isdigit(c) && c != '-' ) GetChar(c); }
	il void ReadAlpha( char &c ){ GetChar(c); while( !isalpha(c) ) GetChar(c); }
	il void ReadInt( int &ans ){
		ans = 0; int nega = 1;
		char c; ReadNum(c);
		if( c == '-' ){
			nega = -1;
			GetChar(c);
		}
		while(isdigit(c)){
			ans = ans*10 + c-'0';
			GetChar(c);
		}
		ans *= nega;
	}
	il void Readll( ll &ans ){
		ans = 0; int nega = 1;
		char c; ReadNum(c);
		if( c == '-' ){
			nega = -1;
			GetChar(c);
		}
		while(isdigit(c)){
			ans = ans*10 + c-'0';
			GetChar(c);
		}
		ans *= nega;
	}
	il void ReadString( string &x ){
		x.clear(); char ch; GetChar(ch);
		while( !isdigit(ch)  &&  !isalpha(ch)  &&  ch != '#'  &&  ch != '.' ) GetChar(ch);
		while( isdigit(ch)  ||  isalpha(ch)  ||  ch == '#'  ||  ch == '.' ){
			x += ch;
			GetChar(ch);
		}
	}
	il void ReadCString( char s[] ){
		int len = 0; char ch; GetChar(ch);
		while( !isdigit(ch)  &&  !isalpha(ch)  /*&&  ch != '*'  &&  ch != '?'*/ ) GetChar(ch);
		while( isdigit(ch)  ||  isalpha(ch)  /*||  ch == '*'  ||  ch == '?'*/ ){
			s[len++] = ch;
			GetChar(ch);
		}
		s[len] = '\0';
	}
	il void SpecialRead( char &c ){
		GetChar(c);
		while( !isdigit(c) && !isalpha(c) && c != '#'  &&  c != '.'  &&  c != '='  &&  c != 'B' ) GetChar(c);
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
template<typename T>
il void P( T t0 ){
	cerr << t0 << endl;
}
template<typename T, typename... Ts>
il void P( T t0 , Ts... ts ){
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
constexpr int MOD = 998244353;
#define Rmoi(a,b) (((a)%b+b)%b)
#define Rmo(a) (((a)%MOD+MOD)%MOD)
#define Rmod(a) a = ((a%MOD+MOD)%MOD)
#define Rmodi(a,b) a = ((a%(b)+(b))%(b))
#define Mymoi(a,b) ((a)>=b?((a)-b):(a))
#define Mymodi(a,b) a = ((a)>=(b))?((a)-(b)):(a)
template<typename T>
il T Mymo( const T &x ){ return x >= MOD ? x-MOD : x; }
template<typename T>
il void Mymod( T &x ){ x = x >= MOD ? x-MOD : x; }
template<typename T1, typename T2>
il void Addi( T1 &x , const T2 &y ){ x = Mymo(x+y); }
template<typename T1, typename T2>
il void Deci( T1 &x , const T2 &y ){ x = Mymo(x-y+MOD); }
template<typename T1, typename T2>
il void Muli( T1 &x , const T2 &y ){ x = 1LL*x*y%MOD; }
il ll Pow( ll a , ll b , const ll p = MOD ){
	ll ret = 1;
	for( ; b ; a = a*a%p, b >>= 1LL )
		if(b&1LL) ret = ret*a%p;
	return ret;
}
il ll Inv( ll a , const ll p = MOD ){ return Pow(a,p-2LL,p); }

#define FACT 1048576
ll fact[FACT], invfact[FACT];
il void InitFact(){
	fact[0] = 1;
	For(i,FACT-1) fact[i] = fact[i-1]*i % MOD;
	invfact[FACT-1] = Inv(fact[FACT-1]);
	fOR0(i,FACT-1) invfact[i] = invfact[i+1]*(i+1) % MOD;
}
il ll C( int n , int m ){
	if( n < m ) return 0;
	return fact[n] * invfact[m]%MOD * invfact[n-m]%MOD;
}
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
constexpr int MAXN = 262144;
const ll inv3 = Inv(3);

il void RemoveTrailingZero( vc<ll> &a ){
	while( !a.empty() and a.back() == 0 )
		a.pop_back();
}
il void MultX( vc<ll> &a ){
	a.insert(a.begin(),0);
}
void NTT( vc<ll> &a , int n , bool useinv = 0 ){
	int lo = __builtin_ctz(n);
	assert( (1<<lo) == n );
	a.resize(n);
	For0(i,n){
		int v = 0;
		For0(j,lo)
			v |= (i>>j&1) << (lo-j-1);
		if( v < i ) swap(a[i],a[v]);
	}
	for( int len = 2 ; len <= n ; len <<= 1 ){
		int half = len >> 1;
		ll omega_b = Pow(useinv?inv3:3,MOD/len);
		Forstep(st,0,n-1,len){
			ll omega = 1;
			For0(i,half){
				const ll l = a[st+i], r = omega*a[st+i+half] % MOD;
				a[st+i] = Mymo(l+r);
				a[st+i+half] = Mymo(l-r+MOD);
				Muli(omega,omega_b);
			}
		}
	}
	if(useinv){
		const ll invn = Inv(n);
		for( auto &x : a )
			Muli(x,invn);
	}
}
vc<ll> operator*( vc<ll> a , vc<ll> b ){
	int len = 1; while( len < a.size()+b.size() ) len <<= 1;
	NTT(a,len);
	NTT(b,len);
	For0(i,len) Muli(a[i],b[i]);
	NTT(a,len,1);
	RemoveTrailingZero(a);
	return a;
}
void operator*=( vc<ll> &a , vc<ll> b ){
	int len = 1; while( len < a.size()+b.size() ) len <<= 1;
	NTT(a,len);
	NTT(b,len);
	For0(i,len) Muli(a[i],b[i]);
	NTT(a,len,1);
	RemoveTrailingZero(a);
}
vc<ll> operator+( vc<ll> a , const vc<ll> &b ){
	int len = max(a.size(),b.size());
	a.resize(len);
	For0(i,len)
		a[i] = Mymo( a[i] + (i>=b.size()?0:b[i]) );
	return a;
}

int n; ll s;
vc<int> e[MAXN];

int sz[MAXN], gson[MAXN];
void FindGson( int pos , int fa ){
	sz[pos] = 1;
	for( auto v : e[pos] ){
		if( v == fa ) continue;
		FindGson(v,pos);
		sz[pos] += sz[v];
		if( sz[v] > sz[gson[pos]] )
			gson[pos] = v;
	}
}

int top[MAXN], bottom[MAXN];
vc<int> glink[MAXN];
void LinkLine( int pos , int fa , int tp ){
	top[pos] = tp;
	bottom[tp] = pos;
	glink[tp].Eb(pos);
	if(gson[pos])
		LinkLine(gson[pos],pos,tp);
	for( auto v : e[pos] ){
		if( v == fa or v == gson[pos] ) continue;
		LinkLine(v,pos,v);
	}
}

vc<ll> dp[MAXN];
vc<ll> light_prod[MAXN];
pair<vc<ll>,vc<ll>> ChenKuoWenAKIOI( int top , int l , int r ){
	if( l == r ){
		int pos = glink[top][l];
		return {light_prod[pos],light_prod[pos]};
	}
	int mid = l+r >> 1;
	auto lres = ChenKuoWenAKIOI(top,l,mid);
	auto rres = ChenKuoWenAKIOI(top,mid+1,r);
	return {
		lres.F + lres.S*rres.F,
		lres.S*rres.S
	};
}
void Solve( int pos , int fa ){
	light_prod[pos] = {1};
	for( auto v : e[pos] ){
		if( v == fa or v == gson[pos] ) continue;
		Solve(v,pos);
		light_prod[pos] *= dp[v];
	}
	MultX(light_prod[pos]);
	if(gson[pos]) Solve(gson[pos],pos);
	if( top[pos] == pos ){
		dp[pos] = ChenKuoWenAKIOI(pos,0,glink[pos].size()-1).F;
		dp[pos][0]++;
	}
}

ll GetFinalAns(){
	ll ans = 0;
	ll uc = 1;
	For(i,n){
		ll tans = uc*dp[1][i] % MOD;
		Addi( ans , tans );
		uc = uc * ((s+i)%MOD)%MOD * Inv(i) % MOD;
	}
	return ans;
}

int main(){
	FILEIO();
	InitFact();

	Read(n); Read(s);
	For(i,n-1){
		iRead2(a,b);
		e[a].Eb(b);
		e[b].Eb(a);
	}

	FindGson(1,0);
	LinkLine(1,0,1);

	Solve(1,0);
	ll ans = GetFinalAns();
	cout << ans << endl;

	END();
}