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
#define Mymin(a,b) (a) = min(a,b)
#define MyMax(a,b) (a) = Max((a),(b))
#define MyMin(a,b) (a) = Min((a),(b))
#define INF (0x3f3f3f3f)
#define LINF ((long long)(0x3f3f3f3f3f3f3f3f))
#define Sqr(x) ((x)*(x))
#define Lowbit(a) ((a)&(-(a)))
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
constexpr int MAXN = 150010;
#undef ld

int n;
vc<int> e[MAXN];
ll a[MAXN];
ll ans = 0;

bool vis[MAXN];
int sz[MAXN];
int FindCentroid( int pos , int overallSize ){
	pii res = {INF,0};
	function<void(int,int)> Dfs = [&]( int pos , int fa ){
		sz[pos] = 1;
		int mxsz = 0;
		for( auto v : e[pos] ){
			if( v == fa or vis[v] ) continue;
			Dfs(v,pos);
			MyMax(mxsz,sz[v]);
			sz[pos] += sz[v];
		}
		Mymax(mxsz,overallSize-sz[pos]);
		Mymin(res,(pii{mxsz,pos}));
	};
	Dfs(pos,0);
	return res.S;
}

void CalcAnswer( int pos , int overallSize ){
	if( overallSize == 1 ){
		MyMax(ans,a[pos]);
		return;
	}

	struct Event{
		bool isAddLine;
		ll k,b;
	};
	static vc<Event> events;
	events.clear();

	struct Path{ ll psum, ssum, sum; int len; };
	function<void(int,int,Path,function<void(Path)>)>
	Dfs = [&]( int pos , int fa , Path path , const auto &onEnter ){
		onEnter(path);
		for( auto v : e[pos] ){
			if( v == fa or vis[v] ) continue;
			Path vPath = {
				path.psum + (path.len+1)*a[v],
				path.ssum + path.sum + a[v],
				path.sum + a[v],
				path.len + 1
			};
			Dfs(v,pos,vPath,onEnter);
		}
	};

	events.Pb({ true , 0 , 0 });
	for( auto v : e[pos] ){
		if(vis[v]) continue;
		Dfs(v,pos,{a[pos]+a[v]*2,a[pos]*2+a[v],a[pos]+a[v],2},[&]( Path path ){
			events.Pb({
				false,
				path.sum, path.psum
			});
		});
		Dfs(v,pos,{a[v],a[v],a[v],1},[&]( Path path ){
			events.Pb({
				true,
				path.len, path.ssum
			});
		});
	}
	events.Pb({ false , a[pos] , a[pos] });

	{
		// Brute Force
		/*
		static vc<pll> lines;
		lines.clear();
		for( auto [isAddLine,k,b] : events ){
			if(isAddLine) lines.Pb({k,b});
			else{
				ll tans = 0;
				ll x = k;
				for( auto [k,b] : lines ) MyMax(tans,x*k+b);
				tans += b;
				MyMax(ans,tans);
			}
		}
		return;
		*/
	}

	struct ConvexHullKeeper{
		struct Line{ ll k,b; };
		bool CanPop( const Line &l1 , const Line &l2 , const Line &l3 ){
			typedef long double ld;
			ld ins12 = (ld)(l1.b-l2.b) / (l2.k-l1.k);
			ld ins23 = (ld)(l2.b-l3.b) / (l3.k-l2.k);
			return ins12 > ins23;
		};

		vc<Line> lines;
		vc<Line> hull;

		void Clear(){
			lines.clear();
			hull.clear();
		}
		il void AddLine( const Line &l ){
			lines.Eb(l);
		}
		il void BuildHull(){
			sort(All(lines),[]( const Line &a , const Line &b ){
				return a.k != b.k ? a.k < b.k : a.b > b.b;
			});
			for( auto ul : lines ){
				if( !hull.empty() and hull.back().k == ul.k ) continue;
				while( !hull.empty() and hull.back().b <= ul.b ) hull.pop_back();
				while( hull.size() >= 2 and CanPop(hull[hull.size()-2],hull.back(),ul) )
					hull.pop_back();
				hull.Eb(ul);
			}
		}
		il ll QueryMaxY( ll x ){
			ll ans = 0;
			for( auto [k,b] : hull ) Mymax(ans,k*x+b);
			return ans;
		}

	}hullKeeper;

	function<void(int,int)> CdqDAC = [&]( int l , int r ){
		if( l == r ) return;
		int mid = l+r >> 1;

		hullKeeper.Clear();
		Forx(i,l,mid)
			if(events[i].isAddLine)
				hullKeeper.AddLine({events[i].k,events[i].b});
		hullKeeper.BuildHull();
		Forx(i,mid+1,r)
			if(!events[i].isAddLine){
				ll tans = hullKeeper.QueryMaxY(events[i].k) + events[i].b;
				MyMax(ans,tans);
			}

		CdqDAC(l,mid);
		CdqDAC(mid+1,r);
	};
	CdqDAC(0,(int)events.size()-1);
}

void TreeDAC( int _pos , int overallSize ){
	int g = FindCentroid(_pos,overallSize);
	CalcAnswer(g,overallSize);
	reverse(All(e[g]));
	CalcAnswer(g,overallSize);
	vis[g] = 1;
	for( auto v : e[g] ){
		if(vis[v]) continue;
		int vsz = sz[v] > sz[g] ? sz[_pos]-sz[g] : sz[v];
		TreeDAC(v,vsz);
	}
}

int main(){
	FILEIO();

	Read(n);
	For(i,n-1){
		iRead2(a,b);
		e[a].Eb(b);
		e[b].Eb(a);
	}
	Read(a,1,n);

	int root = 1;
	TreeDAC(root,n);

	cout << ans << endl;

	END();
}