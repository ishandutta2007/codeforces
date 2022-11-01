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
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define Mymax(a,b) (a) = max((a),(b))
#define Mymin(a,b) (a) = min((a),(b))
#define INF (0x3f3f3f3f)
#define LINF ((long long)(0x3f3f3f3f3f3f3f3f))
#define Sqr(x) ((x)*(x))
#define Lowbit(a) ((a)&(-(a)))
vc<int> Range( int l , int r ){
	vc<int> ret{};
	Forx(i,l,r) ret.Pb(i);
	return ret;
}
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
#define MAXN 262144

int n,m;

vc<int> e[MAXN];
int dsu[MAXN];
int d[MAXN];
vc<int> ansl;
int mem[MAXN][3];
int tran[MAXN][3], tran2[MAXN][3];
void Init(){
	For(i,n){
		dsu[i] = i;
		e[i].clear();
		d[i] = 0;
		mem[i][0] = mem[i][1] = mem[i][2] = -1;
	}
	ansl.clear();
}
int Findfa( int pos ){ return dsu[pos] == pos ? pos : dsu[pos] = Findfa(dsu[pos]); }
bool Unite( int a , int b ){
	a = Findfa(a);
	b = Findfa(b);
	if( a == b ) return 0;
	dsu[a] = b;
	return 1;
}

int Dfs( int pos , int stat , int fa ){	// stat = 0: (nofa), stat = 1: , stat = 2: fa
	if( mem[pos][stat] != -1 ) return mem[pos][stat];
	if( stat == 1 ){
		tran[pos][stat] = 1;
		int ans = 1;
		for( auto v : e[pos] ){
			if( v == fa ) continue;
			int tans = Dfs(v,2,pos);
			ans += tans;
		}
		return mem[pos][stat] = ans;
	}elif( stat == 0 ){
		int ans = INF;
		For0(uput,2){
			int tans = uput;
			if( uput == 1 ){
				for( auto v : e[pos] ){
					if( v == fa ) continue;
					tans += Dfs(v,2,pos);
				}
			}else{
				int sum0 = 0;
				for( auto v : e[pos] ){
					if( v == fa ) continue;
					sum0 += Dfs(v,0,pos);
				}
				int ttans = INF;
				for( auto v : e[pos] ){
					if( v == fa ) continue;
					int tttans = sum0 - Dfs(v,0,pos) + Dfs(v,1,pos);
					if( ttans > tttans ){
						ttans = tttans;
						tran2[pos][stat] = v;
					}
				}
				tans += ttans;
			}
			if( ans > tans ){
				ans = tans;
				tran[pos][stat] = uput;
			}
		}
		return mem[pos][stat] = ans;
	}else{
		int ans = INF;
		For0(uput,2){
			int tans = uput;
			for( auto v : e[pos] ){
				if( v == fa ) continue;
				tans += Dfs(v,uput?2:0,pos);
			}
			if( tans < ans ){
				ans = tans;
				tran[pos][stat] = uput;
			}
		}
		return mem[pos][stat] = ans;
	}
}
void FindAns( int pos , int stat , int fa ){
	int isput = tran[pos][stat];
	if(isput) ansl.Pb(pos);
	if( stat == 1 ){
		for( auto v : e[pos] )
			if( v != fa )
				FindAns(v,2,pos);
	}elif( stat == 0 ){
		if(isput){
			for( auto v : e[pos] )
				if( v != fa )
					FindAns(v,2,pos);
		}else{
			for( auto v : e[pos] ){
				if( v == fa ) continue;
				FindAns(v,v==tran2[pos][stat]?1:0,pos);
			}
		}
	}else{
		if(isput){
			for( auto v : e[pos] )
				if( v != fa )
					FindAns(v,2,pos);
		}else{
			for( auto v : e[pos] )
				if( v != fa )
					FindAns(v,0,pos);
		}
	}
}

int main(){
	FILEIO();
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	iRead(T);
	For(Ti,T){
		Init();
		Read(n,m);
		Init();
		For(i,m){
			iRead2(a,b);
			if(Unite(a,b)){
				e[a].Pb(b);
				e[b].Pb(a);
				++d[a];
				++d[b];
				// B
			}
		}
		int cost = Dfs(1,0,0);
		FindAns(1,0,0);
		// O(cost);
		cout << ansl.size() << endl;
		Print(ansl);
	}

	END();
}