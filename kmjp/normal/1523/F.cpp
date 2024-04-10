#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int N,M;
int X[200],Y[200],T[200];
int costm[1<<14][114];
int cost[114][114];


int ma[1<<14][114];
ll tim[1<<14][114];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>X[i]>>Y[i];
	FOR(i,M) cin>>X[i+N]>>Y[i+N]>>T[i+N];
	FOR(x,N+M) FOR(y,N+M) cost[x][y]=abs(X[x]-X[y])+abs(Y[x]-Y[y]);
	int mask;
	FOR(mask,1<<N) {
		FOR(i,N+M) {
			costm[mask][i]=1<<30;
			FOR(x,N) if(mask&(1<<x)) costm[mask][i]=min(costm[mask][i],cost[x][i]);
		}
	}
	
	
	FOR(mask,1<<14) FOR(x,114) tim[mask][x]=1LL<<60;
	FOR(mask,1<<14) FOR(x,114) ma[mask][x]=-1<<30;
	priority_queue<pair<ll,int>> Q;
	FOR(i,N) tim[1<<i][0]=0, Q.push({0LL,(1<<i)*1000+0});
	FOR(i,M) {
		ma[0][i+N]=0;
		Q.push({-T[i+N],1000000000+i+N});
	}
	
	int ret=0;
	while(Q.size()) {
		ll ctim=-Q.top().first;
		int state=Q.top().second;
		Q.pop();
		if(state>=1000000000) {
			state-=1000000000;
			int cur=state%1000;
			
			FOR(mask,1<<N) {
				int num=++ma[mask][cur];
				if(num<=0) continue;
				
				ret=max(ret,num);
				// go space
				FOR(i,N) if((mask&(1<<i))==0) {
					int co=min(cost[cur][i],costm[mask][i]);
					if(tim[mask|(1<<i)][num]>T[cur]+co) {
						tim[mask|(1<<i)][num]=T[cur]+co;
						Q.push({-tim[mask|(1<<i)][num], (mask|(1<<i))*1000+num});
					}
				}
				// go next
				for(i=N;i<N+M;i++) if(T[i]>T[cur]) {
					int co=min(cost[cur][i],costm[mask][i]);
					if(T[i]>=T[cur]+co) ma[mask][i]=max(ma[mask][i],num);
				}
			}
		}
		else {
			mask=state/1000;
			int num=state%1000;
			if(ctim!=tim[mask][num]) continue;
			
			// go space
			FOR(i,N) if((mask&(1<<i))==0) {
				int co=costm[mask][i];
				if(tim[mask|(1<<i)][num]>ctim+co) {
					tim[mask|(1<<i)][num]=ctim+co;
					Q.push({-tim[mask|(1<<i)][num], (mask|(1<<i))*1000+num});
				}
			}
			// go next
			for(i=N;i<N+M;i++) {
				int co=costm[mask][i];
				if(T[i]>=ctim+co) {
					ma[mask][i]=max(ma[mask][i],num);
				}
			}
		}
	}
	
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}