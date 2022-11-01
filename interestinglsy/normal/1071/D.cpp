#include <algorithm>
#include <iostream>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <climits>
#include <vector>
#include <cstdio>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define F first
#define S second
#define vc vector
#define INF (0x3f3f3f3f)
#define LINF ((long long)(0x3f3f3f3f3f3f3f3f))
#define Pb push_back
#define Mp make_pair
#define ll long long
#define _tp template
#define _tyn typename
#define Pf push_front
#define ull unsigned ll
#define pii pair<int,int>
#define ld double
#define Sqr(x) ((x)*(x))
#define All(x) x.begin(),x.end()
#define B cout << "BreakPoint" << endl;
#define Fin(a) freopen(a,"r",stdin)
#define Fout(a) freopen(a,"w",stdout)
#define Ms(_data) memset(_data,0,sizeof(_data))
#define Msn(_data,_num) memset(_data,_num,sizeof(_data))
#define O_(x) cout << #x << " " << x << "  ";
#define O(x) cout << #x << " " << x << endl;
using namespace std;
#define Mymax(a,b) a = max(a,b)
#define Mymin(a,b) a = min(a,b)
_tp<_tyn T>void Print( T _a[] , int _s , int _t ){
    for( int i = _s ; i <= _t ; i++ )
        cout << _a[i] << " ";
    cout << endl;
}
#define il inline
#define rg register
struct InputReader{
    static const int bs = 100000;
    char buf[bs];
    int p;
    il InputReader():p(bs) {}
    il void Flush(){
        p = 0;
        fread(buf, 1, bs, stdin);
    }
    il char C(){
        if(p >= bs) Flush();
        return buf[p++];
    }
    int Getnum(){
        char ch = C();
        while( ch < '0'  ||  ch > '9' ) ch = C();
        return (int)(ch-'0');
    }
    il int operator() (){
        int ans = 0;
        char ch = C();
        int fu = 1;
        while( ch < '0'  ||  ch > '9' ){
            if( ch == '-' ) fu = -1;
            ch = C();
        }
        while( ch >= '0'  &&  ch <= '9' ){
            ans *= 10;
            ans += ch-'0';
            ch = C();
        }
        return ans * fu;
    }
    ll Readll(){
        ll ans = 0LL;
        ll fu = 1LL;
        char ch = C();
        while( ch < '0'  ||  ch > '9' ){
            if( ch == '-' ) fu = -1LL;
            ch = C();
        }
        while( ch >= '0'  &&  ch <= '9' ){
            ans *= 10LL;
            ans += (ll)ch-'0';
            ch = C();
        }
        return ans * fu;
    }
    il void Readstring( string &x ){
        x.clear();
        char ch = C();
        while( !isdigit(ch)  &&  !isalpha(ch)  &&  ch != '('  &&  ch != ')'  &&  ch != '^' ) ch = C();
        while( isdigit(ch)  ||  isalpha(ch)  ||  ch == '('  ||  ch == ')'  ||  ch == '^' ){
            x += ch;
            ch = C();
        }
    }
    il void Readalpha( char &c ){
        c = C();
        while( !isalpha(c) ) c = C();
    }
    il void Specialread( char &c ){
        c = C();
        while( c != '.'  &&  c != 'W'  &&  c != 'A'  &&  c != 'B' ) c = C();
    }
}In;
il void Read( int &x ){ x = In(); }
il void Read( int &x, int &y ){ x = In(); y = In(); }
il void Read( int &x1 , int &x2 , int &x3 ){
    x1 = In(); x2 = In(); x3 = In();
}
il void Read( int &x1 , int &x2 , int &x3 , int &x4 ){
    x1 = In(); x2 = In(); x3 = In(); x4 = In();
}
il void Read( ll &x ){ x = In.Readll(); }
il void Read( ll &x, ll &y ){ x = In.Readll(); y = In.Readll(); }
il void Read( ll &x1 , ll &x2 , ll &x3 ){
    x1 = In.Readll(); x2 = In.Readll(); x3 = In.Readll();
}
il void Read( ll &x1 , ll &x2 , ll &x3 , ll &x4 ){
    x1 = In.Readll(); x2 = In.Readll(); x3 = In.Readll(); x4 = In.Readll();
}
#ifdef InterestingLSY
clock_t _starttime , _endtime;

