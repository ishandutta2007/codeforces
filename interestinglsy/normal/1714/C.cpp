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
int main() {
	int t; cin >> t;
	For(ti, t) {
		int s; cin >> s;
		int ans = INF;
		for (int mask = 0; mask < (1<<9); ++mask) {
			int t_sum = 0;
			int t_val = 0;
			For(i, 9) {
				if (mask>>(i-1)&1) {
					t_sum += i;
					t_val = t_val*10 + i;
				}
			}
			if (t_sum == s) {
				chkmin(ans, t_val);
			}
		}
		cout << ans << endl;
	}
}