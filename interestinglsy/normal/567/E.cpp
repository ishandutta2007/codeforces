#include <bits/stdc++.h>
#define F first
#define S second
#define dq deque
#define vc vector
#define INF (0x3f3f3f3f)
#define LINF ((long long)(0x3f3f3f3f3f3f3f3f))
#define Pb push_back
#define Mp make_pair
#define ll unsigned long long
#define _tp template
#define _tyn typename
#define Pf push_front
#define itor iterator
#define sint short int
#define pii pair<int,int>
#define All(x) x.begin(),x.end()
#define B cout << "BreakPoint" << endl;
#define Fin(a) freopen(a,"r",stdin)
#define Fout(a) freopen(a,"w",stdout)
#define Ms(_data) memset(_data,0,sizeof(_data))
#define Msn(_data,_num) memset(_data,_num,sizeof(_data))
#define Fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define O_(x) cout << #x << " " << x << "  ";
#define O(x) cout << #x << " " << x << endl;
using namespace std;
#define Mymax(a,b) if(a<b) a = b;
#define Mymin(a,b) if(a>b) a = b;
void Print(int _x){printf("%d\n",_x);}
void Print(ll _x){printf("%I64d\n",_x);}
_tp<_tyn T>void Print( T _a[] , int _s , int _t ){
	for( int i = _s ; i <= _t ; i++ )
		cout << _a[i] << " ";
   	cout << endl;
}
#define il inline
#define rg register
#ifdef InterestingLSY
	#include <windows.h>
	#include <psapi.h>
#endif
clock_t _starttime , _endtime;
il void FILEIO(){
	Fin("road.in");
	#ifdef InterestingLSY
		_starttime = clock();
	#else
		Fout("road.out");
	#endif
}
il void END(){
	#ifdef InterestingLSY
		_endtime = clock();
		double _timeuse = (_endtime-_starttime)* 1000.0 / CLOCKS_PER_SEC;
		printf("\n\nTime usage:\n%.0lf ms\n",_timeuse);
		HANDLE _handle = GetCurrentProcess();
		PROCESS_MEMORY_COUNTERS pmc;
		GetProcessMemoryInfo(_handle,&pmc,sizeof(pmc));
		double _memuse = pmc.PeakPagefileUsage/1024.00/1024.00;
		printf("Memory usage:\n%.1lf MB\n\n",_memuse);
	#endif
	exit(0);
}
#define For(i,j) for( rg int (i) = 1 ; (i) <= (j) ; (i)++ )
#define For0(i,j) for( rg int (i) = 0 ; (i) < (j) ; (i)++ )
#define Forx(i,j,k) for( rg int (i) = (j) ; (i) <= (k) ; (i)++ )
#define Forstep(i,j,k,st) for( rg int (i) = (j) ; (i) <= (k) ; (i) += (st) )
#define fOR(i,j) for( rg int (i) = (j) ; (i) >= 1 ; (i)-- )
#define fOR0(i,j) for( rg int (i) = (j)-1 ; (i) >= 0 ; (i)-- )
#define fORx(i,j,k) for( rg int (i) = (k) ; (i) >= (j) ; (i)-- )
#define Mymod(a,b) if( a >= b ) a -= b;
#define Rmod(a,b) a = (a%b+b)%b
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
#define MAXN 200010
#define MAXM 400020
#define pli pair<ll,int>
// LONGLONG IS NEEDED
struct Edge{
	int t,id;
	ll c;
	Edge(){}
	Edge( int ti , ll ci , int ii ){
		t = ti;
		c = ci;
		id = ii;
	}
};
struct E{
	int f,t;
	ll c;
};
int n,m,s,t;
vc<Edge> e[2][MAXN];
vc<Edge> ne[2][MAXN];
E edges[MAXM];

