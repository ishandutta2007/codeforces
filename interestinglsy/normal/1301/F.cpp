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
constexpr int MAXN = 1024;
constexpr int MAXNODE = 1048576;
constexpr int MAXK = 42;
constexpr int dx[] = {0,-1,0,1};
constexpr int dy[] = {1,0,-1,0};

int n,m,k;
int a[MAXN][MAXN];

int id[MAXN][MAXN];
void GetId(){
	int t = 0;
	For(i,n) For(j,m) id[i][j] = ++t;
}

struct Edge{ int to, cost; };
vc<Edge> e[MAXNODE];
vc<int> colIds[MAXK];
void BuildGraph(){
	For(col,k){
		For(i,n) For(j,m) if( a[i][j] == col ) colIds[col].Eb(id[i][j]);
	}
	// For(i,n) For(j,m) colIds[a[i][j]].Eb(id[i][j]);
	// For(col,k){
	// 	int u = col + n*m;
	// 	for( auto v : colIds[col] ){
	// 		e[u].Pb({v,1});
	// 		e[v].Pb({u,0});
	// 	}
	// }
	// For(i,n)
	// 	For(j,m){
	// 		int uCol = a[i][j], uId = id[i][j];
	// 		For0(dir,4){
	// 			int vi = i + dx[dir];
	// 			int vj = j + dy[dir];
	// 			if( vi < 1 or vi > n or vj < 1 or vj > m ) continue;
	// 			int vCol = a[vi][vj], vId = id[vi][vj];
	// 			if( uCol == vCol ) continue;
	// 			e[uId].Pb({vId,1});
	// 			e[vId].Pb({uId,1});
	// 		}
	// 	}
}

int dises[MAXK][MAXNODE];
void ZeroOneBFS( int st , int dis[] ){
	memset(dis,INF,(sizeof dis[0])*(n*m+k+10));
	static deque<int> dq;
	dq.Pb(st);
	dis[st] = 0;
	while(!dq.empty()){
		const int uId = dq.front();
		dq.pop_front();
		const int uDis = dis[uId];
		if( uDis >= 2*k+1 ) continue;

		auto Trans = [&]( int vId , int cost ){
			if( dis[vId] > uDis + cost ){
				dis[vId] = uDis + cost;
				if(!cost) dq.Pf(vId);
				else dq.Pb(vId);
			}
		};

		if( uId > n*m ){
			const int uCol = uId-n*m;
			for( auto vId : colIds[uCol] )
				Trans(vId,1);
		}else{
			const int x = (uId-1)/m + 1;
			const int y = uId - (x-1)*m;
			assert( id[x][y] == uId );
			Trans(a[x][y]+n*m,0);
			For0(dir,4){
				const int vx = x + dx[dir];
				const int vy = y + dy[dir];
				if( vx < 1 or vx > n or vy < 1 or vy > m ) continue;
				if( a[vx][vy] == a[x][y] ) continue;
				Trans(id[vx][vy],1);
			}
		}
	}
}

void GetDises(){
	For(col,k){
		// O(col);
		ZeroOneBFS(col+n*m,dises[col]);
	}
}

int Solve( int stx , int sty , int edx , int edy ){
	if( stx == edx and sty == edy ) return 0;
	const int stId = id[stx][sty], edId = id[edx][edy];
	const int stCol = a[stx][sty], edCol = a[edx][edy];
	int ans1 = abs(stx-edx) + abs(sty-edy);
	int ans2 = dises[stCol][edId];
	int ans3 = INF;
	Forx(vx,stx-42,stx+42){
		if( vx < 1 or vx > n ) continue;
		const int xDelta = abs(stx-vx);
		const int vySt = max(1,sty-(42-xDelta));
		const int vyEd = min(m,sty+(42-xDelta));
		Forx(vy,vySt,vyEd){
			int vId = id[vx][vy], vCol = a[vx][vy];
			int manhDis = xDelta + abs(sty-vy);
			int tans = dises[vCol][edId] + manhDis;
			MyMin(ans3,tans);
		}
	}
	return min({ ans1 , ans2 , ans3 });
}

int main(){
	FILEIO();
	#ifdef intLSY
		Fout(".temp/ans.out");
	#endif

	Read(n,m,k);
	For(i,n) Read(a[i],1,m);

	GetId();
	// B
	BuildGraph();
	// B
	GetDises();
	// END();

	iRead(q);
	For(qwq,q){
		iRead4(stx,sty,edx,edy);
		int ans = Solve(stx,sty,edx,edy);
		printf("%d\n",ans);
	}

	END();
}