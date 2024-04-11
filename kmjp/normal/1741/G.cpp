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

int T,N,M;
vector<int> E[101010];
vector<int> H,P;

int D[7][10101];
int from[64],to[64];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		FOR(i,N) E[i].clear();
		H.clear();
		P.clear();
		FOR(i,M) {
			cin>>x>>y;
			E[x-1].push_back(y-1);
			E[y-1].push_back(x-1);
		}
		cin>>x;
		H.resize(x);
		FORR(h,H) {
			cin>>h;
			h--;
		}
		cin>>x;
		P.resize(x);
		FORR(h,P) {
			cin>>h;
			h=H[h-1];
		}
		FORR(h,P) {
			FOR(i,H.size()) if(H[i]==h) {
				H.erase(H.begin()+i);
				break;
			}
		}
		sort(ALL(P));
		P.push_back(0);
		FOR(i,P.size()) {
			FOR(j,N) D[i][j]=1<<20;
			D[i][P[i]]=0;
			queue<int> Q;
			Q.push(P[i]);
			while(Q.size()) {
				int cur=Q.front();
				Q.pop();
				FORR(e,E[cur]) if(D[i][e]==1<<20) {
					D[i][e]=D[i][cur]+1;
					Q.push(e);
				}
			}
		}
		
		FOR(i,64) from[i]=0;
		from[0]=1;
		
		P.pop_back();
		FORR(h,H) {
			ZERO(to);
			int ok[64]={};
			
			int mask;
			ok[0]=1;
			FOR(mask,1<<P.size()) if(ok[mask]) {
				FOR(i,P.size()) if((mask&(1<<i))==0) {
					if(D[i][0]+D[i][h]!=D[P.size()][h]) continue;
					FOR(j,P.size()) if((mask&(1<<j))) {
						if(D[i][0]+D[i][P[j]]+D[j][h]==D[P.size()][h]) continue;
						if(D[j][0]+D[j][P[i]]+D[i][h]==D[P.size()][h]) continue;
						break;
					}
					if(j==P.size()) ok[mask|(1<<i)]=1;
				}
			}
			FOR(mask,1<<P.size()) if(from[mask]) {
				int sm=(1<<P.size())-1-mask;
				for(int mask2=sm;mask2>=0;mask2--) {
					mask2&=sm;
					if(ok[mask2]) to[mask|mask2]=1;
				}
			}
			
			swap(from,to);
		}
		int ma=0;
		int mask;
		FOR(mask,1<<P.size()) if(from[mask]) ma=max(ma,__builtin_popcount(mask));
		cout<<P.size()-ma<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}