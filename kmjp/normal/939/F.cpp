#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,K;
int L[101],R[101];

vector<pair<int,int>> V[204][204][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	
	V[0][0][0].push_back({0,0});
	
	int pre=0;
	FOR(i,K) {
		
		cin>>L[i]>>R[i];
		int dif=R[i]-L[i];
		FOR(x,203) {
			FORR(v,V[i][x][0]) {
				int T=v.second+(L[i]-pre),D=v.first+(L[i]-pre);
				V[i+1][x][0].push_back({D+dif,T+dif});
				V[i+1][x+1][1].push_back({D-dif,T+dif});
				V[i+1][x+2][0].push_back({D-dif,T+dif});
			}
			FORR(v,V[i][x][1]) {
				int T=v.second-(L[i]-pre),D=v.first-(L[i]-pre);
				V[i+1][x][1].push_back({D-dif,T-dif});
				V[i+1][x+1][0].push_back({D-dif,T+dif});
				V[i+1][x+2][1].push_back({D-dif,T+dif});
			}
		}
		FOR(x,203) {
			FOR(j,2) if(V[i+1][x][j].size()) {
				vector<pair<int,int>> VV;
				sort(ALL(V[i+1][x][j]));
				FORR(r,V[i+1][x][j]) {
					if(VV.empty() || VV.back().second<r.first) {
						VV.push_back(r);
					}
					else {
						VV.back().second = max(VV.back().second,r.second);
					}
				}
				V[i+1][x][j]=VV;
			}
		}
		
		pre=R[i];
	}
	
	FOR(x,203) {
		FORR(v,V[K][x][0]) {
			int T=v.second+(2*N-pre),D=v.first+(2*N-pre);
			if(T>=0 && D<=0) return _P("Full\n%d\n",x);
		}
		FORR(v,V[K][x][1]) {
			int T=v.second-(2*N-pre),D=v.first-(2*N-pre);
			if(T>=0 && D<=0) return _P("Full\n%d\n",x);
		}
		
	}
	_P("Hungry\n");
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}