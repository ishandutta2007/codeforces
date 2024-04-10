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
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
constexpr int MAXNM = 1048576;

struct Dsu{
	static constexpr int DSUSZ = MAXNM;
	int dsu[DSUSZ];
	il void Init( int sz = DSUSZ-1 ){
		For(i,sz) dsu[i] = i;
	}
	int Findfa( int pos ){
		return dsu[pos] == pos ? pos : dsu[pos] = Findfa(dsu[pos]);
	}
	il bool Unite( int a , int b ){
		a = Findfa(a); b = Findfa(b);
		if( a == b ) return 0;
		dsu[a] = b;
		return 1;
	}
	il bool Same( int a , int b ){
		return Findfa(a) == Findfa(b);
	}
}dsu;

int n;
int col[MAXNM];
int to[MAXNM];
vc<int> back[MAXNM];

void Readin(){
	int m;
	#define Id(x,y) (((x)-1)*m+(y))
	Read(n,m);
	For(i,n)
		For(j,m){
			char col; In.ReadNum(col);
			::col[Id(i,j)] = col == '0';
		}
	For(i,n)
		For(j,m){
			char dir; In.ReadAlpha(dir);
			to[Id(i,j)] = [&](){
				if( dir == 'U' ) return Id(i-1,j);
				if( dir == 'D' ) return Id(i+1,j);
				if( dir == 'L' ) return Id(i,j-1);
				if( dir == 'R' ) return Id(i,j+1);
				cerr << "WTF?" << endl;
			}();
			back[to[Id(i,j)]].Eb(Id(i,j));
		}
	n = n*m;
	#undef Id
}

vc<int> cc[MAXNM];
void BuildDSU(){
	For(i,n) dsu.Unite(i,to[i]);
	For(i,n) cc[dsu.Findfa(i)].Eb(i);
}

bool inCyc[MAXNM];
pii SolveCC( vc<int> &cc ){
	static vc<int> route;
	route.clear();
	static vc<int> cyc;
	cyc.clear();
	static bool vis[MAXNM];
	for( auto x : cc ){
		vis[x] = false;
	}
	int cycLen = 0;
	function<void(int)> Dfs = [&]( int pos ){
		route.Eb(pos);
		vis[pos] = true;
		int v = to[pos];
		if(vis[v]){
			while( route.back() != v ){
				inCyc[route.back()] = true;
				cyc.Eb(route.back());
				++cycLen;
				route.pop_back();
			}
			inCyc[v] = true;
			cyc.Eb(v);
			++cycLen;
		}else{
			Dfs(v);
		}
	};
	Dfs(cc[0]);

	static bool haveDep[MAXNM];
	Forx(i,0,cc.size()+10) haveDep[i] = false;
	int id = 0;
	for( auto st : cyc ){
		function<void(int,int)>
		Dfs = [&]( int pos , int dep ){
			if(col[pos]) haveDep[dep%cycLen] = true;
			for( auto v : back[pos] ){
				if(inCyc[v]) continue;
				Dfs(v,dep+1);
			}
		};
		Dfs(st,id);
		++id;
	}

	int ans2 = 0;
	Forx(i,0,cc.size()+2) ans2 += haveDep[i];

	return {cycLen,ans2};
}

int main(){
	FILEIO();
	dsu.Init();

	iRead(T);
	For(TwT,T){
		Readin();
		BuildDSU();
		pii ans = {0,0};
		For(i,n){
			if(cc[i].empty()) continue;
			pii tans = SolveCC(cc[i]);
			ans.F += tans.F;
			ans.S += tans.S;
		}
		printf("%d %d\n",ans.F,ans.S);

		dsu.Init(n);
		For(i,n){
			back[i].clear();
			cc[i].clear();
			inCyc[i] = false;
		}
	}

	END();
}