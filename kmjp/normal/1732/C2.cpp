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

int T;
int N,Q;
int A[101010];
int nex[101010][31];
ll S[101010],X[101010];
vector<int> C[31];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>Q;
		FOR(j,31) C[j].clear();
		FOR(i,N) {
			cin>>A[i];
			S[i+1]=S[i]+A[i];
			X[i+1]=X[i]^A[i];
			FOR(j,30) if(A[i]&(1<<j)) C[j].push_back(i);
		}
		
		while(Q--) {
			int L,R;
			cin>>L>>R;
			L--,R--;
			
			if((S[R+1]-S[L])==(X[R+1]^X[L])) {
				cout<<L+1<<" "<<L+1<<endl;
				continue;
			}
			
			vector<pair<int,int>> V[30];
			FOR(j,30) {
				x=lower_bound(ALL(C[j]),L)-C[j].begin();
				y=lower_bound(ALL(C[j]),R+1)-C[j].begin();
				if(x==y||x+1==y) {
					continue;
				}
				else if((y-x)%2) {
					V[j].push_back({C[j][x],C[j][y-2]});
					V[j].push_back({C[j][x+1],C[j][y-1]});
				}
				else {
					V[j].push_back({C[j][x],C[j][y-1]});
				}
			}
			int ML=L,MR=R;
			FOR(i,30) {
				FOR(j,V[i].size()) {
					int TL=V[i][j].first,TR=V[i][j].second;
					FOR(x,30) {
						y=0;
						if(V[x].empty()) continue;
						if(V[x][0].first<TL) y++;
						if(y&&V[x].size()==1) TR=2000000;
						else if(V[x][y].first<TL) TR=20000000;
						else TR=max(TR,V[x][y].second);
					}
					if(TR-TL<MR-ML) MR=TR,ML=TL;
				}
			}
			cout<<ML+1<<" "<<MR+1<<endl;
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}