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
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
/*

*/
// #undef ll
// #define ll unsigned long long
const int MAXN = 262144;
const int LOG = 20;

const int SGTSZ = 524288;
struct SGT{
	#define LSON l,l+r>>1,pos<<1
	#define RSON (l+r>>1)+1,r,pos<<1|1
	#define ROOT 1,n+n-1,1
	#define ARG int l , int r , int pos
	ll t[SGTSZ], add[SGTSZ];
	// il SGT(){
		// Msn(t,-INF);
		// Ms(add);
	// }
	il void Update( int pos ){
		t[pos] = max( t[pos<<1] , t[pos<<1|1] );
	}
	il void Push(ARG){
		if( add[pos] == 0 ) return;
		int mid = l+r >> 1;
		t[pos<<1] += add[pos];
		add[pos<<1] += add[pos];
		t[pos<<1|1] += add[pos];
		add[pos<<1|1] += add[pos];
		add[pos] = 0;
	}
	void Set( int gpos , const ll &x , ARG ){
		if( l == r ){
			t[pos] = x;
			return;
		}
		Push(l,r,pos);
		int mid = l+r >> 1;
		if( gpos <= mid ) Set(gpos,x,LSON);
		else Set(gpos,x,RSON);
		Update(pos);
	}
	void Add( int gl , int gr , ll x , ARG ){
		if( gl <= l and r <= gr ){
			t[pos] += x;
			add[pos] += x;
			return;
		}
		Push(l,r,pos);
		int mid = l+r >> 1;
		if( gl <= mid ) Add(gl,gr,x,LSON);
		if( gr > mid ) Add(gl,gr,x,RSON);
		Update(pos);
	}
	ll Query( int gl , int gr , ARG ){
		if( gl <= l and r <= gr ) return t[pos];
		Push(l,r,pos);
		int mid = l+r >> 1;
		if( gr <= mid ) return Query(gl,gr,LSON);
		if( gl > mid ) return Query(gl,gr,RSON);
		return max( Query(gl,gr,LSON) , Query(gl,gr,RSON) );
	}
}sgt[LOG];

int n,q; ll wlim;
vc<int> e[MAXN];
ll w[MAXN];
ll ans = 0;

int root;
vc<int> de[MAXN]; int defa[MAXN];
multiset<ll> anses_set;
ll anses[MAXN];

bool vis[MAXN];
int in[LOG][MAXN], out[LOG][MAXN], nowtime[LOG];
int inlay[MAXN], from[LOG][MAXN];
multiset<ll> mxs[MAXN];
void GetSz( int pos , int fa , int sz[] , int weight[] , vc<int> &past ){
	sz[pos] = 1;
	weight[pos] = 0;
	past.Eb(pos);
	for( auto v : e[pos] ){
		if( v == fa or vis[v] ) continue;
		GetSz(v,pos,sz,weight,past);
		sz[pos] += sz[v];
		Mymax(weight[pos],sz[v]);
	}
}
int FindG( int pos ){
	static int sz[MAXN], weight[MAXN];
	static vc<int> past; past.clear();
	GetSz(pos,0,sz,weight,past);
	int tot = sz[pos], min_weight = INF, g = -1;
	for( auto p : past ){
		Mymax(weight[p],tot-sz[p]);
		if( weight[p] < min_weight ){
			min_weight = weight[p];
			g = p;
		}
	}
	return g;
}

ll GetAns( int pos ){
	if(mxs[pos].empty()) return w[pos];
	auto p = mxs[pos].rbegin();
	return (mxs[pos].size() == 1 ? *p : *p + *next(p)) + w[pos];
}
void InitDfs( int pos , int fa , int lay , int fr , ll dep , ll &maxdep ){
	in[lay][pos] = ++nowtime[lay];
	from[lay][pos] = fr;
	dep += w[pos];
	sgt[lay].Set(in[lay][pos],dep,ROOT);
	Mymax(maxdep,dep);
	for( auto v : e[pos] ){
		if( v == fa or vis[v] ) continue;
		InitDfs(v,pos,lay,fr,dep,maxdep);
	}
	out[lay][pos] = nowtime[lay];
}
void InitLayerData( int pos , int lay ){
	in[lay][pos] = ++nowtime[lay];
	for( auto v : e[pos] ){
		if(vis[v]) continue;
		ll mxdep = 0;
		InitDfs(v,pos,lay,v,0,mxdep);
		mxs[pos].insert(mxdep);
	}
	// cout << pos << endl;
	// for( auto v : mxs[pos] ) cout << v << " ";
	// cout << endl;
	out[lay][pos] = nowtime[lay];
	anses[pos] = GetAns(pos);
	anses_set.insert(anses[pos]);
}
void PreDfs( int g , int lay ){
	// cout << g << " " << lay << endl;
	inlay[g] = lay;
	InitLayerData(g,lay);
	vis[g] = 1;
	for( auto v : e[g] ){
		if(vis[v]) continue;
		int vg = FindG(v);
		de[g].Pb(vg);
		defa[vg] = g;
		PreDfs(vg,lay+1);
	}
}

il void Rein( int pos ){
	anses_set.erase(anses_set.find(anses[pos]));
	anses[pos] = GetAns(pos);
	anses_set.insert(anses[pos]);
}
void Modify( int pos , ll delta ){
	int opos = pos;
	Rein(pos);
	pos = defa[pos];
	while(pos){
		int lay = inlay[pos];
		int ov = from[lay][opos];
		mxs[pos].erase(mxs[pos].find(sgt[lay].Query(in[lay][ov],out[lay][ov],ROOT)));
		sgt[lay].Add(in[lay][opos],out[lay][opos],delta,ROOT);
		mxs[pos].insert(sgt[lay].Query(in[lay][ov],out[lay][ov],ROOT));
		Rein(pos);
		pos = defa[pos];
	}
}

int main(){
	FILEIO();
	// ios_base::sync_with_stdio(false);
	// cin.tie(0); cout.tie(0);

	Read(n,q); Read(wlim);
	For(i,n-1){
		iRead2(a,b); lRead(c);
		int p = i+n;
		w[p] = c;
		e[a].Pb(p); e[p].Pb(a);
		e[b].Pb(p); e[p].Pb(b);
	}

	root = FindG(1);
	PreDfs(root,1);
	// Print(anses,1,n+n-1);

	For(qi,q){
		lRead2(pos,x);
		pos = (pos+ans)%(n-1) + n + 1;
		x = (x+ans)%wlim;
		ll delta = x - w[pos];
		w[pos] = x;
		Modify(pos,delta);
		// cout << pos << " " << x << endl;

		ans = *anses_set.rbegin();
		#ifdef WIN32
			printf("%I64d\n",ans);
		#else
			printf("%lld\n",ans);
		#endif
		// Print(anses,1,n+n-1);
	}

	END();
}