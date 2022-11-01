#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
#define REPN(i,m,in) for(int i=in;i<m;++i)
#define ALL(t) (t).begin(),(t).end()
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
using namespace std;
static const int INF =500000000; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;
int n;
pi cell[100005];
int m;
int x0,y0,x1,y1;
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
vector<int> g[100005];
int cost[100005];

int main(){
	cin>>x0>>y0>>x1>>y1;
	--x0;--y0;--x1;--y1;
	cell[m++]=mp(x0,y0);cell[m++]=mp(x1,y1);
	cin>>n;
	REP(i,n){
		int r,a,b;cin>>r>>a>>b;--r;--a;
		REPN(j,b,a) cell[m++]=mp(r,j);
	}
	sort(cell,cell+m);
	REP(i,m){
		REPN(x,2,-1) REPN(y,2,-1){
			int px=cell[i].sc+x,py=cell[i].fr+y;
			if(binary_search(cell,cell+m,mp(py,px))){
				int p=lower_bound(cell,cell+m,mp(py,px))-cell;
				g[i].pb(p);
			}
		}
	}
	int A=lower_bound(cell,cell+m,mp(x0,y0))-cell,B=lower_bound(cell,cell+m,mp(x1,y1))-cell;
	memset(cost,-1,sizeof(cost));
	queue<int>q;
	q.push(A);cost[A]=0;
	while(!q.empty()){
		int cur=q.front();q.pop();
		REP(i,g[cur].size()){
			int to=g[cur][i];
			if(cost[to]==-1){
				cost[to]=cost[cur]+1;
				q.push(to);
			}
		}
	}
	printf("%d\n",cost[B]);

	return 0;
}