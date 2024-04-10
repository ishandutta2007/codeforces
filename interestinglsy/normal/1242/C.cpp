// InterestingLSY
// 2659723130
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
#if __cplusplus >= 201703L
template<typename T, typename... Ts>
void P( T t0 , Ts... ts ){
    cerr << t0 << " ";
    if constexpr(sizeof...(ts)>0) P(ts...);
    else cerr << endl;
}
#else
template<typename T, typename... Ts>
void P( T t0 , Ts... ts ){
    // I love cpp17.
    // Fuck you.
}
#endif
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
mt19937 Rand(0xe38195e38293);	// 
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
constexpr int MAXN = 18;
constexpr int MAXNUM = 75100;
constexpr int MAXMASK = 32768;

int n,m;
vc<int> a[MAXN];
map<ll,int> inbox;
ll suma[MAXN];
ll allsum = 0;

vc<int> ds;
il int ToVir( int x ){
	return lower_bound(All(ds),x) - ds.begin() + 1;
}
il int ToReal( int x ){
	return ds[x-1];
}
void Disc(){
	For(i,n)
		for( auto x : a[i] )
			ds.Eb(x);
	sort(All(ds));
	m = ds.size();
}

bool isok[MAXMASK];
struct Operation{ int box1, num, box2; };
vc<Operation> subset_ops[MAXMASK];

struct Edge{ int from, to, box1, box2; };
Edge to[MAXNUM];
void BuildGraph(){
	For(i,n){
		if( suma[i] == allsum/n ){
			isok[1<<i>>1] = 1;
			subset_ops[1<<i>>1] = {{i,a[i][0],i}};
			continue;
		}
		for( auto taken : a[i] ){
			ll put = allsum/n - suma[i] + taken;
			if( not inbox.count(put) or inbox[put] == i )
				continue;
			// P(taken,put,ToVir(taken),ToVir(put));
			// P(i,inbox[put]);
			to[ToVir(taken)] = {ToVir(taken),ToVir(put),i,inbox[put]};
		}
	}
}

int vis[MAXNUM];
vc<Edge> been;
void FindCycle( int pos , int token ){
	vis[pos] = token;
	int v = to[pos].to;
	if(!v) return;
	been.Pb(to[pos]);
	if(vis[v]){
		if( vis[v] != token ) return;

		static bool box_used[MAXN];
		Ms(box_used);
		static vc<Operation> tmp_ops;
		tmp_ops.clear();

		reverse(All(been));
		bool is_first = true, failed = false;
		for( auto [from,to,box1,box2] : been ){
			if( to == v ){
				if(!is_first) break;
			}
			is_first = false;
			if(box_used[box2]){
				failed = true;
				break;
			}
			box_used[box2] = true;
			tmp_ops.Pb({box1,ToReal(from),box2});
		}
		if(!failed){
			int mask = 0;
			For(i,n)
				if(box_used[i])
					mask |= 1<<i>>1;
			isok[mask] = 1;
			subset_ops[mask] = tmp_ops;
			// O(mask);
		}
		return;
	}else
		FindCycle(v,token);
}
void GetIsok(){
	For(i,m){
		if(vis[i]) continue;
		static int token = 233; ++token;
		been.clear();
		FindCycle(i,token);
	}
}

int mem[MAXMASK];
int trans[MAXMASK];
bool Dfs( int mask ){
	if(!mask) return 1;
	if(~mem[mask]) return mem[mask];
	for( int sub = mask ; sub ; sub = (sub-1)&mask ){
		if(!isok[sub]) continue;
		if(Dfs(mask^sub)){
			trans[mask] = sub;
			return mem[mask] = 1;
		}
	}
	return mem[mask] = 0;
}

Operation ansl[MAXN];
void FindAnswer( int mask ){
	if(!mask) return;
	for( auto op : subset_ops[trans[mask]] )
		ansl[op.box1] = op;
	FindAnswer(mask^trans[mask]);
}
void Dp(){
	Msn(mem,-1);
	bool ok = Dfs((1<<n)-1);
	if(!ok) END("No");
	puts("Yes");
	FindAnswer((1<<n)-1);
}

void Fix(){
	static int p_inv[MAXN];
	For(i,n) p_inv[ansl[i].box2] = i;
	For(i,n) ansl[i].box2 = p_inv[i];
}

int main(){
	FILEIO();

	Read(n);
	For(i,n){
		iRead(cnt);
		For(j,cnt){
			iRead(x);
			inbox[x] = i;
			a[i].Eb(x);
			suma[i] += x;
			allsum += x;
		}
	}

	if(abs(allsum)%n) END("No");

	Disc();
	BuildGraph();
	GetIsok();
	Dp();
	Fix();

	For(i,n)
		printf("%d %d\n",ansl[i].num,ansl[i].box2);

	END();
}