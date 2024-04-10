// InterestingLSY
// codeforces&github: interestingLSY, qq: 2659723130
#ifdef intLSY
#include <intlsy/stdc++.h>
#else
#include <bits/stdc++.h>
#endif
using namespace std;
#define elif else if
#define ld double
#define ll long long
#define ull unsigned ll
#define all(x) x.begin(),x.end()
#define memset0(_data) memset(_data,0,sizeof(_data))
#define memsetn(_data,_num) memset(_data,_num,sizeof(_data))
#define For(i,j) for( int (i) = 1 ; (i) <= (j) ; ++(i) )
#define For0(i,j) for( int (i) = 0 ; (i) < (j) ; ++(i) )
#define Forx(i,j,k) for( int (i) = (j) ; (i) <= (k) ; ++(i) )
#define Forstep(i,j,k,st) for( int (i) = (j) ; (i) <= (k) ; (i) += (st) )
#define fOR(i,j) for( int (i) = (j) ; (i) >= 1 ; --(i) )
#define fOR0(i,j) for( int (i) = (j)-1 ; (i) >= 0 ; --(i) )
#define fORx(i,j,k) for( int (i) = (k) ; (i) >= (j) ; --(i) )
struct _FileOpener {
	_FileOpener() {
		#ifdef intLSY
			freopen("in.txt", "r", stdin);
		#endif
	}
}_file_opener;
struct _TimePrinter {
	~_TimePrinter() {
		#ifdef intLSY
			double _timeuse = clock()* 1000.0 / CLOCKS_PER_SEC;
			fprintf(stderr,"\n\nTime usage:\n%.0lf ms\n",_timeuse);
		#endif
	}
}_time_printer;
#define B cerr << "BreakPoint" << endl;
#define O(x) cerr << #x << " " << (x) << endl;
#define o(x) cerr << #x << " " << (x) << "  ";
template<typename T0, typename... Ts>
void P(T0 t0, Ts... ts) {
	cerr << t0;
	if constexpr( sizeof...(ts) > 0 ){
		cerr << ' ';
		P(ts...);
	}else
		cerr << endl;
}
#define Msz(x) cerr << "Sizeof " << #x << " " << sizeof(x)/1024/1024 << " MB" << endl;
template<typename T>void Print(T a[], int s, int t, char sp = ' ', char ed = '\n') {
	if( s > t ) return;
	for (int i = s; i < t; i++)
		cout << a[i] << sp;
	cout << a[t] << ed;
}
template<typename T>void Print(T a, int s = 0, int t = -1, char sp = ' ', char ed = '\n') {
	if( t == -1 ) t = a.size()-1;
	for (int i = s; i <= t; i++ )
		cout << a[i] << sp;
	cout << ed;
}
#define chkmax(a,b) (a) = max((a),(b))
#define chkmin(a,b) (a) = min((a),(b))
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3f;
#define Lowbit(a) ((a)&(-(a)))
#define Fastio() {ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);}
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
constexpr int MAXN = 262144;

int n;
int d12, d13, d23;
vector<int> e[MAXN];

int nxt_node = 4;
int get_nxt_node() {
	++nxt_node;
	return nxt_node-1;
}

bool solve() {
	auto gen1 = [&](int a, int b, int c, int d_ab, int d_bc) {
		int last_node = a;
		For(i, d_ab-1) {
			int v = get_nxt_node();
			e[last_node].push_back(v);
			last_node = v;
		}
		e[last_node].push_back(b);
		last_node = b;
		For(i, d_bc-1) {
			int v = get_nxt_node();
			e[last_node].push_back(v);
			last_node = v;
		}
		e[last_node].push_back(c);
		last_node = c;
		while (nxt_node <= n) {
			e[c].push_back(nxt_node);
			++nxt_node;
		}
	};

	int mx = max({d13, d12, d23});
	if (mx > d12+d23+d13 - mx) return false;

	if (d13 == d12 + d23) {
		gen1(1, 2, 3, d12, d23);
		return true;
	}

	if (d12 == d13 + d23) {
		gen1(1, 3, 2, d13, d23);
		return true;
	}

	if (d23 == d13 + d12) {
		gen1(2, 1, 3, d12, d13);
		return true;
	}

	// a + b = d12
	// a + c = d13
	// => b - c = d12 - d13
	// b + c = d23
	// => 2b = d12 - d13 + d23

	if ((d12 - d13 + d23)%2) return false;

	int b = (d12 - d13 + d23) / 2;
	int c = d23-b;
	int a = d12-b;
	
	if (a+b+c+1 > n) return false;
	
	assert (a+b == d12);
	assert (a+c == d13);
	assert (b+c == d23);
	assert (a && b && c);

	int last_node = 1;
	For(i, a) {
		int v = get_nxt_node();
		e[last_node].push_back(v);
		last_node = v;
	}
	int mid = last_node;
	For(i, b-1) {
		int v = get_nxt_node();
		e[last_node].push_back(v);
		last_node = v;
	}
	e[last_node].push_back(2);
	last_node = mid;
	For(i, c-1) {
		int v = get_nxt_node();
		e[last_node].push_back(v);
		last_node = v;
	}
	e[last_node].push_back(3);
	while (nxt_node <= n) {
		e[3].push_back(nxt_node);
		++nxt_node;
	}

	return true;
}

int main() {
	int q; cin >> q;
	For(qi, q) {
		cin >> n >> d12 >> d23 >> d13;
		bool ans = solve();
		if (ans) {
			puts("Yes");
			For(i, n)
				for (int v : e[i])
					printf("%d %d\n", i, v);
		} else {
			puts("No");
		}
		For(i, n) e[i].clear();
		::nxt_node = 4;
	}
}