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
int n,k;
int A,B;

lint pat[2][55][55];
int cost[2][55][55];

const lint mod=1000000007;
lint C[55][55];

inline void chadd(lint& a,lint b){
	a+=b;
	a%=mod;
}

int main(){
	REP(i,55){
		C[i][0]=1;
		REP(j,i) C[i][j+1]=(C[i-1][j+1]+C[i-1][j])%mod;
	}

	scanf("%d%d",&n,&k);
	REP(i,n){
		int a;scanf("%d",&a);
		if(a==50) ++A;
		else ++B;
	}

	memset(cost,-1,sizeof(cost));
	queue<pair<int,pi> >q;
	q.push(mp(0,mp(A,B)));
	cost[0][A][B]=0;
	pat[0][A][B]=1;
	while(!q.empty()){
		int side=q.front().fr;
		pi cur=q.front().sc;q.pop();

		if(side==0){
			REP(i,cur.fr+1) REP(j,cur.sc+1){
				if(i*50+j*100>k) break;
				if(i==0 && j==0) continue;
				
				int na=cur.fr-i,nb=cur.sc-j;
				lint npat=pat[side][cur.fr][cur.sc]*
					C[cur.fr][i]%mod*C[cur.sc][j]%mod;
				
				if(cost[1][na][nb]==-1){
					cost[1][na][nb]=cost[side][cur.fr][cur.sc]+1;
					pat[1][na][nb]=npat;
					q.push(mp(1,mp(na,nb)));
				}else if(cost[1][na][nb]==cost[side][cur.fr][cur.sc]+1){
					chadd(pat[1][na][nb],npat);
				}

			}
		}else{
			REP(i,A-cur.fr+1) REP(j,B-cur.sc+1){
				if(i*50+j*100>k) break;
				if(i==0 && j==0) continue;

				int na=cur.fr+i,nb=cur.sc+j;
				lint npat=pat[side][cur.fr][cur.sc]*C[A-cur.fr][i]%mod*
					C[B-cur.sc][j]%mod;
				if(cost[0][na][nb]==-1){
					cost[0][na][nb]=cost[side][cur.fr][cur.sc]+1;
					pat[0][na][nb]=npat;
					q.push(mp(0,mp(na,nb)));
				}else if(cost[0][na][nb]==cost[side][cur.fr][cur.sc]+1){
					chadd(pat[0][na][nb],npat);
				}
			}
		}
	}

	if(cost[1][0][0]==-1){
		printf("-1\n0\n");
	}else printf("%d\n%d\n",cost[1][0][0],(int)pat[1][0][0]);

	return 0;
}