#endif
il void FILEIO(){
    #ifdef InterestingLSY
        _starttime = clock();
        Fin("in.in");
    #endif
}
void Printtime(){
	#ifdef InterestingLSY
        _endtime = clock();
        double _timeuse = (_endtime-_starttime)* 1000.0 / CLOCKS_PER_SEC;
        printf("\n\nTime usage:\n%.0lf ms\n",_timeuse);
    #endif
}
void END(){
	Printtime();
    exit(0);
}
_tp<_tyn T>void END( T mes ){
	cout << mes << endl;
	END();
}
#define For(i,j) for( rg int (i) = 1 ; (i) <= (j) ; (i)++ )
#define For0(i,j) for( rg int (i) = 0 ; (i) < (j) ; (i)++ )
#define Forx(i,j,k) for( rg int (i) = (j) ; (i) <= (k) ; (i)++ )
#define Forstep(i,j,k,st) for( rg int (i) = (j) ; (i) <= (k) ; (i) += (st) )
#define fOR(i,j) for( rg int (i) = (j) ; (i) >= 1 ; (i)-- )
#define fOR0(i,j) for( rg int (i) = (j)-1 ; (i) >= 0 ; (i)-- )
#define fORx(i,j,k) for( rg int (i) = (k) ; (i) >= (j) ; (i)-- )
int dx4[] = {0,-1,0,1};
int dy4[] = {1,0,-1,0};
int dx8[] = {0,1,1,1,0,-1,-1,-1};
int dy8[] = {1,-1,0,1,-1,-1,0,1};
//          D L U  R
#define Mymod(a,b) if( a >= b ) a -= b;
#define Rmod(a,b) a = (a%b+b)%b
#define Dis2(x1,y1,x2,y2) (Sqr((x1)-(x2))+Sqr((y1)-(y2)))
#define Dis(x1,y1,x2,y2) (sqrt(Dis2(x1,y1,x2,y2)))
#define ERR(x) cout << "ERR! #" << x << endl
#define Msz(x) cout << "Sizeof " << #x << " " << sizeof(x)/1024/1024 << " MB" << endl;
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
#define MAXN 1010
#define Foreach(i) for( auto i = id.begin() ; i != id.end() ; i++ )
const int prime[12] = {2,3,5,7,11,13,17,19,23,29};
il bool Cmp( int a , int b ){ return a>b; }
struct Data{
	int c[12];
	bool operator<( const Data &v )const{
		For0(i,12)
			if( c[i] != v.c[i] )
				return c[i] < v.c[i];
		return 0;
	}
};
int t[12];
Data Makedata(){
	Data ret;
	memcpy(ret.c,t,sizeof t);
	return ret;
}

int dcnt[MAXN];		// 
map<Data,int> id;	// id()
int nowid = 1;

void Dfs( int pos , int remind , int cnt , int last ){
	id[Makedata()] = nowid;
	dcnt[nowid] = cnt;
	nowid++;
	if( pos == 10 ) return;
	for( int i = 1 ; i <= last && remind >= prime[pos] ; i++ ){
		remind /= prime[pos];
		t[pos] = i;
		Dfs(pos+1,remind,cnt*(i+1),i);
	}
	t[pos] = 0;
}

int dis[MAXN][MAXN][2];

int T;
Data Chai( int x ){
	Ms(t);
	int top = 0;
	for( int i = 2 ; i*i <= x ; i++ ){
		if( x%i != 0 ) continue;
		while( x%i == 0 ){
			t[top]++;
			x /= i;
		}
		top++;
	}
	if( x > 1 ) t[top++] = 1;
	sort(t,t+10,Cmp);
	return Makedata();
}

int main(){
	FILEIO();

	Dfs(0,1e8,1,233);//O(nowid);

	Msn(dis,INF);
	Foreach(i){
		For0(j,10){
			memcpy(t,i->F.c,sizeof t);
			//assert(id.count(Makedata()));
			t[j]++;
			sort(t,t+10,Cmp);
			//Print(t,0,9);
			if(id.count(Makedata())){
				dis[i->S][id[Makedata()]][0] = 1;
			}

			memcpy(t,i->F.c,sizeof t);
			if(!t[j]) continue;
			t[j]--;
			sort(t,t+10,Cmp);
			if(id.count(Makedata()))
				dis[i->S][id[Makedata()]][0] = 1;
		}
	}

	Foreach(i)
		Foreach(j)
			if( dcnt[i->S] == dcnt[j->S] )
				dis[i->S][j->S][i->S!=j->S] = 0;
	For(k,nowid)
		For(i,nowid)
			For(j,nowid){
				Mymin(dis[i][j][0],dis[i][k][0]+dis[k][j][0]);
				Mymin(dis[i][j][1],dis[i][k][0]+dis[k][j][0]);
				Mymin(dis[i][j][1],dis[i][k][0]+dis[k][j][1]);
				Mymin(dis[i][j][1],dis[i][k][1]+dis[k][j][0]);
			}

	Read(T);
	For(___,T){
		int a,b;
		Read(a,b);
		Data da = Chai(a);
		Data db = Chai(b);
		int ans = dis[id[da]][id[db]][1];
		printf("%d\n",ans);
	}

	END();
}