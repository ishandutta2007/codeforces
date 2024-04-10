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
int N,M;
int A[101][101];
string S;
vector<int> R;
void go(int r,int c) {
	R.push_back(r+1);
	R.push_back(c+1);
	A[r][c]^=1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		FOR(y,N) {
			cin>>S;
			FOR(x,M) A[y][x]=S[x]-'0';
		}
		R.clear();
		
		FOR(y,N-2) {
			FOR(x,M-1) {
				if(A[y][x]&&A[y][x+1]) {
					go(y,x);
					go(y,x+1);
					go(y+1,x+1);
				}
				else if(A[y][x]) {
					go(y,x);
					go(y+1,x);
					go(y+1,x+1);
				}
				else if(A[y][x+1]) {
					go(y,x+1);
					go(y+1,x);
					go(y+1,x+1);
				}
			}
		}
		y=N-2;
		FOR(x,M-2) {
			if(A[y][x]&&A[y+1][x]) {
				go(y,x);
				go(y+1,x);
				go(y,x+1);
			}
			else if(A[y][x]) {
				go(y,x);
				go(y,x+1);
				go(y+1,x+1);
			}
			else if(A[y+1][x]) {
				go(y+1,x);
				go(y,x+1);
				go(y+1,x+1);
			}
		}
		int num=A[N-2][M-2]+A[N-2][M-1]+A[N-1][M-2]+A[N-1][M-1];
		if(num==1) {
			int ty,tx;
			for(y=N-2;y<N;y++) for(x=M-2;x<M;x++) if(A[y][x]==1) ty=y,tx=x;
			for(y=N-2;y<N;y++) for(x=M-2;x<M;x++) {
				if(y==ty&&x==tx) continue;
				int sy,sx;
				for(sy=N-2;sy<N;sy++) for(sx=M-2;sx<M;sx++) if(sy!=y||sx!=x) go(sy,sx);
			}
		}
		else if(num==4) {
			for(y=N-2;y<N;y++) for(x=M-2;x<M;x++) {
				int sy,sx;
				for(sy=N-2;sy<N;sy++) for(sx=M-2;sx<M;sx++) if(sy!=y||sx!=x) go(sy,sx);
			}
		}
		else if(num==3) {
			for(y=N-2;y<N;y++) for(x=M-2;x<M;x++) if(A[y][x]==1) go(y,x);
		}
		else if(num==2) {
			vector<pair<int,int>> P[2];
			for(y=N-2;y<N;y++) for(x=M-2;x<M;x++) P[A[y][x]].push_back({y,x});
			go(P[0][0].first,P[0][0].second);
			go(P[0][1].first,P[0][1].second);
			go(P[1][0].first,P[1][0].second);
			go(P[0][0].first,P[0][0].second);
			go(P[0][1].first,P[0][1].second);
			go(P[1][1].first,P[1][1].second);
		}
		
		
		FOR(y,N) FOR(x,M) assert(A[y][x]==0);
		
		cout<<R.size()/6<<endl;
		FOR(i,R.size()/6) {
			FOR(j,6) cout<<R[i*6+j]<<" ";
			cout<<endl;
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}