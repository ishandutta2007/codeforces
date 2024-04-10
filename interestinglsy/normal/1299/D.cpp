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
constexpr int MOD = 1000000007;
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
	for( ; b ; a = a*a%p, b >>= 1 )
		if(b&1) ret = ret*a%p;
	return ret;
}
il ll Inv( ll a , const ll p = MOD ){ return Pow(a,p-2LL,p); }
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
constexpr int MAXN = 131072;

int n,m;
struct Edge{ int to, w; };
vc<Edge> e[MAXN];

struct LinerBasis{
	int b[6], cnt;
	// LinerBasis(){ Ms(b); }
	il void Clear(){ Ms(b); cnt = 0; };
	il bool Insert( int x ){
		fOR0(i,5){
			if(x>>i&1^1) continue;
			if(b[i]){
				x ^= b[i];
			}else{
				b[i] = x;
				++cnt;
				return true;
			}
		}
		return false;
	}
	il bool Insert( const LinerBasis &y ){
		if( cnt + y.cnt > 5 ) return false;
		cnt += y.cnt;
		For0(i,5)
			if(y.b[i]){
				bool ok = Insert(y.b[i]);
				if(!ok) return false;
			}
		return true;
	}
};
il int GetHsh( const LinerBasis &lb ){
	int ans = 0;
	ans = lb.b[0]?0:1;
	ans = ans*3 + (lb.b[1]?(lb.b[1]&1):2);
	ans = ans*5 + (lb.b[2]?(lb.b[2]&3):4);
	ans = ans*9 + (lb.b[3]?(lb.b[3]&7):8);
	ans = ans*17 + (lb.b[4]?(lb.b[4]&15):16);
	return ans;
}
il LinerBasis Extract( int hsh ){
	static LinerBasis ans;
	// ans.Clear();
	ans.b[4] = hsh%17 == 16 ? 0 : hsh%17+16; hsh /= 17;
	ans.b[3] = hsh%9 == 8 ? 0 : hsh%9+8; hsh /= 9;
	ans.b[2] = hsh%5 == 4 ? 0 : hsh%5+4; hsh /= 5;
	ans.b[1] = hsh%3 == 2 ? 0 : hsh%3+2; hsh /= 3;
	// assert( hsh == 0 or hsh == 1 );
	ans.b[0] = hsh == 0 ? 1 : 0;
	return ans;
}

bool isAdj1[MAXN];
vc<int> adj1s;
LinerBasis adjBasis[MAXN];
bool adjHave0[MAXN];
int adjW[MAXN];
struct E{ bool type; int v1,v2; int x1,x2,a; };
vc<E> es;
void AnalysisGraph(){
	for( auto [v,w] : e[1] ){
		isAdj1[v] = true;
		adj1s.Eb(v);
		adjW[v] = w;
	}
	static int in[MAXN], nowTime = 0;
	static int xorSum[MAXN];
	function<void(int,int,LinerBasis&,bool&)> Dfs = [&]( int pos , int fa , LinerBasis &lb , bool &have0 ){
		in[pos] = ++nowTime;
		// O(pos);
		for( auto [v,w] : e[pos] ){
			if( v == fa or isAdj1[v] or v == 1 ) continue;
			if(!in[v]){
				xorSum[v] = xorSum[pos] ^ w;
				Dfs(v,pos,lb,have0);
			}else{
				if( in[pos] < in[v] ){
					int cycW = xorSum[v]^xorSum[pos]^w;
					// P(pos,v);
					bool ok = lb.Insert(cycW);
					// O(ok);
					if(!ok) have0 = 1;
				}
			}
		}
	};
	for( auto v : adj1s ){
		Dfs(v,1,adjBasis[v],adjHave0[v]);
	}
	static bool vis[MAXN];
	Ms(vis);
	for( auto [v1,w1] : e[1] ){
		if(vis[v1]) continue;
		vis[v1] = 1;
		int v2 = -1, a;
		for( auto [v,w] : e[v1] ){
			if( v == 1 or !isAdj1[v] ) continue;
			v2 = v; a = w;
		}
		if( v2 == -1 ){
			es.Pb({ 0 , v1 , -1 , w1 , -1 , -1 });
		}else{
			vis[v2] = 1;
			es.Pb({ 1 , v1 , v2 , w1 , adjW[v2] , a });
		}
	}
}

constexpr int MAXHSH = 4589;
vc<pii> okHsh[4600];
int aftInsHsh[32][4600];
void GetOkHsh(){
	Forx(i,0,MAXHSH){
		Forx(j,i,MAXHSH){
			static LinerBasis lb;
			lb = Extract(i);
			bool ok = lb.Insert(Extract(j));
			int hsh = GetHsh(lb);
			if(ok){
				okHsh[i].Eb(j,hsh);
				if( i != j ) okHsh[j].Eb(i,hsh);
			}
		}
		Forx(j,0,31){
			LinerBasis lb = Extract(i);
			bool ok = lb.Insert(j);
			aftInsHsh[j][i] = ok ? GetHsh(lb) : -1;
		}
	}
}

int dp[2][4600];
void Dp(){
	int cur = 0;
	constexpr int fullHsh = 4589;
	dp[cur][fullHsh] = 1;
	for( auto e : es ){
		if( adjHave0[e.v1] or (e.type&&adjHave0[e.v2]) ) continue;
		static LinerBasis merged;
		if(e.type){
			merged = adjBasis[e.v1];
			bool ok = merged.Insert(adjBasis[e.v2]);
			if(!ok) continue;
		}
		int last = cur; cur ^= 1;
		auto bdp = dp[last];
		auto udp = dp[cur];
		memcpy(udp,bdp,sizeof dp[0]);

		int hsh = e.type == 0 ? GetHsh(adjBasis[e.v1]) : GetHsh(merged);
		for( auto [i,nHsh] : okHsh[hsh] ){
			if(!bdp[i]) continue;
			if(!e.type){
				Addi(udp[nHsh],bdp[i]);
			}else{
				Addi(udp[nHsh],bdp[i]);
				Addi(udp[nHsh],bdp[i]);

				nHsh = aftInsHsh[e.x1^e.x2^e.a][nHsh];
				if( nHsh != -1 )
					Addi(udp[nHsh],bdp[i]);
			}
		}
	}
	int ans = 0;
	Forx(i,0,fullHsh) Addi(ans,dp[cur][i]);
	cout << ans << endl;
}

int main(){
	FILEIO();
	GetOkHsh();

	// END();

	Read(n,m);
	For(i,m){
		iRead3(a,b,c);
		e[a].Pb({b,c});
		e[b].Pb({a,c});
	}

	if( n == 1 ) END(1);

	AnalysisGraph();

	// LinerBasis b;
	// b.Clear();
	// O(GetHsh(b));
	Dp();

	END();
}