ll shortest;
ll dis[2][MAXN];
priority_queue< pli , vc<pli> , greater<pli> > pq;
bool vis[MAXN];
il void Dijkstra( int st , int lay ){
    Msn(dis[lay],INF);
    Ms(vis);
    dis[lay][st] = 0;
    pq.push(Mp(0,st));
    while(!pq.empty()){
        pli nu = pq.top();
        pq.pop();
        int u = nu.S;
        if(vis[u]) continue;
        vis[u] = 1;
        For0(i,e[lay][u].size()){
            Edge now = e[lay][u][i];
            int v = now.t;
            if( dis[lay][v] > dis[lay][u] + now.c ){
                dis[lay][v] = dis[lay][u] + now.c;
                pq.push(Mp(dis[lay][v],v));
            }
        }
    }
}

ll mem[2][MAXN];
ll pcnt[MAXN],tot;
#define NOW mem[lay][pos]
#define KNOW NOW != -1
ll MOD;
ll Dfs( int lay , int pos ){		// s/t~pos  
	if(KNOW) return NOW;
	if( pos == (lay?t:s) ) return NOW = 1;
	ll ret = 0;
	For0(i,ne[lay][pos].size()){
		int v = ne[lay][pos][i].t;
		ret += Dfs(lay,v);
		ret %= MOD;
	}
	return NOW = ret;
}

ll ansl[MAXM];

int main(){
	//FILEIO();//Fout("road.out");
////////	Fin("road.in");
/////	Fout("lsy.out");
	srand(time(0));
	MOD = ((ll)rand()*(ll)rand()*(ll)rand()+(ll)rand()*100LL+(ll)rand()*10000LL+19260817LL) % 100000000LL;
	
	
	scanf("%d%d%d%d",&n,&m,&s,&t);
	For(i,m){
		int x,y;
		ll z;
		scanf("%d%d%I64d",&x,&y,&z);
		e[0][x].Pb(Edge(y,z,i));
		e[1][y].Pb(Edge(x,z,i));
		edges[i].f = x;
		edges[i].t = y;
		edges[i].c = z;
	}
	
	Dijkstra(s,0);
	Dijkstra(t,1);
	shortest = dis[0][t];
	//assert(shortest==dis[1][s]);
	
	For(i,m){
		E u = edges[i];
		if( dis[0][u.f] + dis[1][u.t] + u.c != shortest ) continue;
		ne[1][u.f].Pb(Edge(u.t,u.c,i));
		ne[0][u.t].Pb(Edge(u.f,u.c,i));
	}
	
	Msn(mem,-1);
	Dfs(1,s);
	Dfs(0,t);	// 0:s  1:t 
	//Print(mem[0],1,n);
	//Print(mem[1],1,n);
//	Print(pcnt,1,n);
	For(i,n)
		pcnt[i] = mem[0][i]*mem[1][i]%MOD;
	tot = pcnt[t];
	
	For(i,m){
		E u = edges[i];
		ll newc;
		if( dis[0][u.f] + dis[1][u.t] + u.c != shortest ){
			if( dis[0][u.f] + dis[1][u.t] + 1LL < shortest ){
				newc = shortest - dis[0][u.f] - dis[1][u.t] - 1LL;
				printf("CAN %I64d\n",u.c-newc);
			}else{
				printf("NO\n");
			}
			
		}else{
			if( min(pcnt[u.f],pcnt[u.t])%MOD != tot  ||  mem[0][u.f]*mem[1][u.t]%MOD != tot  ||  ne[1][u.f].size() > 1  ||  ne[0][u.t].size() > 1  ||  mem[1][u.f] > mem[1][u.t]  ||  mem[0][u.t] > mem[0][u.f] ){
				if( dis[0][u.f] + dis[1][u.t] + 1LL < shortest ){
					newc = shortest - dis[0][u.f] - dis[1][u.t] - 1LL;
					printf("CAN %I64d\n",u.c-newc);
				}else{
					printf("NO\n");
				}
			}else{
				printf("YES\n");
			}
		}
	}
	
	END();
}